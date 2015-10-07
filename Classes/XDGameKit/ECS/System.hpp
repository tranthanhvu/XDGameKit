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
#include "XDGameKit.h"

NS_XD_BEGIN

enum SystemStatus {
    SystemStatus_Free = 0,    // system is not attached yet
    SystemStatus_Normal        // system is attached
};

class System: public cocos2d::Ref {
    
public:
    System(const std::string type, const std::string firstType, int priority = 0);
    ~System();
    
    static System* create(const std::string type, const std::string firstType, int priority=0);
    
    bool init();
    
    virtual System* cloneEmpty() const;
    virtual void onInit();
    virtual void onAttached();
    virtual void onDeattached();
    virtual void update(float dt);
    virtual void onComponentChanged();
    
    virtual void onEvent(const std::string& eventName);
    
    Component* getComponentByType(const std::string& type);
    
    CC_SYNTHESIZE(Entity*, _ownEntity, OwnEntity);
    CC_SYNTHESIZE(std::string, _type, Type);
    CC_SYNTHESIZE(std::string, _firstType, FirstType);
    CC_SYNTHESIZE(int, _priority, Priority);
    CC_SYNTHESIZE(SystemStatus, _status, Status);
};

NS_XD_END

#endif /* System_hpp */
