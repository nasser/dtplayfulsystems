#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetWindowShape(500, 500);
    ofBackground(0, 0, 0);
    
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(255, 95, 150);
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
//frist one
    for(int i=0; i<60; i++){
        ofRotate(80);
        ofLine(i, 100+i, 5i, 100-i);
    }
    
// second
    ofSetColor(95, 150, 255);
    for (int a=0; a<200; a+=5) {
        ofRotate(5);
        ofLine(20+a, 0, 20-a, 0);
    }
// Green
    ofSetColor(0, 255, 95);
    for (int a=0; a<500; a+=10) {
        ofRotate(5);
        ofLine(10, 5+a, a, 5-a);
    }
//White
    ofSetColor(255, 255, 255);
    for (int a=0; a<200; a+=5) {
        ofRotate(2);
        ofLine(10, a, 10, -a);
    }
    
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
