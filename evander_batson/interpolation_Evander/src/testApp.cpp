#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255,255,255);
    ofSetColor(0,0,0);
    ofEnableAntiAliasing();
    ofSetBackgroundAuto(false);
    
    speed = 2;
    twirl = 0;
    
}

//--------------------------------------------------------------
void testApp::update(){
    
}

void testApp::wave(float a, float b){
    
    ofRotate(rotation, 1, twirl, twirl);
    
    ofSetColor(0x000000);
	ofNoFill();
	ofBeginShape();
	for(int x=0; x<ofGetWidth(); x+=1) {
		ofCurveVertex(x, ofGetHeight()/2 + ofGetHeight() * sin(x * a + ofGetFrameNum() * (b * speed)));
	}
	ofEndShape(false);

}


//--------------------------------------------------------------
void testApp::draw(){
    
    wave(0.01, 0.02);
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    if (key == 'a') {
        speed = -3;
    }
    
    if (key == 's') {
        speed = -2;
    }
    
    if (key == 'd') {
        speed = -1;
    }
    
    if (key == 'f') {
        speed = 0;
    }
    
    if (key == 'g') {
        speed = 1;
    }
    
    if (key == 'h') {
        speed = 2;
    }
    
    if (key == 'j') {
        speed = 3;
    }
    
    if (key == 'r') {
        ofBackground(255,255,255);
    }
    
    if (key == 'q') {
        ofBackground(255,255,255);
        rotation+=10;
        twirl = ofRandom(0,10);
    }
    
    if (key == 'w') {
        ofBackground(255,255,255);
        rotation-=10;
        twirl = ofRandom(0,10);
    }
    
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