#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
  ofSetBackgroundAuto(false);
}


ofPoint testApp::drawCurve(float t){
    ofPoint center;
    center.x = 80* 5 * sin(t*PI/2);
    center.y= 80* 4 * cos(t);
    
    return center;

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    float t=ofGetElapsedTimef()/2;
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofPoint circleCenter= drawCurve(t);
    ofCircle(circleCenter, 5);
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
