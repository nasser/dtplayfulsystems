#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetWindowShape(500, 500);
    ofBackground(255, 255, 255);
    
}

//--------------------------------------------------------------
void testApp::update(){

}

void drawlines(){
    ofTranslate(100, 100);
    ofRotate(100);
    ofLine(250, 250, 50, 50);
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(255, 95, 150);
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofLine(0, 0, 100, 100);
    
    
    for(int i=0; i<50; i++){
        drawlines();
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
