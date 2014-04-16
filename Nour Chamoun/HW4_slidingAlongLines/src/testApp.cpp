#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0);
    ofSetFrameRate(20);
//    ofSetVerticalSync(true);
}

//--------------------------------------------------------------
void testApp::update(){
    
}

void testApp::draw(){
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    ofSetColor(30, 20,200);
    ofNoise(24, 100, 200);
    
    int n =200;
    for(int i = 0; i< n; i=i+4){
        ofRotateX(430.f / n);
        ofRotateY(30.f / n);
        ofRotateX(110.f / n);
        
    float pos = cos(ofGetElapsedTimef()*((float)(i)/ n))*ofGetHeight()/2;
    
        ofSetColor(30, 20,200);
        ofLine(pos*0.3, 20, pos*0.8, 10);
       
        ofSetColor(200, 20,20);
        ofCircle(pos, 2, 2);
        
        ofSetColor(20, 220,20);
        ofCircle(pos, 12, 5);
        ofRect(pos, 40, 13, 3);
        
        ofSetColor(20, 120,50);
        ofCircle(pos, 22, 8);
    
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
