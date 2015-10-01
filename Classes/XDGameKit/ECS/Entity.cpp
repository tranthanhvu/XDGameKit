//
//  Entity.cpp
//  GiatXeng
//
//  Created by VuTT5 on 9/30/15.
//
//

#include "Entity.hpp"

USING_NS_XD;

Entity::Entity() {
    
}

Entity::~Entity() {
    
}

Entity* Entity::createWithId(const ecsId id) {
    Entity* entity = new(std::nothrow) Entity();
    if (entity && entity->initWithID(id)) {
        entity->autorelease();
        return entity;
    } else {
        delete entity;
        entity = NULL;
        return NULL;
    }
}

bool Entity::initWithID(const ecsId id) {
    _id = id;
    
    return true;
}

void Entity::removeComponent(const ecsId id) {
    
}

void Entity::removeAllComponents() {
    _component.clear();
}

void Entity::componentChanged() {
    
}

XD::Component* Entity::getComponentByType(const std::string& type) {
    return _component.at(type);
}

cocos2d::Node* Entity::getNode() {
    return nullptr;
}

Entity* Entity::getParent() {
    return nullptr;
}

void Entity::sendEvent(const std::string& eventName) {
    for (auto iter=_systems.begin(); iter != _systems.end(); iter++) {
        
    }
}

bool Entity::equals(const Entity& target) const {
    return target.getId() == _id;
}