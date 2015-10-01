//
//  World.cpp
//  GiatXeng
//
//  Created by VuTT5 on 9/30/15.
//
//

#include "World.hpp"
#include "SystemManager.hpp"
#include "EntityManager.hpp"
#include "TagManager.hpp"
#include "GroupManager.hpp"

USING_NS_XD;

World::World() {
    // add more managers
    _systemManager = new SystemManager(this);
    _entityManager = new EntityManager(this);
    _groupManager = new GroupManager();
    _tagManager = new TagManager();
    _delta = 0;
}

World::~World() {
    _refreshed.clear();
    _deleted.clear();
}

void World::removeEntity(Entity* entity) {
    if (_deleted.contains(entity)) {
        _deleted.pushBack(entity);
    }
}

void World::refreshEntity(Entity* entity) {
    
}

Entity* World::createEntity() {
    
}

Entity* World::getEntity(int entityId) {
    
}

void World::loopStart() {
    
}