#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------
void testApp::update(){
    

}

float testApp:: xCoordinateOnLine(float t, float x1, float x2){
    t = ofClamp(t,0,1);
    return(y2-y1) * t + y1;
    
}

ofPoint testApp:: pointOnLine(float t, ofPoint p1, ofPoint p2){
    t = ofClamp(t,0,1);
    
    return(p2-p1) * t+ p1;
    
}

//--------------------------------------------------------------
void testApp::draw(){

    float mouseX01 = ofClamp((float) mouseX/ ofGetWidth(), 0,1);
    
    cout<< mouseX01 << endl;
    
    int minimumGrey; 120;
    int maximumGrey; 220;
    
    float g = (maximumGrey - minimumGrey) * mouseX01 + minimumGrey; //the mechanics of non-linear mapping
    
    //ofBackground(g, g, g);
    
//    float cicleX = 100;
//    float circleY = 100;
    
    //linear interpolation =>>> Look it up
    
//    float circleX = ofMap(mouseX, 0, ofGetWidth(), 50, 350, true); //this built-in function is more for the linear (true enables clamping) note: research what the hell clamping is
//    
//    float circleY = ofMap(mouseX, 0, ofGetWidth(), 100, 300 + sin(ofGetElapsedTimef()*10)* 100, true);

    float circleX = xCoordinateOnLine(mouseX01, 50, 350);
    
    float circleY = yCoordinateOnLine(mouseX01, 100, 300);
    
    ofCircle(circleX, circleY, 20);
    
    
    
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
