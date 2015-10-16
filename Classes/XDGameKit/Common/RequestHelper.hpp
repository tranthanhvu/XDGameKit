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
#include "network/HttpRequest.h"
#include "network/HttpClient.h"
#include "XDGameKit.h"

NS_XD_BEGIN

USING_NS_CC;
using namespace network;

class RequestHelper {
    
public:
    void request(std::string url, HttpRequest::Type type, std::function<void (HttpClient*, HttpResponse*)> response);
    void getRequest(std::string url, std::function<void (HttpClient*, HttpResponse*)> response);
    void postRequest(std::string url, std::function<void (HttpClient*, HttpResponse*)> response);
    
    std::string dumpData(HttpResponse* response);
};

NS_XD_END

#endif /* RequestHelper_hpp */
