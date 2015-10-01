//
//  TagManager.hpp
//  GiatXeng
//
//  Created by VuTT5 on 9/30/15.
//
//

#ifndef TagManager_hpp
#define TagManager_hpp

#include <stdio.h>
#include "XDMacros.h"

NS_XD_BEGIN

class Entity;

// If you need to tag any entiy, use this. A typical usage would be to tag entities
// such as "PLAYER", "BOSS" or something that is very unique.
class TagManager: cocos2d::Ref {
private:
    cocos2d::Map<std::string, Entity*> _tagByEntity;
    
public:
    TagManager();
    
    void subscribe(const std::string tag, Entity *entity);
    void unSubscribe(const std::string tag);
    bool isSubscribe(const std::string tag);
    Entity* getEntity(const std::string tag);
    void remove(Entity *entity);
    
};

NS_XD_END

#endif /* TagManager_hpp */
