//
//  MyWidgetReader.hpp
//  DoraemonAdventure
//
//  Created by yoyo on 10/10/15.
//
//

#ifndef MyWidgetReader_hpp
#define MyWidgetReader_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "cocostudio/CocosStudioExport.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

class MyWidgetReader : public cocostudio::NodeReader {
    
public:
    MyWidgetReader() {};
    ~MyWidgetReader() {};
    
    static MyWidgetReader* getInstance();
    static void purge();
    cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
};

#endif /* MyWidgetReader_hpp */
