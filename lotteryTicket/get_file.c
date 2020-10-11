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


using namespace std;
  
FILE *fp;  //定义FILE类型指针
//这个函数是为了符合CURLOPT_WRITEFUNCTION而构造的
////完成数据保存功能
size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)  
{
    int written = fwrite(ptr, size, nmemb, (FILE *)fp);
    cout << "=============begin:============ " << (char *)ptr << "===========end===========" << endl;
    neb::CJsonObject oJson{(char *)ptr}; 

    cout << "reason:" << oJson("reason")  << endl;
    cout << "lottery_id:" << oJson["result"]("lottery_id")  << endl;
    cout << "lottery_no:" << oJson["result"]("lottery_no")  << endl;
    cout << "lottery_date:" << oJson["result"]("lottery_date")  << endl;
    cout << "lottery_res:" << oJson["result"]("lottery_res")  << endl;
    return written;
}

int main(int argc, char *argv[])
{
    CURL *curl;
    if (argc != 3)
    {
		fprintf(stderr, "usage: %s url filename\n", argv[0]);
		exit(-1);
    }
    curl_global_init(CURL_GLOBAL_ALL);  
    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, argv[1]);  
 
    if((fp = fopen(argv[2],"w")) == NULL)
    {
        curl_easy_cleanup(curl);
        exit(1);
    }
  //CURLOPT_WRITEFUNCTION 将后继的动作交给write_data函数处理
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);  
    curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    exit(0);
}
