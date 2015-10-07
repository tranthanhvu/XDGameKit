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
    
    _scenes.pushBack(scene);
    
    if (_scenes.size() == 1) {
        _currentScene = scene;
    }
}

