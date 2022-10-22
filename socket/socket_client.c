#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.dll")  //加载 ws2_32.dll

#define BUF_SIZE 100

int main(){
    //初始化DLL
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    //创建套接字
    SOCKET sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    //向服务器发起请求
    struct sockaddr_in sockAddress;
    memset(&sockAddress, 0, sizeof(sockAddress));  //每个字节都用0填充
    sockAddress.sin_family = PF_INET;
    sockAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
    sockAddress.sin_port = htons(10086);
    __attribute__((unused)) int c = connect(sock, (SOCKADDR*)&sockAddress, sizeof(SOCKADDR));
    //获取用户输入的字符串并发送给服务器
    // char bufSend[BUF_SIZE] = {0};
    // printf("Input a string: ");
    // scanf("%s", bufSend);
    send(sock, "hello server\n", 13, 0);
    //接收服务器传回的数据
    char bufRev[BUF_SIZE] = {0};
    recv(sock, bufRev, BUF_SIZE, 0);
    //输出接收到的数据
    printf("Message form server: %s", bufRev);
    //关闭套接字
    closesocket(sock);
    //终止使用 DLL
    WSACleanup();
    system("pause");
    return 0;
}
