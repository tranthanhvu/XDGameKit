//
//  MyWidget.cpp
//  DoraemonAdventure
//
//  Created by yoyo on 10/10/15.
//
//

#include "MyWidget.hpp"
#include "GameScene.hpp"

USING_NS_CC;
USING_NS_XD;
using namespace std;
using namespace cocos2d::ui;

MyWidget::MyWidget() {
    
}

Widget::ccWidgetTouchCallback MyWidget::onLocateTouchCallback(const std::string &callBackName) {
    return CC_CALLBACK_2(MyWidget::onButtonTouched, this);
    // Callback names must match the ones you set in cocos studio
//    if (callBackName == "on_button_touched")
//    {
//        return CC_CALLBACK_2(MyWidget::onButtonTouched, this);
//    }
//    if (callBackName == "some_other_callback")
//    {
//        // Add declaration in to header for other callbacks
////        return CC_CALLBACK_2(MyWidget::onSomeOtherTouch, this);
//    }
    
    return nullptr;
}

Widget::ccWidgetClickCallback MyWidget::onLocateClickCallback(const std::string &callBackName) {
    return nullptr;
}

Widget::ccWidgetEventCallback MyWidget::onLocateEventCallback(const std::string &callBackName) {
    return nullptr;
}

void MyWidget::onButtonTouched(cocos2d::Ref* object, cocos2d::ui::Widget::TouchEventType type) {
    CCLOG("finish");
}