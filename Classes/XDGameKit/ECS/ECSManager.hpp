//
//  ECSManager.hpp
//  GiatXeng
//
//  Created by VuTT5 on 10/1/15.
//
//

#ifndef ECSManager_hpp
#define ECSManager_hpp

#include <stdio.h>
#include "../XDMacros.h"
#include "ECSFactory.hpp"

NS_XD_BEGIN

class Entity;
class Component;
class System;

class ECSManager: public cocos2d::Ref {
    
public:
    ECSManager();
    ~ECSManager();
    
    Entity* createEntity();
    // create an entity from the configure file
    Entity* createEntity(const std::string& filename);
    void removeEntity(Entity* entity);
    
    void addComponentToEntity(Component* component, Entity* entity);
    void removeComponentFromEntity(const ecsId id, Entity* entity);
    void removeComponentFromEntity(Component *component, Entity* entity);
    void removeAllComponent(Entity* entity);
    
    void update(float dt);
    
    void registerSystem(System* system);
    void unregisterSystem(System *system);

private:
    void addingEntities();
    void removingEntities();
    bool contants(ecsId id);
    
    ecsId generateNewEntityId();
    cocos2d::Vector<Entity*> _entities;
    
    ecsId _lowestUnassignedEntityId;
    cocos2d::Vector<Entity*> _beAdding;
    cocos2d::Vector<Entity*> _beRemoving;
    cocos2d::Vector<Entity*> _handing;
    
    ECSFactory<Component*> *_componentFactory;
    ECSFactory<System*> *_systemFactory;
};

NS_XD_END

#endif /* ECSManager_hpp */
