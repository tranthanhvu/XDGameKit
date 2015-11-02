//
//  SceneManager.cpp
//  XDGameKit
//
//  Created by yoyo on 10/7/15.
//
//

#include "SceneManager.hpp"

USING_NS_XD;

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager() {
    
}

void SceneManager::addLazyScene(const std::string& name, std::function<GameScene *()> callback) {
    if (!name.empty() && callback) {
        _lazySceneNames.emplace_back(name);
        _lazyScenes.emplace_back(callback);
    }
}

GameScene* SceneManager::getFirstScene() {
    GameScene* gameScene = nullptr;
    if (_scenes.empty() == false) {
        gameScene = _scenes.front();
    } else if (_lazyScenes.empty() == false) {
        gameScene = _lazyScenes.front()(); // _lazyScenes.front() likes a function pointer
    }
    
    return gameScene;
}

GameScene* SceneManager::getCurrentScene() {
    return static_cast<GameScene*>(Director::getInstance()->getRunningScene());
}

GameScene* SceneManager::getSceneWithName(const std::string &name) {
    for (size_t i=0; i<_scenes.size(); i++) {
        auto obj = _scenes.at(i);
        if (typeid(obj).name() == name) {
            return obj;
        }
    }
    
    for (size_t i=0; i<_lazySceneNames.size(); i++) {
        std::string className = _lazySceneNames.at(i);
        
        if (className == name) {
            auto obj = _lazyScenes.at(i)();
            _scenes.push_back(obj);
            
            return obj;
        }
    }
    
    return nullptr;
}