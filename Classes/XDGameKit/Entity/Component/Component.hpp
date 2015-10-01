//
//  Component.hpp
//  GiatXeng
//
//  Created by VuTT5 on 9/23/15.
//
//

#ifndef Component_hpp
#define Component_hpp

#include "RTTI.hpp"

class Component: public cocos2d::Ref {
    DECLARE_RTTI_ROOT(Component);
    
public:
    Component();
    virtual ~Component();
    
    virtual Component* Clone() const = 0;
    
    virtual void OnCreate();
    virtual void OnAttached();
    virtual void OnFinalize();
    virtual void OnRemove(bool willDel);
    virtual void OnRelease();
    virtual void OnDetached();
    virtual void OnDestroy();
    // called when this component's entity is update
    virtual void OnUpdate(float delta);
    virtual bool OnUpdateData();
    

    
};

#endif /* Component_hpp */
