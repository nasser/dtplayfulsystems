#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofBackground(255, 255, 255);
    ofSetBackgroundAuto(false);
    
}

//--------------------------------------------------------------
void testApp::update(){

}


//--------------------------------------------------------------

ofPoint testApp::pointOnLine(ofPoint from, ofPoint to, <#float t#>) {
    return ((1-t)*from+(t)*to);
}

//--------------------------------------------------------------
void testApp::draw(){
    
    /*

    //type
    
    string title = "Creative Coding";
    
    ofDrawBitmapString(title, ofGetWidth()/2 - (title.length()*8)/2, 30);
    
    string title1 = "PONG";
    
    ofDrawBitmapString(title1 ,ofGetWidth()/2 - (title1.length()*8)/2, 45);
    
    string title2 = "Midterm";
    
    ofDrawBitmapString(title2, ofGetWidth()/2- (title2.length()*8)/2, 60);
    
    string title3 = "Sandrofredericoz";
    
    ofDrawBitmapString(title3,ofGetWidth()/2-(title3.length()*8)/2, 75);
    
    */
     
     // Tennis field
    
    ofPoint p1, p2;
    
    
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
