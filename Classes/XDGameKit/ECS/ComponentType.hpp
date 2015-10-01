//
//  ComponentType.hpp
//  GiatXeng
//
//  Created by VuTT5 on 9/30/15.
//
//

#ifndef ComponentType_hpp
#define ComponentType_hpp

#include <stdio.h>
#include "XDMacros.h"

NS_XD_BEGIN

// Identifier id for a component object
// Do not instantiate a Component Type, let's use the ComponentTypeManager instead of
class ComponentType: public cocos2d::Ref {
    
public:
    ComponentType();
    
    static void reset();
    
    CC_SYNTHESIZE(int, _id, Id);
    
private:
    static int nextId;
    void init();
};
NS_XD_END

#endif /* ComponentType_hpp */
