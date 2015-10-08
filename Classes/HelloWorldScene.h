#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "XDGameKit.h"

USING_NS_XD;

class HelloWorld : public GameScene
{
public:
    virtual bool init();
    virtual void configureGUIScene();
    
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
