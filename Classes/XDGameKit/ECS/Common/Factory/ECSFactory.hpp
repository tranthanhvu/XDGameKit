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

/*
 Template class don't like a normal class. If you implement the function into cpp file, you must
 add template class ECSFactory<[whatever class name you will implement]> or you will get the 
 'undefined reference' error. 
 Another way, you must implement your function in define file. In this way, when you include your
 file, the compiler also know your function. This is more flexible as it means you can use extra
 instantiations without any more work. But it could mean the same function are compiled many times,
 once in each translation unit. This's not a big problem, as the linker will correctly ignore the 
 duplicate implementations. But it might slow down the compilation a little.
 */

template <class T>
class ECSFactory: public cocos2d::Ref {
    
public:
    ECSFactory() {}
    ~ECSFactory() {}
    
    static ECSFactory<T>* create() {
        ECSFactory<T> *factory = new(std::nothrow) ECSFactory<T>();
        if (factory) {
            factory->autorelease();
            return factory;
        } else {
            delete factory;
            factory = NULL;
            return NULL;
        }
    }
    
    bool registerObject(const std::string& type, T object) {
        if (_objects.find(type) == _objects.end()) {
            // not found
            _objects.insert(std::make_pair(type, object));
            return true;
        }
        
        return false;
    }
    
    void unregisterObject(const std::string& type) {
        _objects.erase(type);
    }
    
    T getObject(const std::string& type) {
        if (_objects.find(type) != _objects.end()) {
            return _objects.at(type);
        }
        
        return nullptr;
    }
    
private:
    std::map<std::string, T> _objects;
};

NS_XD_END

#endif /* ECSFactory_hpp */
