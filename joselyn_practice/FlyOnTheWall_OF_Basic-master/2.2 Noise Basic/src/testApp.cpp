#include "testApp.h"






//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255, 255, 255);
     
    //ofSetFrameRate(500);

    //openFrameworks will draw the background automatically each frame, unless you disable it here:
    //ofSetBackgroundAuto(false);  
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    

    
    
     //--------------------------- greycolor rectangles

     // "ofNoise(ofGetElapsedTimef())": this is to get a noise value by a increase of time (the time line)
     //  You can also replace "ofGetElapsedTimef()" by a constant increasing variable
    
    ofSetColor(ofNoise(ofGetElapsedTimef())*300);   //map the noise value to the grey color of big rectangle
    ofRect(0,0, ofGetWidth(), ofGetHeight());       //draw the big rectangle
    

    ofSetColor(255-ofNoise(ofGetElapsedTimef())*300);    //set up the inversed the color of the small rectangle
    ofRect(ofGetWidth()/2-60,  ofGetHeight()/2-60,120,120);    //draw the small rectangle

    
    

    
    //--------------------------- Draw grid with noise color   
        

//        for(int i=0; i<100; i++){
//            for(int j=0; j<55; j++){
//                ofSetColor(ofNoise(ofGetElapsedTimef()+i*0.005)*350);
//                ofRect(i*15, j*15, 12, 12);
//            }
//          }

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