#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
ofSetRectMode(OF_RECTMODE_CENTER);
}

//--------------------------------------------------------------
void testApp::update(){
    ofBackground(0);

}

//--------------------------------------------------------------
void testApp::draw(){

    

//    for (int i = 0; i < 80; i = i+5) {
//        line(30, i, 80, i);
//    }
    
    

//    ofRotateZ(10);  // <- rotate the object around the z axis by some amount.
//    //x is specified as a global variable in the testApp.h
//    ofSetColor(90,10,105);
//    ofRect(100,200,200,200);
    
//    ofSetRectMode(OF_RECTMODE_CENTER);
//    ofRotateX(x);  // <- rotate the object around the z axis by some amount.
//    ofSetColor(90,10,105,x);
//    ofRect(200,200,200,200);

    
//
//    for (int i = 0; i<5; i++){
//        
//        ofSetColor(255);
//        ofLine(i, 0, 2, 2);
//    }
    
    x += 1; // x = x+1 (so adds 1 everytime)
    y += 1;
    
    ofPushMatrix();
    ofTranslate(500,350);
    ofSetColor(255,20);
    ofRotateZ(x);
    ofRect(0,0,200,200);
    ofRotateZ(x);
    ofRect(0,0,200,200);
    ofRotateZ(x);
    ofRect(0,0,200,200);
    ofRotateZ(x);
    ofRect(0,0,200,200);
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(500,350);
    ofSetColor(225,20);
    ofRotateY(x);
    ofRect(0,0,50,50);
    ofRotateY(x);
    ofRect(0,0,50,50);
    ofRotateY(x);
    ofRect(0,0,50,50);
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(500,350);
    ofSetColor(225,20);
    ofRotateX(x);
    ofRect(0,0,500,500);
    ofRotateX(x);
    ofRect(0,0,500,500);
    ofRotateX(x);
    ofRect(0,0,500,500);
    ofRotateX(x);
    ofRect(0,0,500,500);
    ofRotateX(x);
    ofRect(0,0,500,500);
    ofRotateX(x);
    ofRect(0,0,500,500);
    ofPopMatrix();
    

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
