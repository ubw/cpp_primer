#include "email.h"
#include <iostream>
#include <netdb.h>         /* gethostbyname  */
#include <netinet/in.h>    /* htons          */
#include <sys/socket.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

using namespace std;

Email* Email::instance = NULL;

Email::Email() {}

Email::~Email() {}

Email* Email::Instance() {
	if(instance == NULL) {
		instance = new Email();
	}
	return instance;
}

void Email::Release() {
	if(instance) {
		delete instance;
	}
	instance = NULL;
}

void Email::writeSocket(const int sock, const char *str, const char *arg) {
	char buf[4096];

	if(arg != NULL)
		snprintf(buf, sizeof(buf), str, arg);
	else
		snprintf(buf, sizeof(buf), str, NULL);

	send(sock, buf, strlen(buf), 0);
}

int Email::sendmail(const char *from, std::vector<std::string> recipients, const char *subject, const char *body, const char *hostname, const int port) {
	struct hostent *host;
	struct sockaddr_in saddr_in;
	int sock = 0;
	char buf[256];

	sock = socket(AF_INET, SOCK_STREAM, 0);
        cout << "sock " << sock << endl;
	host = gethostbyname(hostname);
        if(host == NULL)
        {
            cout << "host null" << endl;
            return -1;
        }
        cout << host << endl;
        cout << host->h_name << endl;

	saddr_in.sin_family      = AF_INET;
	saddr_in.sin_port        = htons((u_short)port);
	saddr_in.sin_addr.s_addr = 0;

	memcpy((char*) & (saddr_in.sin_addr), host->h_addr, host->h_length);

        int ret;
        cout << "connect begin" << endl;
	ret = connect(sock, (struct sockaddr*)&saddr_in, sizeof(saddr_in));
        if (ret != 0){
                cout << ret << endl;
		return -2;
	}
        cout << "=======connect success=========" << endl;
	recv(sock, buf, 254, 0);
	printf("\nRec: %s", buf);

        cout << "========= EHLO========" << endl;
	writeSocket(sock, "EHLO %s\n",       "cjwstorm");    // greeting
	recv(sock, buf, 254, 0);
	printf("\nRec: %s", buf);

        cout << "========= AUTH LOGIN========" << endl;
	writeSocket(sock, "AUTH LOGIN\n",       NULL);    // greeting
	recv(sock, buf, 254, 0);
	printf("\nRec: %s", buf);

        cout << "========= uer========" << endl;
	writeSocket(sock, "%s\n",       "Y2p3c3Rvcm0=");    // greeting
	recv(sock, buf, 254, 0);
	printf("\nRec: %s", buf);

        cout << "========= pwd========" << endl;
	writeSocket(sock, "%s\n",       "RFBTUERTR0dUQUlMQVJKWQ==");    // greeting
	recv(sock, buf, 254, 0);
	printf("\nRec: %s", buf);

        cout << "========= FROM========" << endl;

	writeSocket(sock, "MAIL FROM: %s\n", from);    // from
	recv(sock, buf, 254, 0);
	printf("\nRec: %s\n", buf);

	
        cout << "========= TO========" << endl;
	for(int i = 0; i < (int)recipients.size(); i++){
		writeSocket(sock, "RCPT TO: %s\n",   recipients.at(i).c_str()); // to
		//printf("RCPT TO: %s\n", recipients.at(i).c_str());
		recv(sock, buf, 254, 0);
	}
	printf("\nRec: %s\n", buf);
    
        cout << "=========1 DATA========" << endl;

	writeSocket(sock, "DATA\n",          NULL);    // begin data
	recv(sock, buf, 254, 0);
	printf("\nRec: %s", buf);

	// next comes mail headers
	writeSocket(sock, "From: %s\r\n",      from);
	cout << "from: " << from << endl;

        cout << "=========2 TO========" << endl;
	
	for(int i = 0; i < (int)recipients.size(); i++){
		writeSocket(sock, "To: %s\n",   recipients.at(i).c_str()); // to
	        cout << "To: " << recipients.at(i).c_str() << endl;
	}
        cout << "=========3 subject========" << endl;
	
	writeSocket(sock, "subject:%s",   subject);
        cout << "=========4========" << endl;

	writeSocket(sock, "\n",              NULL);
        cout << "=========5 body========" << endl;

	writeSocket(sock, "%s\n",            body);    // data
        cout << "=========6 . ========" << endl;

	writeSocket(sock, ".\n",             NULL);    // end data
	recv(sock, buf, 254, 0);
	printf("\nRec: %s\n", buf);

        cout << "=========7 quit========" << endl;

	writeSocket(sock, "quit\n",          NULL);    // terminate
      
        cout << "end test" << endl;

	close(sock);

	return 0;
}
