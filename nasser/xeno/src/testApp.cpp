#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    circleCenter.set(ofGetWidth()/2, ofGetHeight()/2);
    destination.set(ofGetWidth() - 50, ofGetHeight()/2);
    ofSetBackgroundAuto(false);
    ofSetColor(255, 255, 255, 8);
    ofBackground(0, 0, 0);
    
    string name = "ramsey";
    name.length() * 10;
}

//--------------------------------------------------------------
void testApp::update(){
    /*
     // basic linear movement
    if(circleCenter.x == destination.x) {
        circleCenter.x = destination.x;
    } else {
        circleCenter.x += 1;
    }
    */
    
    destination.set(ofRandomWidth(), ofRandomHeight());
    
    // circleCenter seeks destination using xeno logic
    if(circleCenter.distance(destination) <= 0.1) { // DO NOT CHANGE 3.3 OR DEATH
        // the circle has arrived
        circleCenter = destination;
    } else {
        // the circle has not arrived, keep moving
        circleCenter.interpolate(destination, 0.01);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofDrawBitmapString(ofToString(circleCenter.distance(destination)), 10, 10);
    
    ofCircle(circleCenter, 10);
    // ofCircle(destination, 5);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    // destination.set(x, y);
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    if(button == 0) {
        circleCenter.set(x, y);
    } else if(button == 2) {
        destination.set(x, y);
    }
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
