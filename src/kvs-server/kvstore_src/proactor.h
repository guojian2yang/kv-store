// 修改后的头文件需要与实现中的类定义对齐
#ifndef PROACTOR_H
#define PROACTOR_H

#include <liburing.h>
#include <netinet/in.h>
#include <functional>
#include <memory>
#include <vector>
#include "muduo/base/Logging.h"

// 前置声明需要与实现中的ConnInfo结构一致
struct ConnInfo {
    int fd;
    int event;
    char buffer[1024];
    char response[1024];
};

class ProactorServer {
public:
    using MsgHandler = std::function<int(char*, int, char*)>;
    
    ProactorServer(unsigned short port, MsgHandler handler);
    ~ProactorServer();
    void run();

private:
    // 以下私有方法需要与实现文件中的实际方法签名匹配
    void initServer();
    void submitAcceptEvent();
    void processCompletion(struct io_uring_cqe* cqe);
    
    // 新增类型定义
    using ConnPtr = std::shared_ptr<ConnInfo>;
    
    // 成员变量需要与实现中的实际使用一致
    unsigned short port_;
    int listenFd_;
    struct io_uring ring_;
    MsgHandler msgHandler_;
};

#endif