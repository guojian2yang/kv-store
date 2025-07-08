#include <iostream>
#include <signal.h>
#include <thread>

#include "muduo/net/TcpServer.h"
#include  "muduo/net/TcpConnection.h"
#include "muduo/base/ThreadPool.h"
#include "muduo/net/EventLoop.h"
#include "muduo/base/Logging.h"
#include "config_file_reader.h"
#include "db_pool.h"
#include "kvstore.h"
#include "server.h"

using namespace muduo;
using namespace muduo::net;
using namespace std;

#define reactor 1
#define proactor 0

// 定时持久化任务
void startPeriodicPersistence(std::chrono::seconds interval, const std::string& filename) {
    std::thread([interval, filename]() {
        while (true) {
            std::this_thread::sleep_for(interval);
            KVStore::getInstance().persistToFile(filename);
        }
    }).detach();
}

int main(int argc, char *argv[])
{

    std::cout  << argv[0] << "[conf ] "<< std::endl;
     
    signal(SIGPIPE, SIG_IGN); //忽略SIGPIPE信号
    int ret = 0;
    char *str_kvstore_conf = NULL;
    if(argc > 1) {
        str_kvstore_conf = argv[1];  // 指向配置文件路径
    } else {
        str_kvstore_conf = (char *)"kvstore.conf";
    }
     std::cout << "conf file path: " <<  str_kvstore_conf << std::endl;

    CConfigFileReader config_file(str_kvstore_conf);     //读取配置文件

    //日志设置级别
    char *str_log_level =  config_file.GetConfigName("log_level");  
    Logger::LogLevel log_level = static_cast<Logger::LogLevel>(atoi(str_log_level));
    Logger::setLogLevel(log_level);

    //设置MySQL连接池
    CDBManager::SetConfPath(str_kvstore_conf);   //设置配置文件路径
    CDBManager *db_manager = CDBManager::getInstance();
    if (!db_manager) {
        LOG_ERROR <<"DBManager init failed";
        return -1;
    }

    // 设置 KV 存储的最大容量
    KVStore::getInstance().setMaxCapacity(200);
    // 启动定时清理过期 key 的任务
    KVStore::getInstance().startExpirationCleaner(std::chrono::minutes(1));
    // 从文件加载持久化数据
    // std::thread([](){
    //     LOG_INFO << "Starting async data loading...";
    //     KVStore::getInstance().loadFromFile("kv_store_data.txt");
    //     LOG_INFO << "Data loading completed";
    // }).detach();
    // 启动定时持久化任务
    startPeriodicPersistence(std::chrono::seconds(60), "kv_store_data.txt");

    std::cout << "run server" << std::endl;

    #if reactor
    runReactorServer();
    #elif proactor
    runProactorServer();
    #endif
}