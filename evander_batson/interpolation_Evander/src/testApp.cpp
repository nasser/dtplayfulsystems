#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255,255,255);
    ofSetColor(0,0,0);
    ofEnableAntiAliasing();
    ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void testApp::update(){
    
}

void testApp::wave(float a, float b){
    
    ofSetColor(0x000000);
	ofNoFill();
	ofBeginShape();
	for(int x=0; x<ofGetWidth(); x+=1) {
		ofCurveVertex(x, ofGetHeight()/2 + ofGetHeight() * sin(x*a + ofGetFrameNum() * b));
	}
	ofEndShape(false);
    
}


//--------------------------------------------------------------
void testApp::draw(){
    
    wave(0.01, 0.02);
    
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