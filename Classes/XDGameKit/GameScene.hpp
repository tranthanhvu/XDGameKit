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

// Each game screen should inherit from GameSceen.
class GameScene: public cocos2d::Scene {
    Node* _rootNode;
    
protected:
    // this function registers all button with even onButtonEvent if the name of the button has begun with "btn"
    void registerButtonsEvent(Widget *widget);
    
    Node* createGameScene();
    
public:
    virtual bool init();

    virtual void onEnter();
    virtual void onExit();

    virtual bool loadGUIScene();
    virtual void configureGUIScene();
    
    virtual void onButtonEvent(Ref *pSender, Widget::TouchEventType eventType);
    
    CC_SYNTHESIZE(std::string, _filePath, FilePath);
};

#endif /* GameScene_hpp */
