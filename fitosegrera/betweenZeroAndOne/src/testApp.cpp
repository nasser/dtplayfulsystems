#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void testApp::update(){

}

float testApp::xCoordinateOnLine(float x1, float x2){
    
    
    return (x2 - x1) * x1;
}

float testApp::yCoordinateOnLine(float y1, float y2){
    
    
    return (y2 - y1) * y1;
}

//--------------------------------------------------------------
void testApp::draw(){
    float mouseX01 = ofClamp((float)mouseX / ofGetWidth(), 0, 1);
    cout<< mouseX01 <<endl;
    
    int minimumGrey = 128;
    int maximumGrey = 200;
    
    float g = (maximumGrey - minimumGrey) * mouseX01 + minimumGrey;
    
    //ofBackground(g, g, g);
    
    //float circleX = ofMap(mouseX, 0, ofGetWidth(), 50, 350, true);
    //float circleY = ofMap(mouseX, 0, ofGetWidth(), 100, 300 + sin(ofGetElapsedTimef() * 10) * 100, true);
    
    float circleX = xCoordinateOnLine(0, 0 + ofGetElapsedTimef() * 10);
    float circleY = yCoordinateOnLine(ofGetHeight(), 0) + sin(ofGetElapsedTimef() * 10) * 100;
    
    
    ofCircle(circleX, circleY, 1);
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
