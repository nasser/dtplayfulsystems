#include "testApp.h"

void testApp::drawRotLine(float x, float y, float angle, float length){
    
    float outerX = x + cos(ofDegToRad(angle)) *length;
    float outerY = y + sin(ofDegToRad(angle)) *length;
    
    ofLine(x, y, outerX, outerY); 
    
}


//--------------------------------------------------------------
void testApp::setup(){
    ofSetColor(255);

    ofBackground(0);

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    drawRotLine(ofGetWidth()/2, ofGetHeight()/2, 45 + ofGetElapsedTimef() * 5, ofGetHeight());
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
