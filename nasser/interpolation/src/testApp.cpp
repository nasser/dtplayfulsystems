#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void testApp::update(){

}

ofPoint testApp::pointOnLine(ofPoint from, ofPoint to, float t) {
    return (1 - t) * from + t * to;
}

//--------------------------------------------------------------
void testApp::draw(){
    ofPoint p1, p2;
    
    p1.interpolate(p2, 0.5);
    
    p1.set(500 + sin(ofGetElapsedTimef()) * 200, 500);
    p2.set(450, 600);
    
    
    ofPoint a = pointOnLine(p1, p2, sin(ofGetElapsedTimef()));
    ofPoint b = pointOnLine(p1, p2, 0.3);
    ofPoint c = pointOnLine(p1, p2, 0.4);
    ofPoint d = pointOnLine(p1, p2, 0.5);
    ofPoint e = pointOnLine(p1, p2, 0.6);
    
    /*
    ofSetColor(255, 0, 0);
    ofCircle(p1, 5);

    ofSetColor(0, 255, 0);
    ofCircle(p2, 5);
    
    ofSetColor(255, 255, 255);
    ofLine(p1, p2);
    */
    
    ofSetColor(0, 0, 255);
    ofCircle(a, 10);
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
