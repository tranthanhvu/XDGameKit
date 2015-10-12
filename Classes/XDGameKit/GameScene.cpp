//
//  GameScene.cpp
//  GiatXeng
//
//  Created by VuTT5 on 10/1/15.
//
//

#include "GameScene.hpp"
#include "extensions/cocos-ext.h"

USING_NS_XD;

GameScene::GameScene() {
    Director::getInstance()->getTextureCache()->removeUnusedTextures();
    SpriteFrameCache::getInstance()->removeUnusedSpriteFrames();
}

GameScene::~GameScene() {
    
}

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
    ArmatureDataManager::destroyInstance();
    SceneReader::destroyInstance();
    ActionManagerEx::destroyInstance();
    GUIReader::destroyInstance();
    
    Scene::onEnter();
}

bool GameScene::loadGUIScene() {
    _rootNode = CSLoader::createNode(_filePath);//SceneReader::getInstance()->createNodeWithSceneFile(_filePath);
    
    if (_rootNode) {
        Size screenSize = Director::getInstance()->getVisibleSize();
        
        _rootNode->setContentSize(screenSize);
        ui::Helper::doLayout(_rootNode);
        addChild(_rootNode);
        return true;
    }
    
    return false;
}

void GameScene::configureGUIScene() {
    // register buttons event
    for (Node *node : this->getChildren()) {
        this->registerButtonsEvent(static_cast<Widget*>(node));
    }
}

void GameScene::onButtonEvent(Ref *pSender, Widget::TouchEventType eventType) {
    
}

void GameScene::onAnimationEvent(cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string &movementID) {
    
}

void GameScene::registerButtonsEvent(Node *node) {
    std::string name = node->getName();
    std::string btnPrefix = "btn";
    
    auto res = std::mismatch(btnPrefix.begin(), btnPrefix.end(), name.begin());
    
    if (res.first == btnPrefix.end()) {
        Button *button = static_cast<Button*>(node);
        button->addTouchEventListener(CC_CALLBACK_2(GameScene::onButtonEvent, this));
    }
    
    Vector<Node*> children = node->getChildren();
    for (Node* child : children) {
        registerButtonsEvent(child);
    }
}

void GameScene::registerAnimationEvent(Node *node) {
    std::string name = node->getName();
    std::string aniPrefix = "ani";
    
    auto res = std::mismatch(aniPrefix.begin(), aniPrefix.end(), name.begin());
    
    if (res.first == aniPrefix.end()) {
        ComRender *render = static_cast<ComRender*>(node->getComponent(kComponentRenderArmature));
        Armature *arm = static_cast<Armature*>(render->getNode());
        arm->getAnimation()->setMovementEventCallFunc(CC_CALLBACK_3(GameScene::onAnimationEvent, this));
    }
    
    Vector<Node*> children = node->getChildren();
    for (Node* child: children) {
        registerAnimationEvent(child);
    }
}

void GameScene::runBackgroundAudio() {
    if (_rootNode) {
        ComAudio* audio = static_cast<ComAudio*>(_rootNode->getComponent(kComponentAudioBackground));
        if (audio) {
            audio->playBackgroundMusic();
        }
    }
}