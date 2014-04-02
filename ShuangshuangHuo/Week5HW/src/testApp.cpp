#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
 //ofBackground(0,0,0);
    ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void testApp::update(){

}


//--------------------------------------------------------------
void testApp::draw(){
    
  ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    t=ofGetElapsedTimef()/2;
    x =  80* 5 * sin(t*PI/2);
    y =  80* 4 * cos(t);
    ofCircle(x, y, 5);

}

//------------------------------------------------------------
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
