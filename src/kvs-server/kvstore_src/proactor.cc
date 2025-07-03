#include <liburing.h>
#include <netinet/in.h>
#include <functional>
#include <vector>
#include <memory>
#include "muduo/base/Logging.h"
#include "command_handler.h"

#define EVENT_ACCEPT    0
#define EVENT_READ      1
#define EVENT_WRITE     2

class ProactorServer {
public:
    using MsgHandler = std::function<int(char*, int, char*)>;
    
    ProactorServer(unsigned short port, MsgHandler handler) 
        : port_(port), msgHandler_(handler), listenFd_(-1) {
        struct io_uring_params params;
        memset(&params, 0, sizeof(params));
        if (io_uring_queue_init_params(1024, &ring_, &params) < 0) {
            LOG_SYSERR << "io_uring_queue_init failed";
            throw std::runtime_error("io_uring initialization failed");
        }
        initServer();
        LOG_INFO << "Proactor server initialized on port " << port_;
    }

    ~ProactorServer() {
        if (listenFd_ >= 0) close(listenFd_);
        io_uring_queue_exit(&ring_);
        LOG_INFO << "Proactor server shutdown";
    }

    void run() {
        submitAcceptEvent();
        eventLoop();
    }

private:
    struct ConnInfo {
        int fd;
        int event;
        char buffer[1024];
        char response[1024];
    };
    using ConnPtr = std::shared_ptr<ConnInfo>;

    void initServer();
    void submitAcceptEvent();
    void eventLoop();
    void processCompletion(io_uring_cqe* cqe);
    void handleAccept(std::shared_ptr<ConnInfo> conn, int res);
    void handleRead(std::shared_ptr<ConnInfo> conn, int res);
    void handleWrite(std::shared_ptr<ConnInfo> conn, int res);
    void submitReadEvent(std::shared_ptr<ConnInfo> conn);
    void submitWriteEvent(std::shared_ptr<ConnInfo> conn, int length);

    unsigned short port_;
    int listenFd_;
    struct io_uring ring_;
    MsgHandler msgHandler_;
};

// 类成员函数实现
void ProactorServer::initServer() {
    listenFd_ = socket(AF_INET, SOCK_STREAM, 0);
    
    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(port_);

    if (bind(listenFd_, (sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        LOG_SYSERR << "Bind failed on port " << port_;
        throw std::runtime_error("Port binding failed");
    }
    listen(listenFd_, 10);
}

void ProactorServer::submitAcceptEvent() {
    auto* sqe = io_uring_get_sqe(&ring_);
    auto conn = std::make_shared<ConnInfo>();
    conn->fd = listenFd_;
    conn->event = EVENT_ACCEPT;
    io_uring_prep_accept(sqe, listenFd_, nullptr, nullptr, 0);
    io_uring_sqe_set_data(sqe, new ConnPtr(conn));
    io_uring_submit(&ring_);
}

void ProactorServer::eventLoop() {
    while (true) {
        io_uring_submit(&ring_);
        io_uring_cqe* cqe;
        unsigned head, count = 0;
        
        io_uring_for_each_cqe(&ring_, head, cqe) {
            ++count;
            processCompletion(cqe);
        }
        io_uring_cq_advance(&ring_, count);
    }
}

void ProactorServer::processCompletion(io_uring_cqe* cqe) {
    auto ptr = static_cast<ConnPtr*>(io_uring_cqe_get_data(cqe));
    auto conn = *ptr;
    delete ptr;

    switch (conn->event) {
        case EVENT_ACCEPT: handleAccept(conn, cqe->res); break;
        case EVENT_READ:   handleRead(conn, cqe->res);   break;
        case EVENT_WRITE:  handleWrite(conn, cqe->res);  break;
    }
}

void ProactorServer::handleAccept(std::shared_ptr<ConnInfo> conn, int res) {
    if (res < 0) {
        LOG_ERROR << "Accept failed: " << strerror(-res);
        return;
    }
    
    auto clientConn = std::make_shared<ConnInfo>();
    clientConn->fd = res;
    clientConn->event = EVENT_READ;
    submitReadEvent(clientConn);
    submitAcceptEvent();
}

void ProactorServer::submitReadEvent(std::shared_ptr<ConnInfo> conn) {
    auto* sqe = io_uring_get_sqe(&ring_);
    io_uring_prep_recv(sqe, conn->fd, conn->buffer, sizeof(conn->buffer), 0);
    io_uring_sqe_set_data(sqe, new ConnPtr(conn));
    io_uring_submit(&ring_);
}

void ProactorServer::handleRead(std::shared_ptr<ConnInfo> conn, int res) {
    if (res <= 0) {
        close(conn->fd);
        return;
    }

    conn->event = EVENT_WRITE;
    memset(conn->response, 0, sizeof(conn->response));
    int respLen = msgHandler_(conn->buffer, res, conn->response);
    submitWriteEvent(conn, respLen);
}

void ProactorServer::submitWriteEvent(std::shared_ptr<ConnInfo> conn, int length) {
    auto* sqe = io_uring_get_sqe(&ring_);
    io_uring_prep_send(sqe, conn->fd, conn->response, length, 0);
    io_uring_sqe_set_data(sqe, new ConnPtr(conn));
    io_uring_submit(&ring_);
}

void ProactorServer::handleWrite(std::shared_ptr<ConnInfo> conn, int res) {
    if (res < 0) {
        close(conn->fd);
        return;
    }
    conn->event = EVENT_READ;
    memset(conn->buffer, 0, sizeof(conn->buffer));
    submitReadEvent(conn);
}

void runProactorServer() {
    try {
        ProactorServer server(2000, commandHandler);
        server.run();
    } catch (const std::exception& e) {
        LOG_ERROR << "Proactor server failed: " << e.what();
    }
}