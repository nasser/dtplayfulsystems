#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    counter = 1;
    color = 23;

}

//--------------------------------------------------------------
void testApp::update(){
    theColor.r +=1;

}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(theColor.r, 0 + counter, 54);
    ofRect(0, 0, 80 + counter, 80 + counter);
    counter++;
    
 
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
