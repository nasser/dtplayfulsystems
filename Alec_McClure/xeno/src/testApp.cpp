#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    circleCenter.set(ofGetWidth()/2, ofGetHeight()/2);
    destination.set(ofGetWidth() - 50, ofGetHeight() /2);
    ofSetBackgroundAuto(false);
    ofSetColor(255,255,255,100);
}

//--------------------------------------------------------------
void testApp::update(){
    circleCenter.interpolate(destination, 0.25);




}

//--------------------------------------------------------------
void testApp::draw(){
    ofCircle(circleCenter, 10);
    ofCircle(destination, 5);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    circleCenter.set(x, y);

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    circleCenter.set(x, y);

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
