#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetBackgroundAuto(true);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------

ofPoint testApp::pointOnLine(ofPoint from, ofPoint to, float t) {
    return ((1-t)*from+(t)*to);
}

//--------------------------------------------------------------


void testApp::draw(){

    ofPoint p1, p2;
    
    p1.set(250, 500+ sin(ofGetElapsedTimef())*(-50));
    p2.set(300+ ofGetElapsedTimef()*20, 600);
    
    
    ofPoint p3, p4;
    
    p3=pointOnLine(p1,p2,sin(ofGetElapsedTimef())*(0.1));
    p4.set(100, 200);
    
    ofLine(p3,p4);
    
  
    ofSetColor(255, 0, 0);
    ofCircle(p1, 10);
    
    
  
    ofSetColor(0,255,0);
    ofCircle(p2, 10);
    
        
    ofSetColor(0,0,255);
    ofLine(p1, p2);
  
     
     
    /*
    sin(ofGetElapsedTimef());
    ofSetBackgroundAuto(false); 
     
    */
    
    
    
    
    ofSetColor(255, 155, 55);
    ofPoint a=pointOnLine(p1, p2, (0.2));
    ofCircle(a,2);
    
    ofSetColor(255, 200, 100);
    ofPoint b=pointOnLine(p1, p2, 0.3);
    ofCircle(b,2);
    
    ofSetColor(255, 55, 155);
    ofPoint c=pointOnLine(p1, p2, 0.4);
    ofCircle(c,2);
    
    ofSetColor(55, 155, 155);
    ofPoint d=pointOnLine(p1, p2, 0.5);
    ofCircle(d,2);
    
    ofSetColor(210, 50, 255);
    ofPoint e=pointOnLine(p1, p2, 0.6);
    ofCircle(e,2);
    
    
    ofSetColor(100, 200, 255);
    ofPoint f=pointOnLine(p1, p2, 0.7);
    ofCircle(f,2);
    
    ofSetColor(5, 5, 155);
    ofPoint g=pointOnLine(p1, p2, 0.8);
    ofCircle(g,2);
    
    ofSetColor(100, 25, 50);
    ofPoint h=pointOnLine(p1, p2, 0.9);
    ofCircle(h,2);
    
    
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
