#include <stdio.h>
#include <winsock2.h>
#include <signal.h>

#pragma comment (lib, "ws2_32.dll")  //加载 ws2_32.dll
#define BUF_SIZE 100

int isRunning = 1;

void sigint_handler(int sig)
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
    struct sockaddr_in sockAddr;
    memset(&sockAddr, 0, sizeof(sockAddr));  //每个字节都用0填充
    sockAddr.sin_family = PF_INET;  //使用IPv4地址
    sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");  //具体的IP地址
    sockAddr.sin_port = htons(10086);  //端口
    bind(servSock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
    //进入监听状态
    listen(servSock, 20);
    //接收客户端请求
    // 进程被杀的信号
    // 注册信号处理函数
    signal(SIGILL, sigint_handler);
    // 循环接受客户端的请求
    while(isRunning){
        SOCKADDR clntAddr;
        int nSize = sizeof(SOCKADDR);
        SOCKET clntSock = accept(servSock, (SOCKADDR*)&clntAddr, &nSize);
        char buffer[BUF_SIZE];  //缓冲区
        int strLen = recv(clntSock, buffer, BUF_SIZE, 0);  //接收客户端发来的数据
        printf("Message form client: %s", buffer);
        // 发送 server 字符给客户端
        send(clntSock, "hello client\n", 13, 0);
        // send(clntSock, buffer, strLen, 0);  //将数据原样返回
        //关闭套接字
        closesocket(clntSock);

        //终止 DLL 的使用
        // 休眠1秒
        Sleep(1000);
    }
    closesocket(servSock);
    WSACleanup();
    system("pause");
    return 0;
}
