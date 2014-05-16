#include "testApp.h"
//made by Yinan Zhang for the class "FLy on the wall" between Parsons and Tongji University


//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255, 255, 255);
    ofSetFrameRate(100);
    
    loopingSound.loadSound("wind.mp3");
    loopingSound.setLoop(true);
    loopingSound.setVolume(0.5);
	loopingSound.play();
    
    time=0;

}

//--------------------------------------------------------------
void testApp::update(){

     time+=0.01;

    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    //--------------------------- Multiple Motion Circle
    ofSetColor(150);
    for(int i=0; i<NUM; i++){
        float posx =5+i*5;  
        float posy =ofNoise(time+i*0.005)*768;
        ofCircle(posx, posy, 3);
    }

    //--------------------------- Mapping Y position to pitch    
    float posy1 =768-ofNoise(time+NUM*0.005)*768;
    float pitch = ofMap(posy1*3, 0, (float)ofGetHeight(), 1.5, 0.1);
    loopingSound.setSpeed(pitch);
    
    
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