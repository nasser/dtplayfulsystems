#include "testApp.h"


float ourCircle(ofPoint p, float r) {

    ofCircle(p, r);
    
    return r;

}


ofPoint testApp::pointOnLine(ofPoint from, ofPoint to,float t ) {
                                                                 
        return (1 -t ) * from + t * to;

}



//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofPoint p1, p2;
    p1.set(30, 30);
    p2.set(100, 100);
    
    
    
    
    // 1
//    ofCircle(   pointOnLine(p1, p2, 0.5),  5 );
    

    // 2
    float radius = ourCircle(  pointOnLine(p1, p2, ofGetElapsedTimef(), 5)    );
    ofLine( 10 * radius, 10 * radius , 650, 500);
    
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
