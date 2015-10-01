//
//  RenderComponent.hpp
//  GiatXeng
//
//  Created by VuTT5 on 10/1/15.
//
//

#ifndef RenderComponent_hpp
#define RenderComponent_hpp

#include <stdio.h>
#include "XDGameKit.h"

NS_XD_BEGIN

class RenderComponent: public Component {
public:
    RenderComponent();
    virtual ~RenderComponent();
    
    Node* getNodeByName(const std::string& name) const;
    
    CC_SYNTHESIZE(Node*, _node, Node);
};

NS_XD_END

#endif /* RenderComponent_hpp */
