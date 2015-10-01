//
//  GameScene.hpp
//  GiatXeng
//
//  Created by VuTT5 on 10/1/15.
//
//

#ifndef GameScene_hpp
#define GameScene_hpp

#include <stdio.h>
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace ui;

class GameScene: public cocos2d::Layer {
    
protected:
    // this function registers all button with even onButtonEvent if the name of the button has begin with "btn"
    void registerButtonsEvent(Widget *widget);
    
public:
    virtual bool init();
    
    virtual bool loadGUIScene();
    virtual void configureGUIScene();
    
    virtual void onButtonEvent(Ref *pSender, Widget::TouchEventType eventType);
};

#endif /* GameScene_hpp */
