#include "ofxShelfPack.h"

void ofxShelfPack::setup(ofRectangle* container_ref){
    setup(container_ref, false);
}

void ofxShelfPack::setup(ofRectangle* container_ref, bool resize){
    ShelfPack::ShelfPackOptions options;
    if(resize){
        options.autoResize = true;
    }else{
        options.autoResize = false;
    }
    sprite = std::make_unique<ShelfPack>(container_ref->getWidth(), container_ref->getHeight(), options);
    container = container_ref;
}

bool ofxShelfPack::pack(ofRectangle* item_ref){
    Bin* allocation = sprite->packOne(rectangles.size(), item_ref->getWidth(), item_ref->getHeight());
    
    // return whether packing was successful
    if(allocation){
        rectangles.push_back(item_ref);
        return true;
    }else{
        return false;
    }
}

unsigned long ofxShelfPack::packMany(vector<ofRectangle>* items){
    int count = 0;
    for (auto& item : *items) {
        if (item.getWidth() > 0 && item.getHeight() > 0) {
            if(pack(&item)){
                count ++;
            }else{
                continue;
            }
        }
    }
    
    update();
    return count;
}

void ofxShelfPack::update(){
    update(true);
}

void ofxShelfPack::update(bool shrink){
    if(shrink){
        sprite->shrink();
    }
    container->setWidth(sprite->width());
    container->setHeight(sprite->height());
    
    for(int i = 0; i < rectangles.size(); i++){
        Bin* currentBin = sprite->getBin(i);
        rectangles[i]->setX(currentBin->x);
        rectangles[i]->setY(currentBin->y);
        rectangles[i]->setWidth(currentBin->w);
        rectangles[i]->setHeight(currentBin->h);
    }
}

void ofxShelfPack::clear(){
    for(int i = 0; i < rectangles.size(); i++){
        delete rectangles[i];
    }
    rectangles.clear();
    delete container;
    sprite->clear();
}

