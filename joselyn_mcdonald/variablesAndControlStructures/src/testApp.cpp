#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){


}

//--------------------------------------------------------------
void testApp::update(){
    
    theColor.r += 1; 

}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0, 0, 0);
    //ofSetColor(255, 128, 0);
//    ofSetColor(0);
//    ofRect(20, 40, 100, 100);
//    ofRect(50, 100, 200, 200);
//    ofLine(500, 500, 100, 100);
    
//    
//    float redValue = 10.5;
//    //int redValue = 12;
//    unsigned int redValueAsInt = 12; // 0..2^32  (this is how you can get bigger)
//   // long unsigned int redValueAsInt = 12; // 0..2^64  (this is how you can get bigger)
//
//    
//
    
    float speed = 10;
    
   // ofRect(200 + ofGetElapsedTimef()*50, 50, 600, 400);
    
    
    ofSetColor(theColor); 
    ofRect(200 + x, 200, 600, 400);
    x+=1;
    
    
    for (int i=0; i<x; i++){
    
        ofSetColor(i); 
        ofLine(i, 0, i, 500);
    }
    
    
    // the way you write procderal code  using while loops while(i<x)
    
    //ofColor someColor;
    //someColor.r = 255;
    //someColor.g = 0;
    //someColor.b = 128;
    
    //ofSetColor(someColor);
    
    //ofRect(200, 200, 600, 400);
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    if(key == ' '){
        theColor.g=255;
        
    }
  
    printf("hi hi hi");
    
    //theColor.g = 255;
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
    if(key == ' '){
        theColor.g = 0;
    }
    
     // theColor.g = 0;

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
