#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
   // ofBackground(255);
ofSetBackgroundAuto(false);

    lastY=ofGetHeight()/2;
    lastX=0;
    y=lastY;

 
}



void testApp:: drawShape(){
    for(int x=0;x<ofGetWidth();x+=step){

        y=ofGetHeight()/2+pow(sin(ofRandom(ofGetHeight())),3)*500;
        if (lastX > 0) {
        ofLine(x,y,lastX,lastY);
        }
        lastX=x;
        lastY=y;
    }
    
}



//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
   ofSetColor(ofRandom(255),ofRandom(255),ofRandom(255));
    ofFill();
    drawShape();

}

//--------------------------------------------------------------
void testApp:: keyPressed(int key){

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
