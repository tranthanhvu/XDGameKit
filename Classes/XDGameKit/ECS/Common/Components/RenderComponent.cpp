//
//  RenderComponent.cpp
//  GiatXeng
//
//  Created by VuTT5 on 10/1/15.
//
//

#include "RenderComponent.hpp"

USING_NS_XD;

std::string RenderComponent::TYPE = "RenderComponent";

RenderComponent::RenderComponent(): Component::Component(TYPE) {
    
}

RenderComponent::~RenderComponent() {
    
}

Node* RenderComponent::getNodeByName(const std::string& name) {
    return getNodeByName(_node, name);
}

Node* RenderComponent::getNodeByName(Node* node, const std::string& name) {
    if (node->getName() == name) {
        return node;
    } else {
        // to attempt to get node from childrens.
        for (int i=0; i<node->getChildrenCount(); ++i) {
            Node* temp = node->getChildByName(name);
            if (temp != nullptr) {
                return temp;
            }
        }
        
        return nullptr;
    }
}