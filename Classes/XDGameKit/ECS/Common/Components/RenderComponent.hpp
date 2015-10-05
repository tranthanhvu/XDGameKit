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

USING_NS_CC;
NS_XD_BEGIN

class RenderComponent: public Component {
public:
    static std::string TYPE;
    RenderComponent();
    virtual ~RenderComponent();
    
    Node* getNodeByName(const std::string& name);
    
    CC_SYNTHESIZE(Node*, _node, Node);
    
private:
    // use recursion formula
    Node* getNodeByName(Node* node, const std::string& name);
};

NS_XD_END

#endif /* RenderComponent_hpp */
