#include <stdio.h>
#include <winsock2.h>
#include <signal.h>

#pragma comment (lib, "ws2_32.dll")  //加载 ws2_32.dll
#define BUF_SIZE 100

int isRunning = 1;

void sigint_handler(__attribute__((unused)) int sig)
{
    printf("sigint_handler");
    isRunning = 0;
}

int main(){
    WSADATA wsaData;
    WSAStartup( MAKEWORD(2, 2), &wsaData);
    //创建套接字
    SOCKET servSock = socket(AF_INET, SOCK_STREAM, 0);
    //绑定套接字
    struct sockaddr_in sockAddress;
    memset(&sockAddress, 0, sizeof(sockAddress));  //每个字节都用0填充
    sockAddress.sin_family = PF_INET;  //使用IPv4地址
    sockAddress.sin_addr.s_addr = inet_addr("127.0.0.1");  //具体的IP地址
    sockAddress.sin_port = htons(10086);  //端口
    __attribute__((unused)) int r = bind(servSock, (SOCKADDR*)&sockAddress, sizeof(SOCKADDR));
    //进入监听状态
    listen(servSock, 20);
    //接收客户端请求
    // 进程被杀的信号
    // 注册信号处理函数
    signal(SIGILL, sigint_handler);
    // 循环接受客户端的请求
    while(isRunning){
        SOCKADDR clientAddress;
        int nSize = sizeof(SOCKADDR);
        SOCKET clientSock = accept(servSock, (SOCKADDR*)&clientAddress, &nSize);
        char buffer[BUF_SIZE];  //缓冲区
        // int strLen = recv(clientSock, buffer, BUF_SIZE, 0);  //接收客户端发来的数据
        printf("Message form client: %s", buffer);
        // 发送 server 字符给客户端
        send(clientSock, "hello client\n", 13, 0);
        // send(clientSock, buffer, strLen, 0);  //将数据原样返回
        //关闭套接字
        closesocket(clientSock);

        //终止 DLL 的使用
        // 休眠1秒
        Sleep(1000);
    }
    closesocket(servSock);
    WSACleanup();
    system("pause");
    return 0;
}
