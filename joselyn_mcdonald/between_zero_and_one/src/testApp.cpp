#include "testApp.h"

float circleRad = 2;


float testApp::xCoordinateOnLine(float t, float x1, float x2){
    t = ofClamp(t, 0, 1); // value that is between 0 and 1
    
    return(x2 - x1) * t + x1;
    
}

float testApp:: yCoordinateOnLine(float t, float y1, float y2){
    t = ofClamp(t, 0, 1);
    
    return(y2 - y1) * t + y1;
    
    //ofFloats return floats
    
}

ofPoint testApp:: pointOnLine(float t, ofPoint p1, ofPoint p2){
    t = ofClamp(t, 0, 1);
    
    return (p2 - p1) *t + p1;
    //ofPoint returns a point 
}

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetBackgroundAuto(false); 

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ///this is all about linear interpolation 
    
    float mouseX01 = ofClamp((float)mouseX / ofGetWidth(), 0, 1); // clamp won't let it get bigger than one or less than 0
    cout <<mouseX01<<endl;
    
    int minGrey = 128;
    int maxGrey = 220;
    
    float g = (maxGrey - minGrey) *mouseX01 + minGrey; 

    //ofBackground(g, g, g);
    
//    float circleX = ofMap(mouseX, 0, ofGetWidth(), 50, 350, true);// the true sets the clamp
//
//    float circleY = ofMap (mouseX, 0, ofGetWidth(), 450, 300 +sin(ofGetElapsedTimef()*10) *100, true);// the true sets the clamp on // sin is between -1 and 1
    // if you want the range to be smaller for the y then you need to reduce the number multiplied by sin
    
    
    //ofMap(mouseX, 0, ofGetWidth(), 50, 350);
    
    //float circleRad = 40;
    
    //secont iteration of the code
    
    float circleX = xCoordinateOnLine(mouseX01, 50, 350);
    float circleY = yCoordinateOnLine(mouseX01, 100, 300);
    
    ofPoint circleCenter = pointOnLine(mouseX01, ofPoint(50, 100), ofPoint(350, 300)); 
    ofCircle(circleCenter,2);
    
    
    
    ofCircle(circleX, circleY, circleRad);
    
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
    
    circleRad++;
    

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
