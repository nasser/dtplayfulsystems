#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
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
    
    if (degreeShift > -50) {
        
        for (int i=0;i<1000;i++) {
            
            ofRotateX(degreeShift);
            ofSetColor(000);
            ofFill();
            ofRect(ofGetHeight()/4+200, ofGetHeight()/4, ofGetWidth() - ofGetWidth()/4 + 200, ofGetHeight() - ofGetHeight()/4);
            
            ofRotateX(degreeShift);
            ofSetColor(255);
            ofFill();
            ofRect(ofGetWidth()-500,ofGetHeight()/4, ofGetWidth() - ofGetWidth()/4 -500, ofGetHeight() - ofGetHeight()/4);
            
        }

    }
    
    for (int i=0;i<1000;i++) {
        
        ofRotateX(degreeShift);
        ofSetColor(255);
        ofFill();
        ofLine(ofGetWidth(),ofGetHeight(),0,ofGetHeight());
        
    }
    
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
