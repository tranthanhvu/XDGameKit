//
//  GameSystem.hpp
//  GiatXeng
//
//  Created by VuTT5 on 10/1/15.
//
//

#ifndef GameSystem_hpp
#define GameSystem_hpp

#include <stdio.h>
#include "XDGameKit.h"

NS_XD_BEGIN

class SceneManager;
class GameScene;

// You should subclass GameSystem and add all global parameters into that subclass
class GameSystem: cocos2d::Ref {
    
public:
    GameSystem();
    virtual ~GameSystem();
    
    virtual void init();
    
    void update(float dt);
    
    void didEnterBackgroud();
    void willEnterForeground();
    
    GameScene* getCurrentScene();
    
    CC_SYNTHESIZE_READONLY(SceneManager*, _sceneManager, SceneManager);
};

NS_XD_END

#endif /* GameSystem_hpp */
