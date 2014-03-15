#include "testApp.h"

void testApp:: drawLines(float space, float x1, float y1, float x2, float y2){
    ofLine(x1, y1, x2, y2);
    ofLine(x1, y1+ space, x2, y2+space);
    ofCircle(x1, y1, space);
    
}

void testApp::drawTriangles(float space, float x1, float y1, float x2, float y2, float x3, float y3){
    ofSetColor(255); 
    ofTriangle(x1, y1, x2, y2, x3, y3);
    //ofTriangle(x1, y1+space, x2, y2+space, x3, y3+space);

}

//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    drawLines(30, 0, 0, 100, 100);
    drawTriangles(100, ofGetWidth()/2, ofGetHeight()/2 , ofGetWidth()/2, ofGetHeight()*ofGetElapsedTimef(), 30, 30*ofGetElapsedTimef());
    
     ofDrawBitmapString(ofToString(ofGetFrameRate())+"fps", 50, 15);

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
