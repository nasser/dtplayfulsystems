#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------
void testApp::update(){


    
}

//--------------------------------------------------------------
void testApp::draw(){

    float mouseX01 = ofClamp((float)mouseX/ofGetWidth(),0,1);
    
    int minimumGrey=128;
    int maximumGrey=220;
    
    float g=(maximumGrey-minimumGrey)*mouseX01-minimumGrey;
    ofBackground(g, g, g);
    
    float circleX=ofMap(mouseX, 0, ofGetWidth(), 50, 350,true);
    float circleY=ofMap(mouseX, 0, ofGetWidth(), 1/100, 300+sin(ofGetElapsedTimef()*10)*20,true);
    
    ofCircle(circleX, circleY, 40);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

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