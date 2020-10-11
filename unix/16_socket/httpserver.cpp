#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

using namespace std;


int main(void)
{
   int httpd = socket(AF_INET, SOCK_STREAM, 0); 
   if(httpd < 0)
      cout << "socket error" << endl;

   //sockaddr_in 是 IPV4的套接字地址结构。定义在<netinet/in.h>
   struct sockaddr_in name;
   u_short port = 0;
   memset(&name, 0, sizeof(name));
   name.sin_family = AF_INET;
   //将*port 转换成以网络字节序表示的16位整数
   name.sin_port = htons(port);
   //INADDR_ANY是一个 IPV4通配地址的常量，包含于<netinet/in.h>
   //大多实现都将其定义成了0.0.0.0 参读《TLPI》P1187
   name.sin_addr.s_addr = htonl(INADDR_ANY);

   int ret = bind(httpd, (struct sockaddr*)&name, sizeof(name));
   if(ret < 0)
      cout << "bind error" << endl;


    cout << port << endl;
    //如果调用 bind 后端口号仍然是0，则手动调用getsockname()获取端口号
    if (port == 0)  /* if dynamically allocating a port */
    {
       int namelen = sizeof(name);
       //getsockname()包含于<sys/socker.h>中，参读《TLPI》P1263
       //调用getsockname()获取系统给 httpd 这个 socket 随机分配的端口号
       if (getsockname(httpd, (struct sockaddr *)&name, (socklen_t *)&namelen) == -1)
          cout << "getsockname error" << endl;
       cout << name.sin_port << endl;
       port = ntohs(name.sin_port);
       cout << port << endl;
    }
 

   if (listen(httpd, 5) < 0)
      cout << "listen error" << endl;



   struct sockaddr_in client_name;
   socklen_t client_name_len = sizeof(client_name);
   while(1)
   {

       ret = accept(httpd, (struct sockaddr*)&client_name, &client_name_len);

       cout << ret << endl;

   }

   return 0;
}
