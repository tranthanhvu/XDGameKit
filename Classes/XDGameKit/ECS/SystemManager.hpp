//
//  SystemManager.hpp
//  GiatXeng
//
//  Created by VuTT5 on 9/30/15.
//
//

#ifndef SystemManager_hpp
#define SystemManager_hpp

#include <stdio.h>
#include "XDMacros.h"

NS_XD_BEGIN

class EntitySystem;
class Entity;
class World;

class SystemManager: public cocos2d::Ref {
private:
    World *_world;
    
public:
    SystemManager(World *world);
    ~SystemManager();
};

NS_XD_END

#endif /* SystemManager_hpp */
