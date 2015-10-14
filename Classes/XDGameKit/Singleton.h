//
//  Singleton.h
//  GiatXeng
//
//  Created by VuTT5 on 9/23/15.
//
//

#ifndef Singleton_h
#define Singleton_h

#include <stdio.h>

template <typename T>
class Singleton {
    
    
public:
    static void create() {
        if (self == NULL) {
            self = new T();
        }
    }
    
    static void release() {
        SAFE_DELETE(self);
    }
    
    static T* getInstance() {
        create();
        
        return self;
    }
    
protected:
    Singleton() {}
    virtual ~Singleton() {}
    Singleton(const Singleton& _other);
    T& operator=(const Singleton& _other);
    
protected:
    static T* self;
};

template <typename T>
T* Singleton<T>::self = NULL;

// Singleton Declare
#define DECLARE_SINGLETON(className) \
    private: \
        friend class Singleton<className>; \
        className(const className& _other); \
        className& operator = (const className& _other);

#endif /* Singleton_h */
