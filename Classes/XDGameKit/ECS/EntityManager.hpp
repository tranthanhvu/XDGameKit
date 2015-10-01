//
//  EntityManager.hpp
//  GiatXeng
//
//  Created by VuTT5 on 9/30/15.
//
//

#ifndef EntityManager_hpp
#define EntityManager_hpp

#include <stdio.h>
#include "../XDMacros.h"

NS_XD_BEGIN

class Entity;
class World;
class Component;
class ComponentType;

// Entity Manager
// You should create entity using the create() function. I believe we should have a place to manage all entities.
class EntityManager: public cocos2d::Ref {
    cocos2d::Vector<Entity*> _entities;
    
public:
    EntityManager(World *world);
    ~EntityManager();
    
    Entity* create();
    void remove(Entity *entity);
    void removeComponentsOfEntity(Entity *entity);
    bool isActive(int entityId);
    void addComponent(Entity *entity, Component *component);
    void refresh(Entity *entity);
    
    void removeAllEntities();
    
    void removeComponent(Entity *entity, Component *component);
    void getComponent(Entity *entity, ComponentType *type);
    
};

NS_XD_END

#endif /* EntityManager_hpp */
