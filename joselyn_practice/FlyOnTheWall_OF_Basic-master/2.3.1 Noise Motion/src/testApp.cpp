#include "testApp.h"
//made by Yinan Zhang for the class "FLy on the wall" between Parsons and Tongji University


//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255, 255, 255);
     
    ofSetFrameRate(100);

    //openFrameworks will draw the background automatically each frame, unless you disable it here:
    //ofSetBackgroundAuto(false);  
    
  
    
    
    // Here initialize every random starting time of     
    // each circle in the "Multiple Motion Circle" example

    for (int i = 0; i < NUM; i++){
     time[i]= ofRandom(20);                        
    }

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    
    
     //--------------------------- Single Motion Circle

//    ofSetColor(30,125,150);
//    float posx =ofNoise(ofGetElapsedTimef())*1024;
//    float posy = ofNoise(ofGetElapsedTimef()+1000)*768;
//    ofCircle(posx, posy, 30);

    
    
    
    //--------------------------- Multiple Motion Circle
    ofEnableAlphaBlending();
    ofSetColor(0,0,0,100);
    for(int i=0; i<NUM; i++){
      
        time[i]+=0.01;
        float posx =ofNoise(time[i])*1024;
        float posy =ofNoise(time[i]+1000)*768;
        ofCircle(posx, posy, 10);
        }
    ofDisableAlphaBlending();
    
    
    
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