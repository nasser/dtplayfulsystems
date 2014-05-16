#include "testApp.h"

void testApp::ofDrawRotatingThings(float x1, float y1, float x2, float y2, float radius){
    
    ofRotate(50*ofGetElapsedTimef(), 1, 0.5, 0); //rotates the coordinate system 50 degrees along the x-axis and 25 degrees on the y-axis
    ofRect(x1, y1,radius,radius);
    ofRect(x1, y1,radius,radius);
    
    for (int i = 0; i<100; i++){
        ofSetColor(ofGetElapsedTimef()*i);
        ofRect(x1*i +10, y1*i, radius, radius);
        
 
        
   
    
}
}

//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofDrawRotatingThings(10,10, 40, 10, 40);
    
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
