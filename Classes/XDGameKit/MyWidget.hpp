//
//  MyWidget.hpp
//  DoraemonAdventure
//
//  Created by yoyo on 10/10/15.
//
//

#ifndef MyWidget_hpp
#define MyWidget_hpp

#include <stdio.h>
#include "cocostudio/CocoStudio.h"
#include "cocostudio/WidgetCallBackHandlerProtocol.h"

// Thanks: http://discuss.cocos2d-x.org/t/cocos-studio-linking-button-with-action/19838/8
// THis class don't solve callback directly, It'll send event to correspondence scene
class MyWidget: public cocos2d::Node, public cocostudio::WidgetCallBackHandlerProtocol {
    
public:
    CREATE_FUNC(MyWidget);
    
    MyWidget();
    
    virtual cocos2d::ui::Widget::ccWidgetTouchCallback onLocateTouchCallback(const std::string &callBackName);
    virtual cocos2d::ui::Widget::ccWidgetClickCallback onLocateClickCallback(const std::string &callBackName);
    virtual cocos2d::ui::Widget::ccWidgetEventCallback onLocateEventCallback(const std::string &callBackName);
    
    virtual void onButtonTouched(cocos2d::Ref* object, cocos2d::ui::Widget::TouchEventType type);
};

#endif /* MyWidget_hpp */
