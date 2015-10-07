#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "PlayerInputComponent.hpp"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
//    GameSystem::getInstance();
//    GameSystem::getInstance()->getECS();
//    _entity = GameSystem::getInstance()->getECS()->createEntity("TestScene.csb");
//    addChild(_entity->getNode());
    
    auto rootNode = CSLoader::createNode("TestScene.csb");
    addChild(rootNode);

    rootNode->getChildByName("rhino")->addComponent(PlayerInputComponent::create());
//    rootNode->getChildByName("rhino")->scheduleUpdate();
//    cocostudio::ComRender *component = rootNode->getChildByName<cocostudio::ComRender*>("rhino");
    return true;
}
