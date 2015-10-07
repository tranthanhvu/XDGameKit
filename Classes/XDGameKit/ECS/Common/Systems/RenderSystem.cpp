//
//  RenderSystem.cpp
//  XDGameKit
//
//  Created by VuTT5 on 10/6/15.
//
//

#include "RenderSystem.hpp"

USING_NS_XD;

RenderSystem::RenderSystem() : XD::System("RenderSystem", XD::RenderComponent::TYPE) {
    
}

System* RenderSystem::cloneEmpty() const {
    return new RenderSystem();
}

void RenderSystem::onInit() {
    
}

void RenderSystem::onAttached() {
    _node = (RenderComponent*)getComponentByType(RenderComponent::TYPE);
    _node->getNode()->setUserData(getOwnEntity());
}

void RenderSystem::onDeattached() {
    
}

void RenderSystem::update(float dt) {
    
}

void RenderSystem::onComponentChanged() {
    
}