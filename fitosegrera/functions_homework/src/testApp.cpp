#include "testApp.h"

//--------------------------------------------------------------
void testApp::drawShape(float leftPointX, float leftPointY, float topPointX, float topPointY, float rightPointX, float rightPointY, float bottomPointX, float bottomPointY, float factor){
    
    for(int i = 0; i <500; i+=10){
        ofLine(leftPointX + i, leftPointY - i/factor, topPointX + i/factor, topPointY + i);
        ofLine(topPointX + i/factor, topPointY + i, rightPointX - i, rightPointY + i/factor);
        ofLine(rightPointX - i, rightPointY + i/factor, bottomPointX - i/factor, bottomPointY - i);
        ofLine(bottomPointX - i/factor, bottomPointY - i, leftPointX + i, leftPointY - i/factor);
    }
}
//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0, 0, 0);
    ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
    drawShape(ofGetWidth()/2 - rectSize / 2, ofGetHeight()/2 - rectSize / 2, ofGetWidth()/2 + rectSize / 2, ofGetHeight()/2 - rectSize / 2, ofGetWidth()/2 + rectSize / 2, ofGetHeight()/2 + rectSize / 2, ofGetWidth()/2 - rectSize / 2, ofGetHeight()/2 + rectSize / 2, 5);
    
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
