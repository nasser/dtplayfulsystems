#include "testApp.h"

//////////////////////////////////////////////////////////////////////
/////////////////////// XENO ANIMATION EXAMPLE ///////////////////////
//////////////////////////////////////////////////////////////////////

//--------------------------------------------------------------
void testApp::setup(){
    circleCenter.set(ofGetWidth()/2, ofGetHeight()/2);
    destination.set(ofGetWidth()/2, ofGetHeight()/2);
}

//--------------------------------------------------------------
void testApp::update(){
//    if(circleCenter.x == destination.x){
//        circleCenter.x = destination.x;
//    }else{
//        circleCenter.x += 2;
//    }
    if(circleCenter.distance(destination) <= 1){
        circleCenter = destination;
    }else{
        circleCenter.interpolate(destination, 0.05);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0);
    string instruction = "click and drag to move sprite";
    ofDrawBitmapString(instruction, 10, 10);
    ofDrawBitmapString(ofToString(circleCenter.distance(destination)), instruction.size() * 10 + 10, 10);
    ofSetColor(100, 200, 0);
    ofCircle(circleCenter, 10);
    //ofCircle(destination, 5);
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
    if(button==0){
        destination.set(x, y);
    }
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
