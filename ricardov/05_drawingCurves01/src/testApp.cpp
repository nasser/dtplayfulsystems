#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(10);
    ofSetBackgroundAuto(false);
    
    //VARS CIRCLE
    w = ofGetWidth();
    h = ofGetHeight();
    
    x = 0;
    y = 0;
    sz = 2;

    //VARS ANGLULAR MOV
    theta = 0;
    diam = 150;

    divX = 1;
}

//--------------------------------------------------------------
void testApp::update(){


//    x = w/2 + sin(theta) * diam;
    x = w/2 + sin(theta/divX) * diam;
    y = h/2 + cos(theta) * diam;


    theta +=  0.1;

}

//--------------------------------------------------------------
void testApp::draw(){
    //FOR BG ERASE
    ofSetColor(10,6);
    ofRect(0, 0, w, h);

    //TITLE
    ofSetColor(200);
    ofDrawBitmapString("HW 5? (ricardov); Drawing Lines\nPress keys 1 to 5 to change x", 20, 20);
    ofDrawBitmapString("x =  sin(theta/" + ofToString(divX)+")", 20, 60);
    
    // 1- CIRCLE
    ofSetColor(200);
    ofCircle(x, y, sz, sz);
    ofSetColor(40, 40);
    ofLine(w/2, h-50, x, y);
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

    if(key == '1'){
        divX = 1;
    }
    if(key == '2'){
        divX = 2;
    }
    if(key == '3'){
        divX = 3;
    }
    if(key == '4'){
        divX = 4;
    }
    if(key == '5'){
        divX = 5;
    }
    
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
