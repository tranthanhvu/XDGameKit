//
//  XDGameKit.h
//  GiatXeng
//
//  Created by VuTT5 on 9/29/15.
//
//

#ifndef XDGameKit_h
#define XDGameKit_h

/*
 Unlike high-level game engines such as SpriteKit, Cocos2dx... this project is not involved in 
 animating and rendering visual content. Instead, you use it to develop your gameplay mechanics 
 and to design modular, scalable game architecture with minimal effort.
 I used some codes from genius-x project refering GameplayKit, Omiga engine to create a this project.
 - Entity Component architecture
 - State machine system
 - randomization utilities
 (minmax strategist, pathfinding, agent simulation, rule systems)
 */

#include "XDMacros.h"
#include "Component.hpp"
#include "System.hpp"
#include "Entity.hpp"
#include "ECSManager.hpp"
#include "RenderComponent.hpp"

#include "GameSystem.hpp"
#include "GameScene.hpp"
#include "SceneManager.hpp"
#include "GameLayer.hpp"

#define kComponentRenderArmature "CCArmature"
#define kComponentRenderComponent "GUIComponent"
#define kComponentRenderTileMap "CCTMXTileMap"
#define kComponentRenderParticle "CCParticleSystemQuad"
#define kComponentAudio   "CCComAudio"
#define kComponentAudioBackground "CCBackgroundAudio"
#define kComponentAttribute "CCComAttribute"


#endif /* XDGameKit_h */
