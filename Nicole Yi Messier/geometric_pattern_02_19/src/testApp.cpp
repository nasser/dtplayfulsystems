#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0 , 0, 0);
    step = 20;
    x1 = ofGetWindowWidth();
    x2 =  ofGetWindowWidth() - step;
    y1 = 0;
    y2 = ofGetWindowHeight();
    x3 = ofGetWindowWidth();
    x4 = 0;
    y3 = ofGetWindowHeight();
    y4 = ofGetWindowWidth() - step;
    x5 = 0;
    x6 = step;
    y5 = ofGetWindowHeight();
    y6 = 0;
    x7 = 0;
    x8 = ofGetWindowWidth();
    y7 = 0;
    y8 = step;


}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofEnableSmoothing();
    ofSetColor(255, 255, 255);
    
    for(int i = 0; i < ofGetWindowHeight(); i+=step){
        y1 = i;
        x2 = (ofGetWindowWidth() - step) - i;
        ofLine(x1, y1, x2, y2);
    }
    
    
    for (int j = 0; j < ofGetWindowHeight(); j+=step){
        x3 = ofGetWindowWidth() - j;
        y4 = (ofGetWindowHeight() - step)-j;
        ofLine(x3, y3, x4, y4);
    }
    
    for (int k = 0; k < ofGetWindowHeight(); k+=step){
        x6 = step + k;
        y5 = ofGetWindowHeight() - k;
        ofLine(x5, y5, x6, y6);
    }
    
    for (int m = 0; m < ofGetWindowHeight(); m+=step){
        x7 = 0 + m;
        y8 = step + m;
        ofLine(x7, y7, x8, y8);
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
