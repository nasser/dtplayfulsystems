#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    //COLOR BG
    colBG.r = 0;
    colBG.g = 20;
    colBG.b = 20;

    //COLOR RECT
    colRect.r = 250;
    colRect.g = 250;
    colRect.b = 200;
    
    //RECT
    sz = 600;
    posX = ofGetWidth()/2;
    posY = ofGetHeight()/2;
    
    //ELEMENTS
    ofBackground(colBG);
    rot = 360/8;
    scale = .71;
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofTranslate(posX, posY);
    ofSetRectMode(OF_RECTMODE_CENTER);
    //RECT DRAWINGS
    ofNoFill();
    ofSetColor(colRect);
    ofRect(0, 0, sz, sz);
    
        
    //B SQUARES
    for(int i =0; i< 10; i++){
        ofFill();
        ofSetColor(colRect, 5*i+40);
        ofRect(0, 0, sz+i, sz+i);
        ofScale(scale, scale);
        ofRotate(rot);
    }
    
    
/* A SQUARES
 //Rotations 1
    ofRotate(rot);
    ofScale(scale, scale);
    ofRect(0, 0, sz, sz);

    //Rotations 2
    ofRotate(rot);
    ofScale(scale, scale);
    ofRect(0, 0, sz, sz);

    //Rotations 3
    ofRotate(rot);
    ofScale(scale, scale);
    ofRect(0, 0, sz, sz);

    //Rotations 4
    ofRotate(rot);
    ofScale(scale, scale);
    ofRect(0, 0, sz, sz);

    //Rotations 5
    ofRotate(rot);
    ofScale(scale, scale);
    ofRect(0, 0, sz, sz);
    
    //Rotations 6
    ofRotate(rot);
    ofScale(scale, scale);
    ofRect(0, 0, sz, sz);

    //Rotations 7
    ofRotate(rot);
    ofScale(scale, scale);
    ofRect(0, 0, sz, sz);
 */

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
