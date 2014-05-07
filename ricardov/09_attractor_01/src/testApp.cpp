#include "testApp.h"
//THIS A RAMSEY NASSER EXAMPLE

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0, 0, 0);
}

//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){
    int n = 10000;
    
    float a = 0 + sin(ofGetElapsedTimef());
    float b = -2.3;
    float c = 2.4;
    float d = -2.1;
    
    float x0, y0, x1, y1 = 0;
    x0 = y0 = x1 = y1 = 0;
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofScale(50, 50, 50);
    
    for (int i=0; i<n; i++) {
        x1 = sin(a * y0) - cos(b * x0);
        y1 = sin(c * x0) - cos(d * y0);
        
        ofLine(x1, y1, x1+.001, y1);
        
        x0 = x1;
        y0 = y1;
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