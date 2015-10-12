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
#include "XDGameKit.h"

NS_XD_BEGIN

class GameScene;

// This class manages all scenes. Don't subclass it, you should subclass GameSystem then add all scenes in that class
class SceneManager: public cocos2d::Ref {
private:
    std::vector<std::function<GameScene*()>> _lazyScenes;
    std::vector<std::string> _lazySceneNames;
    GameScene* _currentScene;
    
    void addNewScene(GameScene* scene);
    
public:
    SceneManager();
    ~SceneManager();
    
    void addLazyScene(const std::string& name, std::function<GameScene*()> callback);
    GameScene* getSceneWithName(const std::string& className);
    GameScene* getCurrentScene();
    
    CC_SYNTHESIZE_READONLY(std::vector<GameScene*>, _scenes, Scenes);
};

#define ADD_SCENE(__className__) addLazyScene( #__className__, [](){ return __className__::create();} )
#define GET_SCENE(__className__) getSceneWithName( #__className__)

NS_XD_END

#endif /* SceneManager_hpp */
