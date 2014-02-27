#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    rays = 1000;
    
    ofDisableSmoothing();
    degreeShift = 45;
    start = false;
    ofBackground(255);

}

//--------------------------------------------------------------
void testApp::update(){
    
    if (start) {
    
    degreeShift = ofRandom(-90,90);
    degreeRotate = ofRandom(0,360);
        
    }


}

//--------------------------------------------------------------
void testApp::draw(){
    
    if (degreeShift > -90) {
        
        for (int i=0;i<1000;i++) {
            
            
            primaryRotatorDisk(000, 200);
            

            secondaryRotatorDisk(200, 500);
            
        }

    }
    
    for (int i=0;i<500;i++) {
        
        tertiaryRotatorDisk(255);
        
    }
    
}

void testApp::primaryRotatorDisk(int c, int p) {
    ofRotateX(degreeShift);
    ofSetColor(c);
    ofFill();
    ofRect(ofGetHeight()/2+100, ofGetHeight()/4, ofGetWidth() - ofGetWidth()/2 + p, ofGetHeight() - ofGetHeight()/2);
    }

void testApp::secondaryRotatorDisk(int c, int p) {
    ofRotateX(degreeShift);
    ofSetColor(c);
    ofFill();
    ofRect(ofGetWidth()-100,ofGetHeight()/4, ofGetWidth() - ofGetWidth()/2 - p, ofGetHeight() - ofGetHeight()/4);
    }

void testApp::tertiaryRotatorDisk(int c) {
    ofRotateX(degreeShift);
    ofSetColor(c);
    ofFill();
    ofLine(ofGetWidth(),ofGetHeight(),0,ofGetHeight());
    }


//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    if (key == 's'){
        start=!start;
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
