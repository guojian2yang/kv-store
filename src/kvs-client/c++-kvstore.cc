#include <iostream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

// 连接服务器并发送命令，返回响应
string sendCommand(const string& serverAddr, int port, const string& command) {
    // 创建 TCP socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        return "ERROR: 创建 socket 失败";
    }

    // 设置服务器地址
    sockaddr_in servAddr;
    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(port);
    if (inet_pton(AF_INET, serverAddr.c_str(), &servAddr.sin_addr) <= 0) {
        close(sockfd);
        return "ERROR: 无效的服务器地址";
    }

    // 连接服务器
    if (connect(sockfd, (struct sockaddr*)&servAddr, sizeof(servAddr)) < 0) {
        close(sockfd);
        return "ERROR: 连接服务器失败";
    }

    // 发送命令
    if (send(sockfd, command.c_str(), command.size(), 0) < 0) {
        close(sockfd);
        return "ERROR: 发送命令失败";
    }

    // 接收响应
    char buffer[1024] = {0};
    int bytesRead = recv(sockfd, buffer, sizeof(buffer), 0);
    if (bytesRead < 0) {
        close(sockfd);
        return "ERROR: 接收响应失败";
    }

    close(sockfd);
    return string(buffer, bytesRead);
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        cout << "使用方法: ./kvs_client <服务器地址> <端口> <命令> [参数...]" << endl;
        cout << "示例:" << endl;
        cout << "  设置键值: ./kvs_client 127.0.0.1 2000 set myKey myValue" << endl;
        cout << "  获取键值: ./kvs_client 127.0.0.1 2000 get myKey" << endl;
        cout << "  删除键值: ./kvs_client 127.0.0.1 2000 del myKey" << endl;
        return 1;
    }

    string serverAddr = argv[1];
    int port = stoi(argv[2]);
    string command;

    // 拼接命令参数（如 "set myKey myValue"）
    for (int i = 3; i < argc; ++i) {
        command += argv[i];
        if (i != argc - 1) command += " ";
    }

    cout << "===== 输入参数 =====" << endl;
    cout << "服务器地址: " << serverAddr << endl;
    cout << "端口: " << port << endl;
    cout << "发送的命令: " << command << endl;
    cout << "====================" << endl;

    string response = sendCommand(serverAddr, port, command);
    cout << "响应: " << response << endl;

    return 0;
}