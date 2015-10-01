//
//  Component.hpp
//  GiatXeng
//
//  Created by VuTT5 on 9/30/15.
//
//

#ifndef Component_hpp
#define Component_hpp

#include <stdio.h>
#include "../XDMacros.h"

NS_XD_BEGIN

class Entity;

// to handle specific aspects of an entity's behavior in a general way
// All components in the system must inherit this class
class Component: public cocos2d::Ref {
    
public:
    CC_SYNTHESIZE(std::string, _type, Type);
    CC_SYNTHESIZE(Entity*, _ownEntity, OwnEntity);
    
protected:
    Component(const std::string& type);
    virtual ~Component();
    
    static Component* create(const std::string& type);
    
    /**
     *  Return a clone of this component, used in prototype pattern
     */
    virtual Component* cloneEmpty() const;
    
    void initWithJson(const std::string& json);
};

NS_XD_END

#endif /* Component_hpp */
