#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofEnableSmoothing(); // smoothes edges
    
    ofSetFrameRate(30);
    
    xPos = ofGetWindowWidth()/2; //initial x position
    
    yPos = ofGetWindowHeight()/2; //initial y position
    
    

}

//--------------------------------------------------------------
void testApp::update(){
    
    xPos += (mouseX - xPos)*0.1;
    yPos += (mouseY - yPos)*0.1;
    
    // We calculate the x and y distance
    // of the ball to the mouse position and
    // add a little portion of it to the x and y
    // variables

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackgroundGradient(ofColor::gray,ofColor(30, 10, 30), OF_GRADIENT_CIRCULAR);
    ofSetColor(200,200,1255);
    ofFill();
    ofCircle(xPos, yPos, 30);

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
    xPos = ofRandom( ofGetWindowWidth() );
    yPos = ofRandom( ofGetWindowHeight() );

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
