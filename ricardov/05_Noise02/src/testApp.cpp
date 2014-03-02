#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
    ofSetWindowShape(640, 480);
    ofSetBackgroundAuto(true);

    // FOR LINES
    x = 0;
    y = 0;
    myNoise = 0;
    myAngle = 0;

    w = ofGetWidth();
    h = ofGetHeight();
    
//    ofSetFrameRate(5);
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    myAngle = myAngle + 0.1;
 
    // For every x value, calculate a y value with sine function
    x = myAngle;

    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(10);

    
    // 1 -LINES
    ofPushMatrix();
        ofSetColor(200, 200, 100); // gray
        ofDrawBitmapString("Homework 5 - Lines and Noise \nRicardov", 20,20);
    ofPopMatrix();

    
    // 1ok
    for (int i = 0; i < NUM_POINTS; i++) {
        for (int j=0; j<h; j++) {
            
            ofSetColor(.3*i, .4*j, 150); // gray
            ofCircle(i, h/2 + sin(j)*50, .5);
        }
    }
    
    // 1ok
//    for (int i = 0; i < NUM_POINTS; i++) {
//        for (int j=0; j<h; j++) {
//            
//            ofSetColor(.3*i, .4*j, 150); // gray
//            ofCircle(i, j, .5);
//        }
//    }

 
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
