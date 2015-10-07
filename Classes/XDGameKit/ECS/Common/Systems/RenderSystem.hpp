//
//  RenderSystem.hpp
//  XDGameKit
//
//  Created by VuTT5 on 10/6/15.
//
//

#ifndef RenderSystem_hpp
#define RenderSystem_hpp

#include <stdio.h>
#include "XDGameKit.h"

NS_XD_BEGIN

class RenderSystem: public System {
    
public:
    RenderSystem();
    
protected:
    virtual System* cloneEmpty() const override;
    
    virtual void onInit() override;
    virtual void onAttached() override;
    virtual void onDeattached() override;
    virtual void update(float dt) override;
    virtual void onComponentChanged() override;
    
    RenderComponent *_node;
};

NS_XD_END

#endif /* RenderSystem_hpp */
