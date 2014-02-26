#include "testApp.h"

//--------------------------------------------------------------
void testApp::diamond(ofPoint center, float length, float width){
    //line one
    ofLine(center.x - width/2, center.y, center.x, center.y-length/2);
    
    //line two
    ofLine(center.x-width/2, center.y, center.x, center.y+length/2);
    
    //line three
    ofLine(center.x, center.y-length/2, center.x+width/2, center.y);
    
    //line four
    ofLine(center.x+width/2, center.y, center.x, center.y+length/2);

}


//--------------------------------------------------------------
void testApp::boxTriangle(ofPoint corner, float boxSize, float triangleLength){
    ofRect(corner.x, corner.y, boxSize, boxSize);
    ofTriangle(corner.x+boxSize, corner.y, corner.x+boxSize, corner.y+boxSize, corner.x+boxSize+triangleLength, corner.y+boxSize/2);
   
    
}
void testApp::setup(){
    ofBackground(0, 0, 0);
    
    ofSetFrameRate(30);
    
     ofSetColor(255, 255, 255);
    ofPoint center (50,50);
    boxTriangle(center, 50,100);
    
}

//--------------------------------------------------------------
void testApp::update(){

}

//-------------------------------------------------------------
void testApp::draw(){
    
    int length = ofGetWindowHeight()/1.4;
    ofSetColor(255, 255, 255);
    
    for(int i = 0; i < ofGetWindowWidth(); i++){
        ofPoint center;
        center.x = ofGetWindowWidth()/2 + cos(i)*100;
        center.y = ofGetWindowHeight()/2 + sin(i)*100;
        ofSetColor(ofRandom(100,255), ofRandom(100, 255), ofRandom(100,255));
        diamond(center, length, length);
    };
    
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
