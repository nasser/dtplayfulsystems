#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0, 0, 0);
    ofSetColor(255, 128, 0);
    ofLine(100,100,200,200);
    ofSetColor(0, 128, 255);
    ofLine(500, 500, 100, 100);
    
    float redValue = 10.5;
    int redValueAsInt = 12; //Range of an int -2^31...2^31
    string name = "DT Playful Systems";
    
    ofColor someColor;
    someColor.r = 255;
    someColor.g = 0;
    someColor.b = 128;
    
    //ofSetColor(someColor);
    
    ofRect(200 + ofGetElapsedTimef(), 200, 600, 400);
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
