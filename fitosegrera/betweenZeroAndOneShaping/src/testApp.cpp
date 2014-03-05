#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------
void testApp::update(){

}

ofPoint testApp::pointOnLine(float t, ofPoint p1, ofPoint p2) {
    t = ofClamp(t, 0, 1);
    
    return (p2 - p1) * t + p1;
}

//--------------------------------------------------------------
// circleCenter = from.getInterpolated(to, ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1));
void testApp::draw(){
    ofPoint from, to, circleCenter, from1, to1;
    from1.set(10, 10);
    to1.set(ofGetWidth()-10, 10);
    
    from = pointOnLine(ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1), from1, to1);
    //from.set(300,                ofGetHeight()/2);
    to.set  (ofGetWidth()/2, ofGetHeight()/2);
    
    float t = ofGetElapsedTimef() - ((int)ofGetElapsedTimef());
    
    t = powf(1 - t, 2);
    
    circleCenter = pointOnLine(ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1), from, to);
    
    // draw circle
    ofCircle(circleCenter, 5);
    
    // draw control points and line
    ofCircle(from, 2);
    ofCircle(to, 2);
    ofLine(from, to);

    ofCircle(from1, 2);
    ofCircle(to1, 2);
    ofLine(from1, to1);
    
    
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
