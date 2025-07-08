#include "command_handler.h"
#include <sstream>
#include <iostream>
#include <vector>
#include <cstring>
#include "db_pool.h"

// 分割字符串为命令参数（类似 kvs_split_token）
static std::vector<std::string> splitCommand(const std::string& command) {
    std::istringstream iss(command);
    std::vector<std::string> tokens;
    std::string token;
    while (iss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

int handleCommand(const std::string& command, std::string& response) {
    auto tokens = splitCommand(command);
    if (tokens.empty()) {
        response = "ERROR: 无效命令";
        return -1;
    }


    KVStore& kv = KVStore::getInstance();  // 获取单例 KVStore
    const std::string& cmd = tokens[0];

    if (cmd == "set") {
        if (tokens.size() < 3) {
            response = "ERROR: 格式错误(set <key> <value> [ttl_seconds])";
            return -1;
        }
        cout << "key: " << tokens[1] << " value: " << tokens[2] << endl;
        std::string key = tokens[1];
        std::string value = tokens[2];
        std::chrono::seconds ttl = std::chrono::seconds(0);  // 默认无过期时间
        if (tokens.size() >= 4) {  // 支持可选的 ttl 参数（秒）
            try {
                ttl = std::chrono::seconds(std::stoi(tokens[3]));
            } catch (...) {
                response = "ERROR: ttl 必须为整数（秒）";
                return -1;
            }
        }
        // 调用带结果反馈的 set 方法
        SetResult res = kv.set(key, value, ttl);
        cout << "set res: " << res.overwritten << " " << res.evicted << endl;
        // 构造包含操作结果的响应
        response = "OK";
        if (res.overwritten) response += " (覆盖旧键)";
        if (res.evicted) response += " (淘汰旧键)";
        if (!res.overwritten) {
            // 存储映射关系到 MySQL
            CDBManager *db_manager = CDBManager::getInstance();
            CDBConn *db_conn = db_manager->GetDBConn("tuchuang_master");
            AUTO_REL_DBCONN(db_manager, db_conn);
            std::string str_sql = FormatString("insert into student (name, number) values ('%s', '%s')", 
            key.c_str(), value.c_str());
            cout << "执行：" << str_sql;
            if (!db_conn->ExecuteCreate(str_sql.c_str())) {
            cout << str_sql << " 操作失败";
            } 
        }
    } else if (cmd == "get") {
        if (tokens.size() < 2) {
            response = "ERROR: 格式错误(get <key>)";
            return -1;
        }
        std::string key = tokens[1];
        // 调用带结果反馈的 get 方法
        GetResult res = kv.get(key);
        if (!res.exists) {
            CDBManager *db_manager = CDBManager::getInstance();
            CDBConn *db_conn = db_manager->GetDBConn("tuchuang_master");
            AUTO_REL_DBCONN(db_manager, db_conn);
            std::string str_sql = FormatString("select number from student where name = '%s'", key.c_str());
            CResultSet * result_set = db_conn->ExecuteQuery(str_sql.c_str());
            if (result_set->Next()) {  // 确保有数据行
        // 添加字段存在性检查
                response = result_set->GetString("number");
                    // 将结果缓存到本地
                KVStore::getInstance().set(key, response, std::chrono::minutes(60));
            }
            else {
                response = "NOT_FOUND";
            }
        } else if (res.expired) {
            response = "EXPIRED";
        } else {
            response = res.value;  // 返回实际值
        }
    } else if (cmd == "del") {
        if (tokens.size() < 2) {
            response = "ERROR: 格式错误(del <key>)";
            return -1;
        }
        std::string key = tokens[1];
        // 调用带返回值的 del 方法
        bool success = kv.del(key);
        response = success ? "OK" : "NOT_FOUND";
        if (success) {
            CDBManager *db_manager = CDBManager::getInstance();
            CDBConn *db_conn = db_manager->GetDBConn("tuchuang_master");
            AUTO_REL_DBCONN(db_manager, db_conn);
            std::string str_sql = FormatString("delete from student where name = '%s'", key.c_str());
            CResultSet * result_set = db_conn->ExecuteQuery(str_sql.c_str());
        }
    } else {
        response = "ERROR: 未知命令(支持 set/get/del)";
        return -1;
    }

    return response.size();  // 返回响应长度
}

int commandHandler(char* msg, int length, char* response) {
    std::string command(msg, length);  // 将原始字符数组转为字符串
    std::string resp;
    std::cout << "command: " << command << std::endl;
    int ret = handleCommand(command, resp);  // 调用命令处理函数
    std::cout << "resp: " << resp << std::endl;
    if (ret > 0) {
        strncpy(response, resp.c_str(), resp.size());  // 将响应复制到发送缓冲区
        return resp.size();
    }
    return ret;
}