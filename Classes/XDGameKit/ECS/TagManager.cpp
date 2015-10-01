//
//  TagManager.cpp
//  GiatXeng
//
//  Created by VuTT5 on 9/30/15.
//
//

#include "TagManager.hpp"

USING_NS_XD;

TagManager::TagManager() {
    
}

void TagManager::subscribe(const std::string tag, Entity *entity) {
    remove(entity);
    _tagByEntity.insert(tag, entity);
}

void TagManager::unSubscribe(const std::string tag) {
    _tagByEntity.erase(tag);
}

bool TagManager::isSubscribe(const std::string tag) {
    return _tagByEntity.at(tag) != NULL;
}

Entity* TagManager::getEntity(const std::string tag) {
    return _tagByEntity.at(tag);
}

void TagManager::remove(Entity *entity) {
    // TODO: find cleaner way to remove by value
    for (auto it = _tagByEntity.begin(); it != _tagByEntity.end(); ++it) {
        if (it->second == entity) {
            _tagByEntity.erase(it->first);
            return;
        }
    }
}