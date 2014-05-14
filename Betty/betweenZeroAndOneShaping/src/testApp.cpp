#include "testApp.h"
#include "ofPolyline.h"
#include "ofPath.h"

//--------------------------------------------------------------
void testApp::setup(){
    

}

//--------------------------------------------------------------
void testApp::update(){

}

ofPoint testApp::pointOnLine(float t, ofPoint p1, ofPoint p2, ofPoint p3, ofPoint p4){
    t = ofClamp(t, 0, 1);
    
    return(p2 - p1)*t+p1;
}


//--------------------------------------------------------------
void testApp::draw(){
    ofSetBackgroundColor(0,0,0);

    ofSetColor(200, 2, 20);
    
    ofPoint from, to, from1, to1, from2, to2, circleCenter, circleCenter2, circleCenter3, circleCenter4, circleCenter5;
    
    from2.set(ofGetWidth()/2, 10);
    to2.set(60, ofGetHeight()/2);
    from1.set(0,0);
    to1.set(ofGetWidth(),0);
    from.set(50, ofGetHeight()/2);
    to.set(ofGetWidth()-100, ofGetHeight()/2);
    
    from = pointOnLine(ofMap(sin(ofGetElapsedTimef()*4), -1, 1, 0, 1), from1, to1, from2, to2);
    to.set(ofGetWidth()/2, ofGetHeight()); 
    
    //float t = ofMap(sin(ofGetElapsedTimef()));
    
    circleCenter = pointOnLine(ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1), from, to, from2, from1);
    circleCenter2 = pointOnLine(ofMap(sin(ofGetElapsedTimef()-.1), -1, 1, 0, 1), from, to, from2, from1);
    circleCenter3 = pointOnLine(ofMap(sin(ofGetElapsedTimef()-.2), -1, 1, 0, 1), from, to, from2, from1);
    circleCenter4 = pointOnLine(ofMap(sin(ofGetElapsedTimef()-.3), -1, 1, 0, 1), from, to, from2, from1);
    circleCenter5 = pointOnLine(ofMap(sin(ofGetElapsedTimef()-.5), -1, 1, 0, 1), from, to, from2, from1);
    
    ofCircle(circleCenter, 40);
    ofCircle(circleCenter2, 30);
    ofCircle(circleCenter3, 20);
    ofCircle(circleCenter4, 10);
    ofCircle(circleCenter5, 5);
    ofCircle(from, 2);
    ofCircle(to, 2);
    ofLine(from, to);
    //ofCurve(10*sin(ofGetElapsedTimef()*8), 2, 90, 100, 80, 90, 208, ofGetWidth());
    

    
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
