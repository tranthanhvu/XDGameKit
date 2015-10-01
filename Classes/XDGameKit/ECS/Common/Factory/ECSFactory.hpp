//
//  ECSFactory.hpp
//  GiatXeng
//
//  Created by VuTT5 on 10/1/15.
//
//

#ifndef ECSFactory_hpp
#define ECSFactory_hpp

#include <stdio.h>
#include "XDMacros.h"

NS_XD_BEGIN

template <class T>
class ECSFactory: public cocos2d::Ref {
    
public:
    ECSFactory();
    ~ECSFactory();
    
    bool registerObject(T* object);
    void unregisterObject(const std::string& type);
    T* createObject(const std::string& type);
    
private:
    std::map<std::string, T*> _objects;
};

NS_XD_END

#endif /* ECSFactory_hpp */
