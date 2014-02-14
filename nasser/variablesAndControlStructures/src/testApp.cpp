#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    theColor.set(0, 0, 0);
}

//--------------------------------------------------------------
void testApp::update(){
    if(theColor.r < 255)
        theColor.r += 1;
    
    x += 0.1;
}

//--------------------------------------------------------------
void testApp::draw() {
    ofBackground(0, 0, 0);
    ofSetColor(255, 128, 0);
    ofLine(10,10,100,100);
    
    ofSetColor(theColor);
    ofLine(500,500,100,100);
    
    ofRect(200 + x, 200, 600, 400);
    
    ofSetColor(255, 255, 0);
    for (int i=0; i<x; i += 20) {
        ofLine(200 + i, 0, 200 + i, 500);
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    switch (key) {
        case ' ':
            theColor.r = 255;
            break;
        case 'a':
            theColor.g = 80;
            break;
        case 's':
            theColor.b = 128;
            break;
            
        default:
            break;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    if (key == ' ') {
        theColor.g = 0;
    }
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
