//
//  SceneManager.cpp
//  XDGameKit
//
//  Created by yoyo on 10/7/15.
//
//

#include "SceneManager.hpp"

USING_NS_XD;

SceneManager::SceneManager():
_currentScene(nullptr)
{
}

SceneManager::~SceneManager() {
    
}

void SceneManager::addNewScene(GameScene* scene) {
    
    _scenes.push_back(scene);
    
    if (_scenes.size() == 1) {
        _currentScene = scene;
    }
}

void SceneManager::addLazyScene(const std::string& name, std::function<GameScene *()> callback) {
    if (!name.empty() && callback) {
        _lazySceneNames.emplace_back(name);
        _lazyScenes.emplace_back(callback);
    }
}

GameScene* SceneManager::getCurrentScene() {
    if (_currentScene == nullptr) {
        if (_scenes.empty() == false) {
            _currentScene = _scenes.front();
        } else if (_lazyScenes.empty() == false) {
            _currentScene = _lazyScenes.front()(); // _lazyScenes.front() likes a function pointer
        }
    }
    
    return _currentScene;
}

GameScene* SceneManager::getSceneWithName(const std::string &name) {
    for (int i=0; i<_scenes.size(); i++) {
        auto obj = _scenes.at(i);
        if (typeid(obj).name() == name) {
            return obj;
        }
    }
    
    for (int i=0; i<_lazySceneNames.size(); i++) {
        std::string className = _lazySceneNames.at(i);
        
        if (className == name) {
            auto obj = _lazyScenes.at(i)();
            _scenes.push_back(obj);
            
            return obj;
        }
    }
    
    return nullptr;
}