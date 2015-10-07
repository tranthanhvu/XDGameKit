//
//  PlayerInputComponent.cpp
//  GiatXeng
//
//  Created by VuTT5 on 9/29/15.
//
//

#include "PlayerInputComponent.hpp"

USING_NS_CC;

PlayerInputComponent::PlayerInputComponent() : _position(cocos2d::Point::ZERO) {
    
}

PlayerInputComponent::~PlayerInputComponent() {
    
}

bool PlayerInputComponent::init() {
    if (cocos2d::Component::init()) {
        this->setName("PlayerInput");
        
        _eventListener = EventListenerTouchOneByOne::create();
        _eventListener->setSwallowTouches(true);
        
        _eventListener->onTouchBegan = CC_CALLBACK_2(PlayerInputComponent::onTouchBegan, this);
        _eventListener->onTouchMoved = CC_CALLBACK_2(PlayerInputComponent::onTouchMoved, this);
        _eventListener->onTouchEnded = CC_CALLBACK_2(PlayerInputComponent::onTouchEnded, this);
        _eventListener->onTouchCancelled = CC_CALLBACK_2(PlayerInputComponent::onTouchCanceled, this);
        
        return true;
    }
    
    return false;
}

void PlayerInputComponent::onEnter() {
    Component::onEnter();
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(_eventListener, this->getOwner());
}

void PlayerInputComponent::update(float update) {
    if (!this->getOwner()->getPosition().equals(_position)) {
        this->getOwner()->setPosition(_position);
    }
}

bool PlayerInputComponent::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event) {
    return true;
}

void PlayerInputComponent::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event) {
    
}

void PlayerInputComponent::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event) {
    _position = touch->getLocation();
}

void PlayerInputComponent::onTouchCanceled(cocos2d::Touch *touch, cocos2d::Event *event) {
    
}