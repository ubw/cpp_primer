#include <iostream>
#include <vector>
#include "email.h"

int main() {
	Email *email = Email::Instance();
	std::vector<std::string> recipients;
	recipients.push_back("<cjwstorm@163.com>");
	
	int ret = email->sendmail(
        "<cjwstorm@163.com>",                              /* from     */
        recipients,                                      /* to       */
        "hello stmp",                                  /* subject  */
        "Mail body.\n\nCan contain linebreaks.\n\nBye.", /* body     */
        "smtp.163.com",                                     /* hostname */
         25                                               /* port     */
    );

    if (ret != 0)
		std::cerr << "Failed to send mail (code: " << ret << ")" << std::endl;
    else
		std::cout << "Mail successfully sent" << std::endl;
	
	email->Release();
	return ret;
}
