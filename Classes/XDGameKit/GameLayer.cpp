//
//  GameLayer.cpp
//  XDGameKit
//
//  Created by VuTT5 on 10/7/15.
//
//

#include "GameLayer.hpp"

USING_NS_XD;

GameLayer::GameLayer() {
    
}

GameLayer::~GameLayer() {
    
}

bool GameLayer::init() {
    if (Layer::init()) {
        if (this->loadGUIScene()) {
            // configure GUI if needed
            this->configureGUIScene();
            
            return true;
        }
    }
    
    return false;
}

bool GameLayer::loadGUIScene() {
    _rootNode = CSLoader::createNode(_filePath);
    
    if (_rootNode) {
        Size screenSize = Director::getInstance()->getVisibleSize();
        _rootNode->setAnchorPoint(Vec2(0.5, 0.5));
        _rootNode->setPosition(screenSize * 0.5);
        addChild(_rootNode);
        return true;
    }
    
    return false;
}

void GameLayer::configureGUIScene() {
    // register buttons event
    for (Node *node : this->getChildren()) {
        this->registerButtonsEvent(static_cast<Widget*>(node));
    }
}

void GameLayer::onButtonEvent(Ref *pSender, Widget::TouchEventType eventType) {
    
}

void GameLayer::registerButtonsEvent(Node *node) {
    std::string name = node->getName();
    std::string btnPrefix = "btn";
    
    auto res = std::mismatch(btnPrefix.begin(), btnPrefix.end(), name.begin());
    
    if (res.first == btnPrefix.end()) {
        Button *button = static_cast<Button*>(node);
        button->addTouchEventListener(CC_CALLBACK_2(GameLayer::onButtonEvent, this));
    }
    
    Vector<Node*> children = node->getChildren();
    for (Node* child : children) {
        registerButtonsEvent(child);
    }
}