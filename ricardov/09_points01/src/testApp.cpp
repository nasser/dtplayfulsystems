#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    //1
    points.push_back( ofPoint(0, ofGetHeight()/2) );
    points.push_back( ofPoint(10, ofGetHeight()/2) );
    points.push_back( ofPoint(20, ofGetHeight()/2) );
    points.push_back( ofPoint(30, ofGetHeight()/2) );
    points.push_back( ofPoint(40, ofGetHeight()/2) );
    points.push_back( ofPoint(50, ofGetHeight()/2) );
    points.push_back( ofPoint(500, ofGetHeight()/2) );
    
    
}

//--------------------------------------------------------------
void testApp::update(){
    //1
    points[3].y = ofGetHeight()/2 + sin(ofGetElapsedTimef()) * 100;
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    //1
    for (int i =0; i<points.size()-1; i++) {
        ofLine(points[i], points[i+1]);
    }

    
    //1
    int amt = 10000;
    float a = 0 + sin ( ofGetElapsedTimef() );
    float b= 0.5;
    float c = 0.9;
    float d = -2.1;
    float x0, y0, x1, y1 =0;
     x0 = y0 = x1 = y1 = 0;
    
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofScale(50, 50);

    
    
    for ( int i=0; i< 10; i++) {
       // <#statements#>
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
