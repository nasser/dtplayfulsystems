#include "testApp.h"

float g=0.95; //gravity

//--------------------------------------------------------------
void testApp::setup(){

    ofSetFrameRate(60);
    ofEnableSmoothing();
    
    nBalls=ofRandom(10,50);
    myBall = new ofBall*[nBalls];
    
    for (int i = 0; i < nBalls; i++){
        float x = ofRandom(0, ofGetWidth());
        float y = ofRandom(0, ofGetHeight());
        float r = ofRandom(0, ofGetWidth()/25);
        
        myBall[i] = new ofBall(x,y,r);  // create each object from the array
    }
}

//--------------------------------------------------------------
void testApp::update(){

    for(int i=0; i<nBalls; i++)
    {
        myBall[i]->update();
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackgroundGradient(ofColor::black,ofColor(10,20,30), OF_GRADIENT_CIRCULAR);

    for(int i=0; i<nBalls; i++)
    {
        myBall[i]->draw();
    }
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    nBalls=ofRandom(10,50);
    myBall = new ofBall*[nBalls];
    
    for (int i = 0; i < nBalls; i++){
        float x = ofRandom(0, ofGetWidth());
//        float y = ofRandom(0, ofGetHeight());
        float r = ofRandom(0, ofGetWidth()/25);
        
        myBall[i] = new ofBall(x,y,r);  // create each object from the array
    }
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