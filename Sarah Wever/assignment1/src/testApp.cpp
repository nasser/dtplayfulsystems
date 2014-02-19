#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
        font.loadFont("AvenirLTStd-BlackOblique.otf.otf", 150, true, true, true);

}

//--------------------------------------------------------------
void testApp::update(){
    

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackground(50);
    
    ofSetColor(255,102,102);
    float centerX = ofGetWidth()/2.0;
    float centerY = ofGetHeight()/2.0;
    for(float i=0; i<360; i+=1)
    {
        float t = ofDegToRad(i);
        float x = centerX + cos(t) * 300;
        float y = centerY + sin(t) * 300;
        float x2 = (centerX + cos(6*t)*300);
        float y2 = (centerY + sin(6*t)*300);
        ofLine(x, y, x2, y2);
    }
    
    ofSetColor(255);
    font.drawString("Wow. \nSuch Flower. \nMuch Code", ofGetWidth()/2.0, ofGetHeight()/2.0);
    
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
