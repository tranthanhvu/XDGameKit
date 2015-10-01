//
//  Entity.hpp
//  GiatXeng
//
//  Created by VuTT5 on 9/30/15.
//
//

#ifndef Entity_hpp
#define Entity_hpp

#include <stdio.h>
#include "XDGameKit.h"

NS_XD_BEGIN

class ECSManager;

/// represent an entity in game
class Entity: public cocos2d::Ref {
    
private:
    Entity();
    virtual ~Entity();
    
    static Entity* createWithId(const ecsId id);
    
    bool initWithID(const ecsId id);
    
public:
    void removeComponent(const ecsId id);
    void removeAllComponents();
    void componentChanged();
    
    Component* getComponentByType(const std::string& type);
    cocos2d::Node* getNode();
    
    /**
     *  get parent's entity
     *
     *  @return a owner entity
     */
    Entity* getParent();
    
    /**
     *  send an event to all components regarding this entity
     *
     *  @param eventName is a name of event :D
     */
    void sendEvent(const std::string& eventName); // many system have event mechanism, I dont clear for now. Let's leave it
    
    /**
     *  to compare two entities
     *
     *  @param target is  another entity
     *
     *  @return return true, it means we have same entity
     */
    bool equals(const Entity& target) const;
    
    CC_SYNTHESIZE(ecsId, _id, Id);
    
    CC_SYNTHESIZE(EntityStatus, _status, Status);
    CC_SYNTHESIZE(ComponentMap, _component, ComponentMap); // It should be a Map, Because we can retrieve it late
    CC_SYNTHESIZE(SystemMap, _systems, Systems);
    CC_SYNTHESIZE(bool, _isMoving, IsMoving); // this flag means Object is moving into removing stack, and it'll be removed.
    
    friend ECSManager;
};

NS_XD_END


#endif /* Entity_hpp */
