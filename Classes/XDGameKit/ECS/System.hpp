//
//  System.hpp
//  GiatXeng
//
//  Created by VuTT5 on 9/30/15.
//
//

#ifndef System_hpp
#define System_hpp

#include <stdio.h>
#include "../XDMacros.h"

NS_XD_BEGIN

class Entity;

enum SystemStatus {
    SystemStatus_Free = 0,    // system is not attached yet
    SystemStatus_Normal        // system is attached
};

class System: public cocos2d::Ref {
    
public:
    System(const ecsId id, const ecsId firstId, int priority = 0);
    ~System();
    
    static System* create(const ecsId id, const ecsId firstId, int priority=0);
    
    bool init();
    
    virtual System* cloneEmpty() const;
    virtual void onInit();
    virtual void onAttached();
    virtual void onDeattached();
    virtual void update(float dt);
    virtual void onComponentChanged();
    
    virtual void onEvent(const std::string& eventName);
    
    CC_SYNTHESIZE(Entity*, _ownEntity, OwnEntity);
    CC_SYNTHESIZE(ecsId, _id, ID);
    CC_SYNTHESIZE(ecsId, _firstId, FirstId);
    CC_SYNTHESIZE(int, _priority, Priority);
    CC_SYNTHESIZE(SystemStatus, _status, Status);
};

NS_XD_END

#endif /* System_hpp */
