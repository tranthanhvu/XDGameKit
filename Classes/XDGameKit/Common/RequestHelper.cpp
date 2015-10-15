//
//  RequestHelper.cpp
//  XDGameKit
//
//  Created by VuTT5 on 10/15/15.
//
//

#include "RequestHelper.hpp"

void RequestHelper::request(std::string url, HttpRequest::Type type, std::function<void (HttpClient *, HttpResponse *)> response) {
    HttpRequest* request = new(std::nothrow) HttpRequest();
    request->setUrl(url.c_str());
    request->setRequestType(type);
    request->setResponseCallback(response);
    HttpClient::getInstance()->setTimeoutForConnect(5);
    HttpClient::getInstance()->send(request);
    request->release();
}

void RequestHelper::getRequest(std::string url, std::function<void (HttpClient *, HttpResponse *)> response) {
    request(url, HttpRequest::Type::GET, response);
}

void RequestHelper::postRequest(std::string url, std::function<void (HttpClient *, HttpResponse *)> response) {
    request(url, HttpRequest::Type::POST, response);
}