#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(50, 0, 40);
    

    time = ofGetElapsedTimef();
    myW = ofGetWidth();
    myH = ofGetHeight();
    posX = ofGetWidth()/2;
    posY = ofGetHeight()/2;
 
    
//    for (int i=0; i<ofGetWidth(); i++) {
//        myPoint.push_back(   ofPoint(posX, posY) );
//    }
//    

//        myPoint(    ofPoint(posX, posY) );
    
    
    
}

//--------------------------------------------------------------
void testApp::update(){
    
//    posX = ofGetWidth()/2 + sin(time) *100;
//    posY = ofGetHeight()/2 + cos(time) *100;

    for (int i=0; i<100; i++) {

        myPoint[i].y = ofGetHeight()/2 + sin(ofGetElapsedTimef()) * 300;
        myPoint[i].x = posX;
        myPoint[i].y = posY;
    
    }
    

}

//--------------------------------------------------------------
void testApp::draw(){
    
    for (int i =0; i<myPoint.size()-1; i++) {
        ofSetColor(150, 150, 10, 100);

        ofLine(myPoint[i], myPoint[i+1]);
     
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
