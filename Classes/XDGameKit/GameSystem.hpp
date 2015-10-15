//
//  GameSystem.hpp
//  XDGameKit
//
//  Created by VuTT5 on 10/1/15.
//
//

#ifndef GameSystem_hpp
#define GameSystem_hpp

#include <stdio.h>
#include "XDMacros.h"

NS_XD_BEGIN

//class ECSManager;
class SceneManager;

// You should subclass GameSystem and add all global parameters into that subclass
class GameSystem: cocos2d::Ref {
    
public:
    GameSystem();
    virtual ~GameSystem();
    
//    static GameSystem* getInstance();
    
    virtual void init();
    
    void update(float dt);
    
    void didEnterBackgroud();
    void willEnterForeground();
    
//    CC_SYNTHESIZE_READONLY(ECSManager*, _ecs, ECS);
    CC_SYNTHESIZE_READONLY(SceneManager*, _sceneManager, SceneManager);
    
protected:
//    static GameSystem * sm_pSharedGameSystem;
};

NS_XD_END

#endif /* GameSystem_hpp */
