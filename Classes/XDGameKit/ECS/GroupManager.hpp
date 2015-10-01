//
//  GroupManager.hpp
//  GiatXeng
//
//  Created by VuTT5 on 9/30/15.
//
//

#ifndef GroupManager_hpp
#define GroupManager_hpp

#include <stdio.h>
#include "XDMacros.h"

NS_XD_BEGIN

class Entity;

// If you need to group your entities together, e.g tanks going into "units" group or explosions into "effects",
// then use this manager. You must retrieve it using world instance.
class GroupManager: public cocos2d::Ref {
private:
    cocos2d::Vector<Entity*> _emptyBag;
    std::string emptyString;
    std::vector<std::string> _groupByEntity;
    cocos2d::Map<std::string, cocos2d::Vector<cocos2d::Vector<Entity*>>> _entitiesByGroup;
    
public:
    GroupManager();
    ~GroupManager();
    
    void set(std::string group, Entity *entity);
    void remove(Entity *entity);
    std::string getGroupOf(Entity *entity);
    bool isGrouped(Entity *entity);
    bool isInGroup(std::string group, Entity* entity);
    cocos2d::Vector<Entity*> getEntities(std::string group);
};

NS_XD_END

#endif /* GroupManager_hpp */
