#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------
void testApp::update(){
    
    //myRectX+=4;

}

//--------------------------------------------------------------
void testApp::draw(){
    ofRect(0, 3, 20, 10);
    ofSetColor(2, 100, 13);
    ofLine(30, 10, 100, 100);
    
    float redValue = 10.5;
    int redValueAsInt = 12; //-2^31..2^31
    string name = "DT Playful systems";
    
    
    ofColor someColor;
    someColor.r =255;
    someColor.g = 0;
    someColor.b = 128;
    ofSetColor(someColor);
    
    float speed =10;
    
    //ofRect(200 ofGetElapsedTimef()*10, 200, 600, 400); //to control the speed add "* speed"
   
    ofRect(200 + x, 200, 600, 400); //x is specified as a global variable in the testApp.h
    x += 1; // x = x+1 (so adds 1 everytime)
    thecolor.r += 1;

    for (int i = 0; i<x; i++){
        ofLine(200 + i, 0, 200 + i, 500);
    }
    
//    switch (x) {  //this is an if statement
//        case 20:
//            //do some stuff
//            break;
//            
//        default:
//            break;
//    }

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key ==' '){
        thecolor.g = 0; //if statement
//    } else if

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    if(key ==' '){
        thecolor.g = 255; //if statement
    }

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
