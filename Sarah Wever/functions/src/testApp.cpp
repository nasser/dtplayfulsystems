#include "testApp.h"

void testApp::drawTwoLines(float spacing, float x1, float y1, float x2, float y2){
    
    ofLine(x1, y1, x2, y2);
    ofLine(x1, y1+spacing, x2, y2 +spacing);
    
}
//--------------------------------------------------------------
void testApp::drawAndledLine(ofPoint center, float angle, float length){
    
    ofPoint outer;
    
    outer.x =center.x+ cos(ofDegToRad(angle)) *length;
    outer.y =center.y+ sin(ofDegToRad(angle)) *length;
    
    ofLine(center, center + outer);
}

//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackground(0);

    
    drawTwoLines(20+sin(ofGetElapsedTimef() *20) *50,0, 0, 100, 200);
    ofPoint center;
    center.x = ofGetWidth()/2;
    center.y = ofGetHeight()/2;
    drawAndledLine(center, 45 + ofGetElapsedTimef()*50, 100);

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
