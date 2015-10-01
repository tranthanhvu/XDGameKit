//
//  World.hpp
//  GiatXeng
//
//  Created by VuTT5 on 9/30/15.
//
//

#ifndef World_hpp
#define World_hpp

#include <stdio.h>
#include "XDMacros.h"

NS_XD_BEGIN

class Entity;
class EntityManager;
class SystemManager;
class TagManager;
class GroupManager;

// The primary instance for the framework. It contains all the managers
// You must use this to create, delete and retrive entities
// It is also important to set the delta each game loop iteration, and initialize before game loop.
class World: public cocos2d::Ref {
    
public:
    World();
    ~World();
    
    void removeEntity(Entity *entity);
    void refreshEntity(Entity *entity);
    Entity* createEntity();
    Entity* getEntity(int entityId);
    void loopStart();
    
    CC_SYNTHESIZE_READONLY(SystemManager*, _systemManager, SystemManager);
    CC_SYNTHESIZE_READONLY(EntityManager*, _entityManager, EntityManager);
    CC_SYNTHESIZE_READONLY(TagManager*, _tagManager, TagManager);
    CC_SYNTHESIZE_READONLY(GroupManager*, _groupManager, GroupManager);
    CC_SYNTHESIZE(float, _delta, Delta);
    
private:
    cocos2d::Vector<Entity*> _deleted;
    cocos2d::Vector<Entity*> _refreshed;
};

NS_XD_END

#endif /* World_hpp */
