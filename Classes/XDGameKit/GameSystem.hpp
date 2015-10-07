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
#include "XDMacros.h"

NS_XD_BEGIN

class ECSManager;

class GameSystem: cocos2d::Ref {
    
public:
    GameSystem();
    virtual ~GameSystem();
    
    static GameSystem* getInstance();
    
    virtual void init();
    
    void update(float dt);
    
    void didEnterBackgroud();
    void willEnterForeground();
    
    CC_SYNTHESIZE_READONLY(ECSManager*, _ecs, ECS);
    
protected:
    static GameSystem * sm_pSharedGameSystem;
};

NS_XD_END

#endif /* GameSystem_hpp */
