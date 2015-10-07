//
//  SceneManager.hpp
//  XDGameKit
//
//  Created by yoyo on 10/7/15.
//
//

#ifndef SceneManager_hpp
#define SceneManager_hpp

#include <stdio.h>

class GameScene;



// This class manages all scenes. You should subclass, and add all scenes in game
class SceneManager: cocos2d::Ref {
    
public:
    SceneManager();
    ~SceneManager();
    
    void addNewScene(GameScene* scene);
    
    template <class T>
    T getSceneWithType(T className) {
        for (int i=0; i<_scenes.size(); i++) {
            auto obj = _scenes.at(i);
            if (typeid(obj).name() == typeid(T).name()) {
                return obj;
            }
        }
        
        return nullptr;
    }
    
    CC_SYNTHESIZE(GameScene*, _currentScene, CurrentScene);
    CC_SYNTHESIZE_READONLY(cocos2d::Vector<GameScene*>, _scenes, Scenes);
};

#endif /* SceneManager_hpp */
