#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofBackground(20);

    //FOR LERP
    x1 = 0;
    y1 = 0;
    amount1 = 0.1;

    //FOR CLAMP
    x2 = 0;
    y2 = 0;
    amount2 = 0.1;


}

//--------------------------------------------------------------
void testApp::update(){

    x2 = mouseX;
    y2 = mouseY;

}

//--------------------------------------------------------------
void testApp::draw(){
    
    // 1 - LERP - - - - - - - - - - - - - - - -
    amount1 = 0.1;

    x1 = ofLerp(x1, mouseX, amount1);
    y1 = ofLerp(y1, mouseY, amount1);

    ofSetColor(200, 200, 0);
//    ofCircle(x1, y1, 10);
    

    
    // 2 - CLAMP - - - - - - - - - - - - - - - -
    newX = ofClamp(x2, 400, 700);
    newY = ofClamp(y2, 400, 700);

    //RECT AREA
    ofSetColor(30);
    ofRect(400, 400, 300, 300);

    //BALL CONSTRINED
    ofSetColor(0, 200, 200);
    ofCircle(newX, newY, 10);
    
    
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
