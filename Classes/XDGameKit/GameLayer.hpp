//
//  GameLayer.hpp
//  XDGameKit
//
//  Created by VuTT5 on 10/7/15.
//
//

#ifndef GameLayer_hpp
#define GameLayer_hpp

#include <stdio.h>
#include <ui/CocosGUI.h>
#include <cocostudio/CocoStudio.h>
#include "XDGameKit.h"

NS_XD_BEGIN

USING_NS_CC;
using namespace ui;
using namespace cocostudio;

class GameLayer: public cocos2d::LayerColor {
protected:
    Node* _rootNode;
    // to register all buttons with even onButtonEvent if the name of the node has begun with "btn"
    void registerButtonsEvent(Node *node);
    
public:
    GameLayer();
    virtual ~GameLayer();
    
    virtual bool init();
    virtual bool loadGUIScene();
    virtual void configureGUIScene();
    
    virtual void onButtonEvent(Ref *pSender, Widget::TouchEventType eventType);
    CC_SYNTHESIZE(std::string, _filePath, FilePath);
};

NS_XD_END

#endif /* GameLayer_hpp */
