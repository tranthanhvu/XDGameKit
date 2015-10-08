#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "PlayerInputComponent.hpp"

USING_NS_CC;

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    _filePath = "TestScene.csb";
    
    if ( !GameScene::init() )
    {
        return false;
    }
    
    
    return true;
}

void HelloWorld::configureGUIScene() {
    _rootNode->getChildByName("rhino")->addComponent(PlayerInputComponent::create());
}