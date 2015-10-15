//
//  XDMacros.h
//  XDGameKit
//
//  Created by VuTT5 on 9/29/15.
//
//

#ifndef XDMacros_h
#define XDMacros_h

#include "cocos2d.h"
#include <vector>
#include <map>
#include "json/document.h"

#define NS_XD_BEGIN                 namespace XD {
#define NS_XD_END                   }
#define USING_NS_XD                 using namespace XD


NS_XD_BEGIN

class System;
class Component;

typedef unsigned int ecsId;
typedef std::map<std::string, System*> SystemMap;
typedef std::map<std::string, Component*> ComponentMap;

enum EntityStatus {
    EntityStatus_Unload = 0,    // entity is not managed yet
    EntityStatus_Normal,        // entity is loaded, and can be updated
    EntityStatus_Removed,       // entity is removed from manager
    EntityStatus_Destroy        // entity is to be delete
};

NS_XD_END

#endif /* XDMacros_h */
