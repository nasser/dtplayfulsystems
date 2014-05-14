#include "testApp.h"


//--------------------------------------------------------------
void testApp:: drawPointOnLine(ofPoint p1, ofPoint p2, float t){
    t = ofClamp(t, 0, 1);
    ofPoint circleCenter = p1.getInterpolated(p2, t);
    
    ofCircle(circleCenter, 5);
    ofLine(p1, p2);
    ofCircle(p1, 3);
    ofCircle(p2, 3);
}

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255, 255, 255);
    ofSetBackgroundAuto(false);
    
    myfont.loadFont("arial.ttf", 32);
    
}

//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(51, 204, 204, 5);
    myfont.drawString("BOOM pyramid!!", ofGetWidth()/2-100,ofGetHeight()/2+200);
    ofPoint p1, p2, d1, d2, a1, a2;
    
    
    ofTranslate(0, 40);
    p1.set(ofGetWidth()/2, 10);
    p2.set(ofGetWidth()/2, ofGetHeight()/2);
    d1.set(ofGetWidth()/2, 10);
    d2.set(0, ofGetHeight()/2);
    a1.set(ofGetWidth()/2, 10);
    a2.set(ofGetWidth(), ofGetHeight()/2);

    for (int i = 0; i <100; i++){
        drawPointOnLine(p1 + ofPoint(i*5, 5*i), p2, cos(ofGetElapsedTimef()+.01*i));
    }
    for (int i = 0; i <100; i++){
        drawPointOnLine(d1 + ofPoint(i*5, 5*i), d2, cos(ofGetElapsedTimef()+.01*i));
    }
    for (int i = 0; i <100; i++){
        drawPointOnLine(a1 + ofPoint(i*5, 5*i), a2, cos(ofGetElapsedTimef()+.01*i));
    }
    
    //    for (int i = 0; i <100; i++){
    //        drawPointOnLine(p1 + ofPoint(i*10, 1*i), p2, sin(ofGetElapsedTimef()+i));
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
