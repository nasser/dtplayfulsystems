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
    
    // 1 - LERP, YELLOW BALL - - - - - - - - - - - - - - - -
//    amount1 = 0.1;

    x1 = ofLerp(x1, mouseX, amount1);
    y1 = ofLerp(y1, mouseY, amount1);

    //SHOW VALUES ON SCREEN
    ofSetColor(200);
    ofDrawBitmapString("ofLerp", x1 + 13, y1);
    ofDrawBitmapString("x: " + ofToString(x1),      x1 + 13, y1+12);
    ofDrawBitmapString("y: " + ofToString(y1),      x1 + 13, y1+24);

    ofSetColor(200, 200, 0);
    ofCircle(x1, y1, 10);
    

    
    // 2 - CLAMP, GREEN BALL - - - - - - - - - - - - - - - -
    newX = ofClamp(x2, 400, 700);
    newY = ofClamp(y2, 400, 700);

    //RECT AREA
    ofSetColor(70, 40);
    ofRect(400, 400, 300, 300);

    //SHOW VALUES ON SCREEN
    ofSetColor(200);
    ofDrawBitmapString("ofClamp", newX + 13, newY);
    ofDrawBitmapString("newX: " + ofToString(newX),      newX + 13, newY+12);
    ofDrawBitmapString("newY: " + ofToString(newY),      newX + 13, newY+24);

    //BALL CONSTARINED
    ofSetColor(0, 20, 200);
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
