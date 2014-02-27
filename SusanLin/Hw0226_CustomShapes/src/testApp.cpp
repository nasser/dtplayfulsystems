#include "testApp.h"

void testApp::stars(ofPoint point, float angle, float length){
    // I tried to do closed shape
    // but can't figure out how to use ofVertex()
    ofPoint outer;
    
    ofSetPolyMode(OF_POLY_WINDING_NONZERO);
    ofBeginShape();
    ofVertex(400,135);
    ofVertex(215,135);
    ofVertex(365,25);
    ofVertex(305,200);
    ofVertex(250,25);
    ofEndShape();
}

void testApp::myfunction(float x, float y, float angle, float lentgh){
    
    ofLine(x, y, x + lentgh, y);
    ofLine(x + lentgh, y, x + lentgh + cos(ofDegToRad(angle)) * lentgh, y + sin(ofDegToRad(angle)) * lentgh);
    ofLine(x + lentgh + cos(ofDegToRad(angle)) * lentgh, y + sin(ofDegToRad(angle)) * lentgh, x + lentgh, y + sin(ofDegToRad(angle)) * lentgh * 2);
    ofLine(x + lentgh, y + sin(ofDegToRad(angle)) * lentgh * 2, x, y + sin(ofDegToRad(angle)) * lentgh * 2);
    ofLine(x, y + sin(ofDegToRad(angle)) * lentgh * 2, x - cos(ofDegToRad(angle)) * lentgh, y + sin(ofDegToRad(angle)) * lentgh);
    ofLine(x - cos(ofDegToRad(angle)) * lentgh, y + sin(ofDegToRad(angle)) * lentgh, x, y);
  
}


//--------------------------------------------------------------
void testApp::setup(){
    ofEnableSmoothing();
    ofBackground(0, 0, 0);
    cout << ofGetElapsedTimef() << endl;
}
//--------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
//    ofFill();
    ofSetColor(255, 100, 150);
    myfunction(0, 400, 60, 500);
    myfunction(0, 300, 60, 400);
    myfunction(0, 200, 60, 300);
    myfunction(0, 100, 60, 200);
    myfunction(0, 100, 60, 100);
    
    ofSetColor(100, 255, 150);
    myfunction(ofGetWidth()-500, ofGetHeight()-700, 60, 500);
    myfunction(ofGetWidth()-400, ofGetHeight()-600, 60, 400);
    myfunction(ofGetWidth()-300, ofGetHeight()-500, 60, 300);
    myfunction(ofGetWidth()-200, ofGetHeight()-400, 60, 200);
    myfunction(ofGetWidth()-100, ofGetHeight()-300, 60, 100);
    

//    float x, y, z;
//    float length;
//    
//    x = ofGetWidth()/2;
//    y = ofGetHeight()/2;
//    z = 0;
//    length = 50;
//    
//    ofSetColor(255, 255, 255);
//    ofLine(x, y, x+length, y);
//    for(int i=0; i<6; i++){
//        ofTranslate(x+length,y, z);
//        ofRotate(60);
//        ofLine(0,0,length, 0);
//    }
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
