//
//  MyRequestHelper.cpp
//  XDGameKit
//
//  Created by VuTT5 on 10/16/15.
//
//

#include "MyRequestHelper.hpp"

USING_NS_XD;

void MyRequestHelper::getGoogle(std::function<void ()> success, std::function<void (std::string)> failure) {
    std::string url = "https://www.google.com";
    
    getRequest(url, ^(HttpClient *client, HttpResponse *response) {
        
        if (response->isSucceed()) {
            log("ok");
            
//            std::vector<char>* buffer = response->getResponseData();
//            std::string res = response->getHttpRequest()->getTag();
//            for (int i = 0; i < buffer->size(); i++)
//            {
//                res += (*buffer)[i];
//            }
            std::string data = RequestHelper::dumpData(response);
            log("%s", data.c_str());
//
//            if (success) {
//                success();
//            }
        } else {
            log("ko ok");
//            if (failure) {
//                failure("error");
//            }
        }
    });
}