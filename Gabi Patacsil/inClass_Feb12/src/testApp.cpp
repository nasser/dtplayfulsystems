#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    //ofBackground(0,0,0);
    ofSetColor(255,120,100);
    
    x = 100;
    for (i=1; i<10; i++){
        
        ofLine(100,100,500,x);
        x += 50;
        
    }
    
}

//--------------------------------------------------------------
void testApp::update(){
    

}

//--------------------------------------------------------------
void testApp::draw(){

    

    
//    float redValue = 10.5;
//    long int redValueAsInt = 12;
//    string name = "DT Playful Systems";
//    
//
//    ofSetColor(theColor);
//    
//    ofRect(200+ x,200,600,400);
//    ofLine(500,500,100,100);
//
//    x += 5;
    
    
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
