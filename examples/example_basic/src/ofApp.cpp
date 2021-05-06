#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    
    container.set(0, 0, ofGetWidth(), ofGetHeight());
    packer.setup(&container);
    
    
    rect1.set(0,0, 45,45);
    rect2.set(0, 0, ofGetWidth(), 50);
    rect3.set(0,0, 130,45);
    rect4.set(0,0, 45,34);
    rect5.set(0,0, 23,52);
    
    packer.pack(&rect1);
    packer.pack(&rect2);
    packer.pack(&rect3);
    packer.pack(&rect4);
    packer.pack(&rect5);
    
    packer.update();
    
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSeedRandom(100);
    
    ofSetColor(255, 255, 255);
    ofDrawRectangle(container);
    
    ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
    ofDrawRectangle(rect1);
    
    ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
    ofDrawRectangle(rect2);
    
    ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
    ofDrawRectangle(rect3);
    
    ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
    ofDrawRectangle(rect4);
    
    ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
    ofDrawRectangle(rect5);
}
