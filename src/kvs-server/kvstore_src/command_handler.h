#ifndef COMMAND_HANDLER_H
#define COMMAND_HANDLER_H

#include <string>
#include "kvstore.h"  // 依赖 KVStore 类

// 处理客户端命令并生成响应
// 参数：原始命令字符串，输出响应字符串
// 返回：响应长度（成功）或 -1（失败）
int handleCommand(const std::string& command, std::string& response);
int commandHandler(char* msg, int length, char* response);

template <typename... Args>
std::string FormatString(const std::string &format, Args... args) {
    auto size = std::snprintf(nullptr, 0, format.c_str(), args...) +
                1; // Extra space for '\0'
    std::unique_ptr<char[]> buf(new char[size]);
    std::snprintf(buf.get(), size, format.c_str(), args...);
    return std::string(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside
}

#endif