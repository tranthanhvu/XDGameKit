//
//  GameSystem.cpp
//  XDGameKit
//
//  Created by VuTT5 on 10/1/15.
//
//

#include "GameSystem.hpp"
#include "XDGameKit.h"
#include "cocostudio/CocoStudio.h"

USING_NS_XD;
USING_NS_CC;

//GameSystem* GameSystem::sm_pSharedGameSystem = nullptr;

GameSystem::GameSystem()
{
//    sm_pSharedGameSystem = this;
    
    cocos2d::Director::getInstance()->getScheduler()->schedule(schedule_selector(GameSystem::update), this, 0.0f,false);
    
    init();
}

GameSystem::~GameSystem()
{
//    sm_pSharedGameSystem = 0;
    
    cocostudio::ArmatureDataManager::destroyInstance();
}

void GameSystem::update(float dt)
{
}

//GameSystem* GameSystem::getInstance()
//{
//    if (sm_pSharedGameSystem==nullptr) {
//        sm_pSharedGameSystem = new GameSystem();
//        sm_pSharedGameSystem->init();
//    }
//    
//    return sm_pSharedGameSystem;
//}

void GameSystem::init()
{
    _sceneManager = new SceneManager();
}

void GameSystem::didEnterBackgroud() {
    Director::getInstance()->stopAnimation();
}

void GameSystem::willEnterForeground() {
    Director::getInstance()->startAnimation();
}