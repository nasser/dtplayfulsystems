#include "testApp.h"

void testApp::drawTwoLines(float spacing, float x1, float y1, float x2, float y2){
    ofLine(x1, y1, x2, y2);
    ofLine(x1, y1 + spacing, x2, y2 + spacing);
}

void testApp::drawAngledLine(ofPoint center, float angle, float length){

//    float outerX = x + cos(ofDegToRad(angle)) * length;
//    float outerY = y + sin(ofDegToRad(angle)) * length;

// another wat to code
    ofPoint outer; //outer is a object can carry things, like number or other object
    
    outer.x = cos(ofDegToRad(angle)) * length;
    outer.y = sin(ofDegToRad(angle)) * length;
    
    ofLine(center, center + outer);
}

//--------------------------------------------------------------
void testApp::setup(){
    
    //of println
    cout << ofGetWidth() << endl;
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
//    drawTwoLines(20 + sin(ofGetElapsedTimef() * 20) * 50, 0, 0, 100, 200);
    
    ofPoint center;
    center.x = ofGetWidth()/2;
    center.y = ofGetHeight()/2;
    drawAngledLine(center, 45 + ofGetElapsedTimef() *50, 100);
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
