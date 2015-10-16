//
//  MyRequestHelper.hpp
//  XDGameKit
//
//  Created by VuTT5 on 10/16/15.
//
//

#ifndef MyRequestHelper_hpp
#define MyRequestHelper_hpp

#include <stdio.h>
#include "RequestHelper.hpp"
#include "Singleton.h"

class MyRequestHelper: public XD::RequestHelper, public Singleton<MyRequestHelper>   {
    
public:
    void getGoogle(std::function<void ()> success, std::function<void (std::string)> failure);
};

#endif /* MyRequestHelper_hpp */
