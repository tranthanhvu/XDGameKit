//
//  PlayerInputComponent.hpp
//  GiatXeng
//
//  Created by VuTT5 on 9/29/15.
//
//

#ifndef PlayerInputComponent_hpp
#define PlayerInputComponent_hpp

#include "cocostudio/CocoStudio.h"

class PlayerInputComponent: public cocostudio::ComController {
    cocos2d::EventListenerTouchOneByOne* _eventListener;
    
public:
    PlayerInputComponent();
    virtual ~PlayerInputComponent();
    
    virtual bool init();
    virtual void onEnter();
    virtual void update(float update);
    
    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchCanceled(cocos2d::Touch* touch, cocos2d::Event* event);
    
    CREATE_FUNC(PlayerInputComponent);
    
    CC_SYNTHESIZE(cocos2d::Point, _position, Position);
};

#endif /* PlayerInputComponent_hpp */
