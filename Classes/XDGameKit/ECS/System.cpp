//
//  System.cpp
//  GiatXeng
//
//  Created by VuTT5 on 9/30/15.
//
//

#include "System.hpp"

USING_NS_XD;

System::System(const std::string type, const std::string firstType, int priority):
_type(type),
_firstType(firstType),
_priority(priority),
_status(SystemStatus_Free) {
}

System::~System() {
    
}

System* System::create(const std::string type, const std::string firstType, int priority) {
    System* system = new(std::nothrow) System(type, firstType, priority);
    if (system) {
        system->autorelease();
        return system;
    } else {
        delete system;
        system = NULL;
        return NULL;
    }
}


bool System::init() {
    return true;
}

System* System::cloneEmpty() const {
    return nullptr;
}

void System::onInit() {
    
}

void System::onAttached() {
    
}

void System::onDeattached() {
    
}

void System::update(float dt) {
    
}

void System::onComponentChanged() {
    
}

void System::onEvent(const std::string& eventName) {
    
}

XD::Component* System::getComponentByType(const std::string& type) {
    if (_ownEntity) {
        return _ownEntity->getComponentByType(type);
    }
    
    return nullptr;
}