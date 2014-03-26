#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------

ofPoint testApp::drawAngledLine(ofPoint center, float angle, float length) {
    ofPoint outer;
    outer.set(cos(ofDegToRad(angle)), sin(ofDegToRad(angle)));
    ofLine(center, center + outer * length);
    
    return center + outer * length;
}



//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofPoint center;
    center.set(ofGetWidth()/2, ofGetHeight()/2);
    
    ofPoint outerPosition = drawAngledLine(center, 100 + ofGetElapsedTimef() * 50, 500);
    ofLine(center, outerPosition);
    float distance=ofMap(sin(ofGetElapsedTimef()),-1, 1, 0, 1);
    ofPoint circleCenter=drawAngledLine(center, 100 + ofGetElapsedTimef() * 50, distance*500);
    ofCircle(circleCenter,5);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    destination.set(x,y);
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    if(button==0){
    circleCenter.set(x,y); //don't need to write mouseX, mouseY
    }else if(button==2){
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
