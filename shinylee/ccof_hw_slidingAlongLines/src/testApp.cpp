#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(50);
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
}

//--------------------------------------------------------------
void testApp::update(){
    
}

void testApp::draw(){
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    ofSetColor(200);
    
    int n =20000;
    for(int i = 0; i< n; i=i+2){
        ofRotateZ(360.f / n);
        
    float pos = sin(ofGetElapsedTimef()*((float)(i)/ n))*ofGetHeight()/2;
    
    ofLine(pos*0.8, 0, pos*0.8, 2); //ofCircle(pos, 0, 2);

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
