#pragma once

#include "ofMain.h"
#include "ofxShelfPack.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    ofxShelfPack packer;
    
    ofRectangle container;
    
    ofRectangle rect1;
    ofRectangle rect2;
    ofRectangle rect3;
    ofRectangle rect4;
    ofRectangle rect5;
};
