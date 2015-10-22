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
#include "cocostudio/CocoStudio.h"
#include "XDGameKit.h"

NS_XD_BEGIN

using namespace cocostudio;
USING_NS_CC;
using namespace ui;

class GameLayer;

// Each game screen should inherit from GameSceen.
class GameScene: public cocos2d::Scene {
    
protected:
    Node* _rootNode;
    __Array* _popoverLayers;
    
    // to register all buttons with even onButtonEvent if the name of the node has begun with "btn"
    void registerButtonsEvent(Node *node);
    // to register all armatures with event onAnimationEvent if the name of the node has begun with "ani"
    void registerAnimationEvent(Node *node);
    
    void runBackgroundAudio();
    
public:
    GameScene();
    virtual ~GameScene();
    
    virtual bool init();
    
    virtual void onEnter();
    virtual void onExit();
    
    virtual bool loadGUIScene();
    virtual void configureGUIScene();
    
    virtual void onButtonEvent(Ref *pSender, Widget::TouchEventType eventType);
    
    virtual void onAnimationEvent(cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID);
    
    bool isAddedPopoverLayer(GameLayer* layer);
    void addPopoverLayer(GameLayer* layer);
    void removePopoverLayer(GameLayer* layer);
    
    CC_SYNTHESIZE(std::string, _filePath, FilePath);
    CC_SYNTHESIZE(bool, _autoRunBackgroundAudio, AutoRunBackgroundAudio);
};

NS_XD_END

#endif /* GameScene_hpp */
