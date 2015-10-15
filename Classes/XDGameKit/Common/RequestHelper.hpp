//
//  RequestHelper.hpp
//  XDGameKit
//
//  Created by VuTT5 on 10/15/15.
//
//

#ifndef RequestHelper_hpp
#define RequestHelper_hpp

#include <stdio.h>
#include "Singleton.h"
#include "network/HttpRequest.h"
#include "network/HttpClient.h"

USING_NS_CC;
using namespace network;

class RequestHelper: public cocos2d::Ref, public Singleton<RequestHelper> {
    
public:
    void request(std::string url, HttpRequest::Type type, std::function<void (HttpClient*, HttpResponse*)> response);
    void getRequest(std::string url, std::function<void (HttpClient*, HttpResponse*)> response);
    void postRequest(std::string url, std::function<void (HttpClient*, HttpResponse*)> response);
};

#endif /* RequestHelper_hpp */
