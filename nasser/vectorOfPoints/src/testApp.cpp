#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    points.push_back(ofPoint(0, ofGetHeight()/2));
    points.push_back(ofPoint(10, ofGetHeight()/2));
    points.push_back(ofPoint(20, ofGetHeight()/2));
    points.push_back(ofPoint(30, ofGetHeight()/2));
    points.push_back(ofPoint(40, ofGetHeight()/2));
    points.push_back(ofPoint(50, ofGetHeight()/2));
}

//--------------------------------------------------------------
void testApp::update(){
    for (int i=0; i<points.size(); i++) {
        points[i].y = ofGetHeight()/2 + sin(i + `ofGetElapsedTimef()) * 100;
        
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    for (int i=0; i<points.size()-1; i++) {
        ofLine(points[i], points[i+1]);
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
