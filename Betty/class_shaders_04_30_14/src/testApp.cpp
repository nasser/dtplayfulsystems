#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    shader.load("","wolf.frag");
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    float w, h;
    w = ofGetWidth();
    h = ofGetHeight();
    ofBackground(0, 0, 0);
    ofSetColor(255);
    
    shader.begin();
    shader.setUniform3f("iResolution", w, h, 0);
    shader.setUniform2f("iMouse", w, h);
    shader.setUniform1f("iGlobalTime", ofGetMouseX()*0.01);
    
    ofRect(0, 0, w, h);
    ofCircle(mouseX, mouseY, 100);
    shader.end();
    
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
