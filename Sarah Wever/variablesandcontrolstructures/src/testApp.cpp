#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------
void testApp::update(){
    
    theColor.r += 1;
    x+=0.1;

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackground(0);
    ofSetColor(ofColor::peachPuff);
    ofRect(300,200, 200, 200);
    
    ofColor someColor;
    someColor.r = 255;
    someColor.g = 89;
    someColor.b = 189;
    ofSetColor(theColor);
    
    
    ofRect(200+x,90,49,80);
    for ( int i = 0; i<x; i++) {
        ofLine(200+i, 0, 200+i, 500);
    }
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    theColor.g = 255;

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    theColor.g = 0;

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
