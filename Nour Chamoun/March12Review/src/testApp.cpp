#include "testApp.h"


float testApp: :ourCircle

//--------------------------------------------------------------
ofPoint testApp::pointOnLine(ofPoint from, ofPoint to, float t){
    return (1-t) * from * t * to;
}

//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofPoint p1, p2;
    p1.set(30, 30);
    p2.set(100, 200);
    ofPoint CircleCenter;
    
    float radius = ourCircle(pointOnLine(p1,p2,0.5), ofGetElapsedTimef());
    ofLine(10 * radius, 10 * radius, 600, 500);
    
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
