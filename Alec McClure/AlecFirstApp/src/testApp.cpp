#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	theColor.set=(0,0,0);
}

//--------------------------------------------------------------
void testApp::update(){
	theColor.r += 1;
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(0,255,255);
	ofSetColor(100,100,100);
    ofCircle(200, 300, 60);
    
    ofSetColor(theColor);
    ofRect(200,200,50+ofGetElapsedTimef()*50,400);
    ofDrawBox(100+ofGetSeconds()*20,100,100,100,100,100);
    //ofRotate(ofGetElapsedTimef(),500.0, 300.0, 0.0);
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
