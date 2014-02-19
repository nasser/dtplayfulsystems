#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    ofBackground(0, 0, 0);
    ofSetColor(255, 128, 0);
    ofLine(0,0,1024,760);
    ofSetColor(0, 128, 255);
    ofLine(1024, 0, 0,768);
    ofSetColor(0, 128, 255);
    ofLine(512, 0, 512,768);
    ofSetColor(255, 128, 0);
    ofLine(0,380,1024,380);
    
    //float redValue = 10.5;
    //int redValueAsInt = 12; //Range of an int -2^31...2^31
    //string name = "DT Playful Systems";
    
    //ofRect(200 + ofGetElapsedTimef(), 200, 600, 400);
    ofNoFill();
    ofSetColor(255, 128, 0);
    for (int i = 0; i <= x; i+= 10) { 
        ofEllipse(512, 380, i, i);
    }
    
    switch (x) {
        case 20:
            //do some stuff
            break;
        case 30:
            //do some other stuff
            break;
        default:
            break;
    }
    
    x += 1;
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    someColor.g = 255;
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
