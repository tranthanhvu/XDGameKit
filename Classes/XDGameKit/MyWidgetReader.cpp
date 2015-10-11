//
//  MyWidgetReader.cpp
//  DoraemonAdventure
//
//  Created by yoyo on 10/10/15.
//
//

#include "MyWidgetReader.hpp"
#include "MyWidget.hpp"

USING_NS_CC;
using namespace flatbuffers;

static MyWidgetReader* _instanceWidgetReader = nullptr;

MyWidgetReader* MyWidgetReader::getInstance() {
    if (!_instanceWidgetReader) {
        _instanceWidgetReader = new MyWidgetReader();
    }
    
    return _instanceWidgetReader;
}

void MyWidgetReader::purge() {
    CC_SAFE_DELETE(_instanceWidgetReader);
}

Node* MyWidgetReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions) {
    MyWidget *node = MyWidget::create();
    
    setPropsWithFlatBuffers(node, nodeOptions);
    
    return node;
}