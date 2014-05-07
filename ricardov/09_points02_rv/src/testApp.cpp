#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(50, 20, 10);
    
    
    //2
    myW = ofGetWidth();
    posY = ofGetHeight()/2;
    myCounter = 0;

    

    for (int i=0; i<ofGetWidth(); i++) {
        points.push_back(   ofPoint(i, posY) );
    }
    
    
    
}

//--------------------------------------------------------------
void testApp::update(){
    //1
//    points[3].y = ofGetHeight()/2 + sin(ofGetElapsedTimef()) * 100;
    
    
    //2
    points[myCounter].y = ofGetHeight()/2 + sin(ofGetElapsedTimef()) * 300;
    

    if(myCounter == myW) {
        myCounter = 0;
    }

    myCounter++;
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    //1
    for (int i =0; i<points.size()-1; i++) {
        ofLine(points[i], points[i+1]);
        ofSetColor(150, 150, 10, 100);
        ofCircle(points[i].x, points[i].y, 10);
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
