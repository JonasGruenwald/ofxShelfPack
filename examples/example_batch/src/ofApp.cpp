#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);    
    container.set(0, 0, ofGetWidth(), ofGetHeight());
    packer.setup(&container, true);
    
    for(int i = 0; i < targetCount; i++){
        items.push_back(ofRectangle(
                                    0,
                                    0,
                                    50 + ofRandom(-variance / 2, variance / 2),
                                    50 + ofRandom(-variance / 2, variance / 2)
                                    ));
    }
    
    int packedCount = packer.packMany(&items);
    
    cout << "Packed " << packedCount << " rectangles." << endl;
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSeedRandom(100);
    ofSetColor(255, 255, 255);
    ofDrawRectangle(container);
    for(int i = 0; i < items.size(); i++){
        ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
        ofDrawRectangle(items[i]);
    }
}
