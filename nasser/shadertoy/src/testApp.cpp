#include "testApp.h"
//--------------------------------------------------------------
void testApp::setup(){
    shader.load("","wolf.frag");
    ofSetFrameRate(30);
    ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void testApp::draw(){
    float w, h;
    w = ofGetWidth();
    h = ofGetHeight();
    ofBackground(0, 0, 0);
    ofSetColor(255, 255, 255, 8);
    
    shader.begin();
    shader.setUniform3f("iResolution",w,h,0);
    shader.setUniform2f("iMouse",ofGetMouseX(),ofGetMouseY());
    shader.setUniform1f("iGlobalTime", ofGetElapsedTimef());
    
    for(int i=0; i<50; i++) {
        ofCircle(ofGetMouseX(), ofGetMouseY(), 200 - i*10);
    }
    
    ofCircle(100, 300, 10);
    ofCircle(120, 400, 50);
    shader.end();
}

//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}