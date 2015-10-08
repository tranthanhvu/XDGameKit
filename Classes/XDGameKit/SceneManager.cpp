//
//  SceneManager.cpp
//  XDGameKit
//
//  Created by yoyo on 10/7/15.
//
//

#include "SceneManager.hpp"

SceneManager::SceneManager() {
    
}

SceneManager::~SceneManager() {
    
}

void SceneManager::addNewScene(GameScene* scene) {
    
    _scenes.push_back(scene);
    
    if (_scenes.size() == 1) {
        _currentScene = scene;
    }
}

void SceneManager::addLazyScene(const std::string &name, std::function<GameScene *()> callback) {
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