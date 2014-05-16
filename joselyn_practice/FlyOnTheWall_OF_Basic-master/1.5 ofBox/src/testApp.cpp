#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofBackground(255, 255, 255);
    
    ofSetVerticalSync(true);
  
    // this uses depth information for occlusion
	// rather than always drawing things on top of each other
    glEnable(GL_DEPTH_TEST);
    

    ofSetRectMode(OF_RECTMODE_CENTER);
    ofEnableSmoothing();
    
    ofSetLineWidth(2);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
//Begin using the camera by ofEasyCam function
//You can rotate the camera angle by mouse dragging
cam.begin();
    ofSeedRandom(0);
    
    //ofPushMatrix saves the current coordinate system allowing users to develop specific movements.
    //ofPopMatrix needs to be called after
    ofPushMatrix();
    
    ofRotateY(ofGetElapsedTimef()*100);  // increasing the rotating angle by time
    ofRotateZ(50);
    
    
    ofNoFill();
    ofSetColor(0);
    ofBox(0, 0, 0, 200);    // draw the box filled color
    
    
    ofFill();
    //ofSetColor(55);
    ofEnableAlphaBlending();
    ofSetColor(0,100);
    ofBox(0, 0, 0, 200);   // draw the box outlines
    ofDisableAlphaBlending();
    
    
    ofPopMatrix();
    
cam.end();

    
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