#include <errno.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <sys/time.h>
#include <functional>
#include <vector>
#include <iostream>
#include "command_handler.h" 

// 假设的 conn 结构体定义
struct Conn {
    int fd;
    char rbuffer[1024];
    int rlength;
    char wbuffer[1024];
    int wlength;
    struct {
        std::function<int(int)> recv_callback;
    } r_action;
    std::function<int(int)> send_callback;
};

#define CONNECTION_SIZE 1024
#define MAX_PORTS 1
#define BUFFER_LENGTH 1024

// 计算时间差的函数
int timeSubMs(const timeval& tv1, const timeval& tv2) {
    return (tv1.tv_sec - tv2.tv_sec) * 1000 + (tv1.tv_usec - tv2.tv_usec) / 1000;
}

class ReactorServer {
private:
    int epfd;
    timeval begin;
    std::vector<Conn> conn_list;
    std::function<int(char*, int, char*)> kvs_handler;

    // 设置事件
    int setEvent(int fd, int event, bool flag) {
        epoll_event ev;
        ev.events = event;
        ev.data.fd = fd;
        if (flag) {
            if (epoll_ctl(epfd, EPOLL_CTL_ADD, fd, &ev) == -1) {
                perror("epoll_ctl: add");
            }
        } else {
            if (epoll_ctl(epfd, EPOLL_CTL_MOD, fd, &ev) == -1) {
                perror("epoll_ctl: mod");
            }
        }
        return 0;
    }

    // 注册事件
    int eventRegister(int fd, int event) {
        if (fd < 0) return -1;
        conn_list[fd].fd = fd;
        conn_list[fd].r_action.recv_callback = [this](int fd) { return this->recvCb(fd); };
        conn_list[fd].send_callback = [this](int fd) { return this->sendCb(fd); };

        memset(conn_list[fd].rbuffer, 0, BUFFER_LENGTH);
        conn_list[fd].rlength = 0;
        memset(conn_list[fd].wbuffer, 0, BUFFER_LENGTH);
        conn_list[fd].wlength = 0;

        setEvent(fd, event, true);
        return 0;
    }

    // 接受新连接回调
    int acceptCb(int fd) {
        sockaddr_in clientaddr;
        socklen_t len = sizeof(clientaddr);
        int clientfd = accept(fd, reinterpret_cast<sockaddr*>(&clientaddr), &len);
        if (clientfd < 0) {
            printf("accept errno: %d --> %s\n", errno, strerror(errno));
            return -1;
        }

        eventRegister(clientfd, EPOLLIN);

        if ((clientfd % 1000) == 0) {
            timeval current;
            gettimeofday(&current, nullptr);
            int time_used = timeSubMs(current, begin);
            begin = current;
        }
        return 0;
    }

    // 接收数据回调
    int recvCb(int fd) {
        memset(conn_list[fd].rbuffer, 0, BUFFER_LENGTH);
        int count = recv(fd, conn_list[fd].rbuffer, BUFFER_LENGTH, 0);
        if (count == 0) {
            close(fd);
            epoll_ctl(epfd, EPOLL_CTL_DEL, fd, nullptr);
            return 0;
        } else if (count < 0) {
            printf("count: %d, errno: %d, %s\n", count, errno, strerror(errno));
            close(fd);
            epoll_ctl(epfd, EPOLL_CTL_DEL, fd, nullptr);
            return 0;
        }

        conn_list[fd].rlength = count;

        if (kvs_handler) {
            // 将接收到的数据传递给 commandHandler 处理
            conn_list[fd].wlength = kvs_handler(
                conn_list[fd].rbuffer,  // 输入数据
                conn_list[fd].rlength,  // 输入数据长度
                conn_list[fd].wbuffer   // 输出响应缓冲区
            );
        }

        setEvent(fd, EPOLLOUT, false);
        return count;
    }

    // 发送数据回调
    int sendCb(int fd) {
        int count = 0;
        if (conn_list[fd].wlength != 0) {
            count = send(fd, conn_list[fd].wbuffer, conn_list[fd].wlength, 0);
        }
        setEvent(fd, EPOLLIN, false);
        return count;
    }

    // 初始化服务器套接字
    int initServer(unsigned short port) {
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        sockaddr_in servaddr;
        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
        servaddr.sin_port = htons(port);

        std::cout << "bind port: " << port << std::endl;

        if (bind(sockfd, reinterpret_cast<sockaddr*>(&servaddr), sizeof(servaddr)) == -1) {
            printf("bind failed: %s\n", strerror(errno));
        }

        listen(sockfd, 10);
        return sockfd;
    }

public:
    ReactorServer() : epfd(0), conn_list(CONNECTION_SIZE) {}

    // 启动反应堆
    void start(unsigned short port, std::function<int(char*, int, char*)> handler) {
        kvs_handler = handler;
        epfd = epoll_create(1);

        for (int i = 0; i < MAX_PORTS; ++i) {
            int sockfd = initServer(port + i);
            conn_list[sockfd].fd = sockfd;
            conn_list[sockfd].r_action.recv_callback = [this](int fd) { return this->acceptCb(fd); };
            setEvent(sockfd, EPOLLIN, true);
        }

        gettimeofday(&begin, nullptr);

        while (true) {
            std::vector<epoll_event> events(1024);
            int nready = epoll_wait(epfd, events.data(), 1024, -1);

            for (int i = 0; i < nready; ++i) {
                int connfd = events[i].data.fd;
                if (events[i].events & EPOLLIN) {
                    conn_list[connfd].r_action.recv_callback(connfd);
                }
                if (events[i].events & EPOLLOUT) {
                    conn_list[connfd].send_callback(connfd);
                }
            }
        }
    }
};

void runReactorServer() {
    ReactorServer server;
    server.start(2000, commandHandler);
}