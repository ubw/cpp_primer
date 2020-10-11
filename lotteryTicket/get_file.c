// 采用CURLOPT_WRITEFUNCTION 实现网页下载保存功能
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
#include <curl/curl.h>
//#include <curl/types.h>
#include <curl/easy.h>
#include "CJsonObject/CJsonObject.hpp"
#include "CJsonObject/cJSON.h"
#include <string>
#include <vector>
#include "email.h"
#include <string.h>


using namespace std;

char *tmp =  NULL;
int tmp_size = 0;

void foo()
{

    if(tmp == NULL)
    {
        cout << "tmp == NULL" << endl;
        return;
    }

    neb::CJsonObject oJson{tmp}; 

    cout << "reason:" << oJson("reason")  << endl;
    cout << "lottery_id:" << oJson["result"]("lottery_id")  << endl;
    cout << "lottery_no:" << oJson["result"]("lottery_no")  << endl;
    cout << "lottery_date:" << oJson["result"]("lottery_date")  << endl;
    cout << "lottery_res:" << oJson["result"]("lottery_res")  << endl;

    string str_tmp = oJson["result"]("lottery_res");

    cout << str_tmp.c_str() << endl;





   Email *email = Email::Instance();
  vector<string> recipients;
  recipients.push_back("<cjwstorm@163.com>");

   int ret = email->sendmail(
        "<cjwstorm@163.com>",                              /* from     */
        recipients,                                      /* to       */
        str_tmp.c_str(),                                  /* subject  */
        str_tmp.c_str(),                              /* body     */
        "smtp.163.com",                                     /* hostname */
         25                                               /* port     */
    );

    if (ret != 0)
                std::cerr << "Failed to send mail (code: " << ret << ")" << std::endl;
    else
                std::cout << "Mail successfully sent" << std::endl;

        email->Release();

    return;
}

//这个函数是为了符合CURLOPT_WRITEFUNCTION而构造的
////完成数据保存功能
//要服务端没有关闭连接,只要服务端还在发送响应数据,这个函数就会被调用,而被调用的次数不一定只是一次,也许会是许多次,每一次被调用所接收到的数据大小是size*nmemb,这些文档上似乎没有提到,因为这是理当如此的事情.所以在处理响应数据的时候不能想当然,必须要考虑到这个函数会被多次调用.
size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)  
{
    cout << "=======in==========" << endl;
    int cur_size = nmemb * size;
    cout << cur_size << endl;
    tmp = (char *)realloc(tmp, tmp_size+cur_size);
    memcpy(tmp + tmp_size,  ptr, cur_size);
    tmp_size += cur_size;
    cout << tmp << endl;
    cout << "=======end==========" << endl;
    return size*nmemb;
}

int main(int argc, char *argv[])
{
    CURL *curl;
    
    if (argc != 2)
    {
		fprintf(stderr, "usage: %s url \n", argv[0]);
		exit(-1);
    }

    curl_global_init(CURL_GLOBAL_ALL);  
    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, argv[1]);  
 
  //CURLOPT_WRITEFUNCTION 将后继的动作交给write_data函数处理
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);  
    
    //执行顺序????
    curl_easy_perform(curl);
    foo();
    if(tmp != NULL)
        free(tmp);
    curl_easy_cleanup(curl);
    exit(0);
}
