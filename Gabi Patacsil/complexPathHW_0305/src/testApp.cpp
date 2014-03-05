#include "testApp.h"



//--------------------------------------------------------------
void testApp::setup(){
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void testApp::update(){
}




ofPoint testApp::pointOnLine(float t, ofPoint p1, ofPoint p2){
    t = ofClamp(t, 0, 1);
    return (p2 - p1) * t + p1;
}



//--------------------------------------------------------------
void testApp::draw(){
    
    
    
    ofSetColor(0,0,0,10);
    for(int i = 0; i <100; i++){
    ofPoint from, to, circleCenter, test;
    from.set(400+(i*5), 400);
    to.set(550, 200+(i*5));
    
    float t = ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1);
    
    circleCenter = pointOnLine(t, from-cos(ofGetElapsedTimef())*20, to+cos(ofGetElapsedTimef())*10);
    ofCircle(circleCenter, 2);
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
