#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetWindowShape(500, 500);
    ofBackground(0, 0, 0);
    
}

//--------------------------------------------------------------
void testApp::update(){

}

void drawlines(){
    ofRotate(100);
    ofLine(20, 20, 100, 100);
}

void drawlines2(){
    ofTranslate(0, 0);
    ofRotate(50);
    ofLine(0, 0, 100, 100);
}

void drawCricle(){
    ofTranslate(0, 0);
    ofRotate(5);
    ofLine(10, 10, 50, 50);
}

void drawBigCricle(){
    ofTranslate(0, 0);
    ofRotate(5);
    ofLine(100, 100, 500, 500);
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(255, 95, 150);
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
//frist one
    for(int i=0; i<60; i++){
        drawlines();
    }
    
// second
    ofSetColor(95, 150, 255);
    for (int a=0; a<100; a+=5) {
        drawlines2();
    }
// Green
    ofSetColor(0, 255, 95);
    for (int a=0; a<500; a+=5) {
        drawCricle();
    }
//White
    ofSetColor(255, 255, 255);
    for (int a=0; a<500; a+=5) {
        drawBigCricle();
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
