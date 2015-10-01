//
//  GroupManager.cpp
//  GiatXeng
//
//  Created by VuTT5 on 9/30/15.
//
//

#include "GroupManager.hpp"

USING_NS_XD;

GroupManager::GroupManager() {
    
}

GroupManager::~GroupManager() {
    _groupByEntity.clear();
    _entitiesByGroup.clear();
}

void GroupManager::set(std::string group, Entity *entity) {
    remove(entity);
    
//    cocos2d::Vector<cocos2d::Vector<Entity*>> entities = _entitiesByGroup.at(group);
//    if (&entities == nullptr) {
//        
//    }
    
}

void GroupManager::remove(Entity *entity) {
    
}

std::string GroupManager::getGroupOf(Entity *entity) {
    return "";
}

bool GroupManager::isGrouped(Entity *entity) {
    return false;
}

bool GroupManager::isInGroup(std::string group, Entity *entity) {
    return false;
}

cocos2d::Vector<Entity*> GroupManager::getEntities(std::string group) {
    cocos2d::Vector<Entity*> result = cocos2d::Vector<Entity*>();
    return result;
}