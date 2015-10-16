#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "PlayerInputComponent.hpp"
#include "MyRequestHelper.hpp"

USING_NS_CC;
using namespace timeline;

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
    
    // start action time line
    ActionTimeline *actionTimeLine = CSLoader::createTimeline(_filePath);
    _rootNode->runAction(actionTimeLine);
    actionTimeLine->gotoFrameAndPlay(0);
    
    MyRequestHelper::getInstance()->getGoogle(^() {
        log("success");
    }, ^(std::string) {
        log("failure");
    });
}