//
//  GameScene.cpp
//  GiatXeng
//
//  Created by VuTT5 on 10/1/15.
//
//

#include "GameScene.hpp"

bool GameScene::init(){
    if(Layer::init()){
        if (this->loadGUIScene()) {
            // configure GUI if need
            this->configureGUIScene();
            
            return true;
        }
    }
    return false;
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