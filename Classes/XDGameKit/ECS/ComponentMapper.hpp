//
//  ComponentMapper.hpp
//  GiatXeng
//
//  Created by VuTT5 on 9/30/15.
//
//

#ifndef ComponentMapper_hpp
#define ComponentMapper_hpp

#include <stdio.h>
#include "XDMacros.h"

NS_XD_BEGIN

class EntityManager;

// High performce component retrieval from entities. Use this wherever you need to retrieve components from entities often and fast.
class ComponentMapper: public cocos2d::Ref {
private:
    EntityManager *_entityManager;
    
public:
    ~ComponentMapper();
    
    void init();
    
};

NS_XD_END

#endif /* ComponentMapper_hpp */
