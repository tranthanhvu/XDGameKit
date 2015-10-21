//
//  GameSystem.cpp
//  GiatXeng
//
//  Created by VuTT5 on 10/1/15.
//
//

#include "GameSystem.hpp"
#include "XDGameKit.h"
#include "cocostudio/CocoStudio.h"

USING_NS_XD;
USING_NS_CC;

GameSystem::GameSystem()
{
    cocos2d::Director::getInstance()->getScheduler()->schedule(schedule_selector(GameSystem::update), this, 0.0f,false);
    
    init();
}

GameSystem::~GameSystem()
{
    cocostudio::ArmatureDataManager::destroyInstance();
}

void GameSystem::update(float dt)
{
}

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

GameScene* GameSystem::getCurrentScene() {
    return _sceneManager->getCurrentScene();
}