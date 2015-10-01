//
//  EntityTemplate.hpp
//  GiatXeng
//
//  Created by VuTT5 on 9/30/15.
//
//

#ifndef EntityTemplate_hpp
#define EntityTemplate_hpp

#include <stdio.h>
#include "XDMacros.h"

NS_XD_BEGIN

class Entity;
class Component;

class EntityTemplate: public cocos2d::Ref {
    
public:
    EntityTemplate(rapidjson::Document &node); // use json node
    EntityTemplate(cocos2d::ui::Widget &widget); // use widget node
    
    
    
};

NS_XD_END
#endif /* EntityTemplate_hpp */
