#include "testApp.h"

void testApp::drawStar(float x1, float y1, float angle, float length) {

    float x2 =cos(ofDegToRad(angle))*length;
    float y2 =sin(ofDegToRad(angle))*length;

    ofLine(x1, y1, x2, y2);

}


//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackground(255, 255, 255);
    ofColor colorOne;
    ofColor colorTwo;
    colorOne.set (255, 255, 255);
    colorTwo.set (251, 155, 201);
    ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_CIRCULAR);
   
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    //circle
    ofSetColor(200,200,200,40);
    ofCircle(0, 0, 300);
    
    //lines
    ofSetColor(171, 155, 202, 100);
    ofSetLineWidth(10);
    drawStar(0,-300,45,300);
    drawStar(0,-300,135,300);
    
    ofRotate(180);
    drawStar(0,-300,45,300);
    drawStar(0,-300,135,300);
        
    ofRotate(90);
    drawStar(0,-300,45,300);
    drawStar(0,-300,135,300);
  
    ofRotate(180);
    drawStar(0,-300,45,300);
    drawStar(0,-300,135,300);
    
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
