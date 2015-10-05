//
//  Component.cpp
//  GiatXeng
//
//  Created by VuTT5 on 9/30/15.
//
//

#include "Component.hpp"
USING_NS_XD;

Component::Component(const std::string& type) :
_type(type) {
    
}

Component::~Component() {
    
}

Component* Component::create(const std::string& type) {
    Component* entity = new(std::nothrow) Component(type);
    if (entity) {
        entity->autorelease();
        return entity;
    } else {
        delete entity;
        entity = NULL;
        return NULL;
    }
}

Component* Component::cloneEmpty() const {
    return nullptr;
}

void Component::initWithJson(const std::string &json) {
    
}

void Component::onCreate() {
    
}

void Component::onAttached() {
    
}

void Component::onFinalize() {
    
}

void Component::onRemove(bool willDel) {
    
}

void Component::onRelease() {
    
}

void Component::onDetached() {
    
}

void Component::onDestroy() {
    
}

void Component::onUpdate(float delta) {
    
}

bool Component::onUpdateData() {
    
}
