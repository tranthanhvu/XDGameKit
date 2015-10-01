//
//  ComponentType.cpp
//  GiatXeng
//
//  Created by VuTT5 on 9/30/15.
//
//

#include "ComponentType.hpp"

USING_NS_XD;

int ComponentType::nextId = 1;

ComponentType::ComponentType() {
    init();
}

void ComponentType::init() {
    _id = nextId++;
}

void ComponentType::reset() {
    nextId = 1;
}