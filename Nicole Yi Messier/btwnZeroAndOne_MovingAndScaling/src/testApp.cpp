#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
float testApp::xCoordinateOnLine(float t, float x1, float x2){
    
    //t is the value between 0 and 1
    t = ofClamp(t, 0, 1);
    
    return(x2-x1)*t + x1;
}

//--------------------------------------------------------------
ofPoint testApp::pointOnLine(float t, ofPoint p1, ofPoint p2){
    t = ofClamp(t, 0, 1);
    
    return(p2 - p1)*t + p1;
}

//--------------------------------------------------------------
float testApp::yCoordinateOnLine(float t, float y1, float y2){
    t = ofClamp(t, 0, 1);
    
    return(y2-y1)*t + y1;
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    //linear interpolation
    
    float mouseX01 =  ofClamp((float)mouseX / ofGetWidth(), 0, 1);
   //float mouseX01 =  (float)mouseX / ofGetWidth();
    cout << mouseX01 << endl;
    
    int minGrey = 128;
    int maxGrey = 255;
    
    float g = (maxGrey - minGrey)*mouseX01+minGrey;
    
    //ofBackground(g, g, g);
    
    // float circleX = 100;
    //float cirlceY = 100;
    //float circleY = ofMap(mouseX,0, ofGetWidth(), 450, 300 + sin(ofGetElapsedTimef()*5)*200, true);
    
    //true enables clamping
    //float circleX = ofMap(mouseX, 0, ofGetWidth(), 50, 350, true);
    
    //float circleX = xCoordinateOnLine(mouseX01, 50, 350);
    //float circleY = yCoordinateOnLine(mouseX01, 100, 300);
    //ofCircle(circleX, circleY, 10);
    
    
    ofPoint circleCenter = pointOnLine(mouseX01, ofPoint(50,100), ofPoint(250, 300));
    ofCircle(circleCenter, 2);
    
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
