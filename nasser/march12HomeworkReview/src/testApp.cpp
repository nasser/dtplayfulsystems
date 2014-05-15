#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
}

//--------------------------------------------------------------
void testApp::update(){
    
}

float testApp::ourCircle(ofPoint p, float r) {
    ofCircle(p, r);
    
    return r;
}

void testApp::drawPointOnLine(ofPoint p1, ofPoint p2, float t) {
    t = ofClamp(t, 0, 1);
    // ofPoint circleCenter = (p2 - p1) * t + p1;
    // ofPoint circleCenter = pointOnLine(p1, p2, t);
    ofPoint circleCenter = p1.getInterpolated(p2, t);
    
    ofCircle(circleCenter, 5);
    ofLine(p1, p2);
    ofCircle(p1, 3);
    ofCircle(p2, 3);
}

//--------------------------------------------------------------
ofPoint testApp::pointOnLine(ofPoint from, ofPoint to, float t) {
    return (1 - t) * from + t * to;
}

//--------------------------------------------------------------
void testApp::draw(){
    ofPoint p1, p2;
    
    p1.set(30, 30);
    p2.set(100, 200);
    
    // float radius = ourCircle(pointOnLine(p1, p2, 0.5), ofGetElapsedTimef());
    // ofLine(10 * radius, 10 * radius, 600, 500);
    
    drawPointOnLine(p1, p2, 0.5);
    
    for (int i=0; i<100; i++) {
        drawPointOnLine(p1 + ofPoint(i*10, 0),
                        p2 + ofPoint(i*10, 0), sin(ofGetElapsedTimef() + i));
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
