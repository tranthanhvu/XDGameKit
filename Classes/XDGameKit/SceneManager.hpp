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



// This class manages all scenes. Don't subclass it, you should subclass GameSystem then add all scenes in that class
class SceneManager: cocos2d::Ref {
private:
    std::vector<std::function<GameScene*()>> _lazyScenes;
    std::vector<std::string> _lazySceneNames;
    GameScene* _currentScene;
    
    void addNewScene(GameScene* scene);
    
public:
    SceneManager();
    ~SceneManager();
    
    
    void addLazyScene(const std::string& name, std::function<GameScene*()> callback);
    
    GameScene* getCurrentScene();
    
    template <class T>
    T getSceneWithType(T className) {
        for (int i=0; i<_scenes.size(); i++) {
            auto obj = _scenes.at(i);
            if (typeid(obj).name() == typeid(T).name()) {
                return obj;
            }
        }
        
        for (int i=0; i<_lazySceneNames.size(); i++) {
            std::string className = _lazySceneNames.at(i);

            if (className == typeid(T).name()) {
                auto obj = _lazyScenes.at(i)();
                _scenes.push_back(obj);
                
                return obj;
            }
        }
        
        return nullptr;
    }
    
    CC_SYNTHESIZE_READONLY(std::vector<GameScene*>, _scenes, Scenes);
};

#define ADD_SCENE(__className__) addLazyScene( #__className__, [](){ return new (std::nothrow) __className__;} );

#endif /* SceneManager_hpp */
