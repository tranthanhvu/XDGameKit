//
//  System.cpp
//  GiatXeng
//
//  Created by VuTT5 on 9/30/15.
//
//

#include "System.hpp"

USING_NS_XD;

System::System(const ecsId id, const ecsId firstId, int priority):
_id(id),
_firstId(firstId),
_priority(priority),
_status(SystemStatus_Free) {
}

System::~System() {
    
}

System* System::create(const ecsId id, const ecsId firstId, int priority) {
    System* system = new(std::nothrow) System(id, firstId, priority);
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