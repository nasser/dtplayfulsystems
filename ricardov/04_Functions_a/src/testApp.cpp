#include "testApp.h"




// 1 --------------------------------------------------------------
void testApp::drawTwoLines(float x1, float y1, float x2, float y2) {
    ofLine(x1, y1, x2, y2);
}

// 2 --------------------------------------------------------------
void testApp::drawAngledLines(float angle, float lenght) {
    ofPoint center;
    center.x = ofGetWidth()/2;
    center.y = ofGetHeight()/2;

    
    ofPoint outer;
    outer.x = ofGetWidth()/2  + cos(angle) * lenght;
    outer.y = ofGetHeight()/2 + sin(angle) * lenght;
 
    ofLine(center, outer);
    ofCircle(outer, 20);
}


//--------------------------------------------------------------
void testApp::setup(){
    
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){

    // 1 - - - - - - - - - - - -
//    for (int i =0; i<50; i++) {
//        float myVal = sin(ofGetElapsedTimef()) * 350;
//        ofLine(20*i, ofGetHeight()/2+myVal, ofGetWidth()/2, ofGetHeight()/2);
//        
//    }

    // 2 - - - - - - -
    drawAngledLines(ofGetElapsedTimef(), 250);

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
