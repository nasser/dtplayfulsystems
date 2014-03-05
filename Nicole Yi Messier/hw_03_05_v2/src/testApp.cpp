#include "testApp.h"


//--------------------------------------------------------------
ofPoint testApp::pointOnLine(float t, ofPoint p1, ofPoint p2){
    ofClamp(t, 0, 1);
    
    return((p2-p1)*t+p1);
    
}

//--------------------------------------------------------------
void testApp::setup(){
    ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void testApp::update(){
    ofPoint from1, to1, from2, to2, from3, to3, from4, to4, circleCenter1, circleCenter2, circleCenter3, circleCenter4;
    float m = 10;
    
    from1.set(0,0);
    to1.set(ofGetWidth(), 0);
    
    from2.set(0, ofGetWindowHeight());
    to2.set(ofGetWidth(), ofGetHeight());
    
    //ofLine(from1, to1);
    
    from3 = pointOnLine(ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1), from1, to1);
    to3.set(ofGetWidth()/2, ofGetHeight()/2);
    
    from4 = pointOnLine(ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1), from2, to2);
    to4.set(ofGetWidth()/2, ofGetHeight()/2);
    
    
    
    circleCenter1 = pointOnLine(ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1), from3, to3);
    circleCenter2 = pointOnLine(ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1), from4, to4);
    circleCenter3 = pointOnLine(ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1), to3, from3);
    circleCenter4 = pointOnLine(ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1), to4, from4);
    

    ofSetColor(0, 0, 0);
    ofCircle(circleCenter1, 10);
    ofCircle(circleCenter2, 10);
    ofCircle(circleCenter3, 10);
    ofCircle(circleCenter4, 10);
    
    ofSetColor(175, 238, 238);
    ofLine(from3, to3);
    ofLine(from4, to4);

}

//--------------------------------------------------------------
void testApp::draw(){

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
