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

ofPoint testApp:: pointOnLine(float t, ofPoint p1, ofPoint p2){
    t = ofClamp(t,0,1);
    
    return(p2-p1) * t+ p1;
    
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
    
    float mouseX01 = ofClamp((float)mouseX / ofGetWidth(), 0, 1);
    cout << mouseX01 << endl;
    
    int minimumGrey = 128;
    int maximumGrey = 220;
    
    float g = (maximumGrey - minimumGrey) * mouseX01 + minimumGrey;
    
    // ofBackground(g, g, g);
    
    // float circleX = xCoordinateOnLine(mouseX01, 50, 350);
    // float circleY = yCoordinateOnLine(mouseX01, 100, 300);
    
    // ofCircle(circleX, circleY, 2);
    
    ofPoint circleCenter = pointOnLine(mouseX01, ofPoint(50, 100), ofPoint(350, 300));
    ofCircle(circleCenter, 2);

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
