//
//  ECSManager.cpp
//  GiatXeng
//
//  Created by VuTT5 on 10/1/15.
//
//

#include "ECSManager.hpp"
#include "Entity.hpp"
#include "Component.hpp"
#include "System.hpp"
#include "cocostudio/CocoStudio.h"

USING_NS_XD;
USING_NS_CC;

ECSManager::ECSManager() {
    _entities.reserve(50);
    _lowestUnassignedEntityId = 1;
    
    _componentFactory = ECSFactory<Component*>::create();
    _componentFactory->retain();
    _systemFactory = ECSFactory<System*>::create();
    _systemFactory->retain();
    
    _componentFactory->registerObject(RenderComponent::TYPE, new RenderComponent());
}

ECSManager::~ECSManager() {
    // remove all game objects
    for (auto iter = _entities.begin(); iter != _entities.end(); iter++) {
        (*iter)->release();
    }
    _entities.clear();

    // TODO we must call System factory and component factory to remove all objects here
    _componentFactory->release();
    _systemFactory->release();
}

Entity* ECSManager::createEntity() {
    Entity* entity = Entity::createWithId(generateNewEntityId());
    
    // add entity to _beAdding array, to make sure it'll be added after updating in the next time
    _beAdding.pushBack(entity);
    
    return entity;
}

Entity* ECSManager::createEntity(const std::string& filename) {
    
    __String str = __String(filename);
    __Array *arr = str.componentsSeparatedByString(".");
    __String *extension = (__String*)arr->getLastObject();
    
    if (extension->compare("scb")) {
        Node *node = CSLoader::createNode(filename);
        
        if (node != nullptr) {
            Entity* entity = createEntity();
            
            Component *component = _componentFactory->getObject(node->getName());
            if (component) {
                addComponentToEntity(component, entity);
            }
            
//            for (int i=0; i<node->getChildrenCount(); i++) {
//                Node *child = node->getChildren().at(i);
//                
//                Component *component = _componentFactory->getObject(child->getName());
//                if (component) {
//                    addComponentToEntity(component, entity);
//                }
//                
//                CCLOG("%s", child->getName().c_str());
//            }
            
            return entity;
        }
    } else {
        // maybe it's a json file
        // TODO: for now, I'm not implemented it yet
    }
    
    return nullptr;
}

void ECSManager::removeEntity(Entity* entity) {
    if (entity != nullptr) {
        entity->setIsMoving(true);
        
        // do not remove it immediately, let's put it into _beRemoving, and system will be removed it in the next time
        _beRemoving.pushBack(entity);
    }
}

void ECSManager::addComponentToEntity(Component* component, Entity* entity) {
    entity->getComponentMap().insert(std::make_pair(component->getType(), component));
}

void ECSManager::removeComponentFromEntity(const ecsId id, Entity* entity) {
    
}

void ECSManager::removeComponentFromEntity(Component *component, Entity* entity) {
    
}

void ECSManager::removeAllComponent(Entity* entity) {
    
}

void ECSManager::update(float dt) {
    // add game objects
    addingEntities();
    
    // update game objects
    for (auto iterEntity = _entities.begin(); iterEntity != _entities.end(); ++iterEntity) {
        Entity* entity = *iterEntity;
        if (entity->getIsMoving()) {
            break;
        } else if (entity->getSystems().empty() == false) {
            for (auto iterSystem = entity->getSystems().begin(); iterSystem != entity->getSystems().end(); ++iterSystem) {
                if (iterSystem->second->getStatus() != SystemStatus_Free) {
                    iterSystem->second->update(dt);
                    
                    if (entity->getIsMoving()) {
                        break;
                    }
                }
            }
        }
    }
    
    // remove game objects
    removingEntities();
}

void ECSManager::registerSystem(System* system) {
    
}

void ECSManager::unregisterSystem(System *system) {
    
}

void ECSManager::addingEntities() {
    
}

void ECSManager::removingEntities() {
    if (_beRemoving.empty())
        return;
    
    _handing = _beRemoving;
    
    // clean data
    for (auto iterEntity = _handing.begin(); iterEntity!=_handing.end(); ++iterEntity) {
        Entity *entity = *iterEntity;
        
        // Remove fo
    }
}

bool ECSManager::contants(ecsId id) {
    return false;
}

ecsId ECSManager::generateNewEntityId() {
    if (_lowestUnassignedEntityId < UINT32_MAX) {
        return _lowestUnassignedEntityId++;
    }
    
    return 0;
}