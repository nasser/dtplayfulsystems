#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetBackgroundAuto(true);
}

//--------------------------------------------------------------
void testApp::update(){

}

float testApp::xCoordinateOnLine(float t, float x1, float x2) {
    t = ofClamp(t, 0, 1);
    
    return (x2 - x1) * t + x1;
}

float testApp::yCoordinateOnLine(float t, float y1, float y2) {
    t = ofClamp(t, 0, 1);
    
    return (y2 - y1) * t + y1;
}

ofPoint testApp::pointOnLine(float t, ofPoint p1, ofPoint p2) {
    t = ofClamp(t, 0, 1);
    
    return (p2 - p1) * t + p1;
}

//--------------------------------------------------------------
void testApp::draw(){
    float mouseX01 = ofClamp((float)mouseX / ofGetWidth(), 0, 1);
    cout << mouseX01 << endl;
    
    int minimumGrey = 128;
    int maximumGrey = 220;
    
    float g = (maximumGrey - minimumGrey) * mouseX01 + minimumGrey;
    
    // ofBackground(g, g, g);

    // float circleX = xCoordinateOnLine(mouseX01, 50, 350);
    // float circleY = yCoordinateOnLine(mouseX01, 100, 300);
    
    // ofCircle(circleX, circleY, 2);
    
    ofPoint circleCenter = pointOnLine(mouseX01, ofPoint(50, 100), ofPoint(350, 300));
    ofCircle(circleCenter, 2);
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
