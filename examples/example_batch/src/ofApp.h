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
    int targetCount = 250;
    int variance = 40;
    vector<ofRectangle> items;

};
