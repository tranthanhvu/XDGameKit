//
//  GameScene.cpp
//  GiatXeng
//
//  Created by VuTT5 on 10/1/15.
//
//

#include "GameScene.hpp"
#include "extensions/cocos-ext.h"
#include "cocostudio/CocoStudio.h"

using namespace cocostudio;

bool GameScene::init(){
    if(Scene::init()){
        if (this->loadGUIScene()) {
            // configure GUI if need
            this->configureGUIScene();
            
            return true;
        }
    }
    return false;
}

void GameScene::onEnter() {
    Scene::onEnter();
}

void GameScene::onExit() {
    ActionManagerEx::getInstance()->releaseActions();
    
    Scene::onEnter();
}

bool GameScene::loadGUIScene() {
    return true;
}

void GameScene::configureGUIScene() {
    // register buttons event
    for (Node *node : this->getChildren()) {
        this->registerButtonsEvent(static_cast<Widget*>(node));
    }
}

void GameScene::onButtonEvent(Ref *pSender, Widget::TouchEventType eventType) {
    
}

void GameScene::registerButtonsEvent(cocos2d::ui::Widget *widget) {
    std::string name = widget->getName();
    std::string btnPrefix = "btn";
    
    auto res = std::mismatch(btnPrefix.begin(), btnPrefix.end(), name.begin());
    
    if (res.first == btnPrefix.end()) {
        widget->addTouchEventListener(CC_CALLBACK_2(GameScene::onButtonEvent, this));
    }
    
    Vector<Node*> children = widget->getChildren();
    for (Node* node : children) {
        registerButtonsEvent(static_cast<Widget*>(node));
    }
}

Node* GameScene::createGameScene() {
    _rootNode = SceneReader::getInstance()->createNodeWithSceneFile(_filePath);
    return _rootNode;
}