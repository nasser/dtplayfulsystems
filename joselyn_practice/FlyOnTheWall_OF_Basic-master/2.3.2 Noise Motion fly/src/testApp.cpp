#include "testApp.h"

//made by Yinan Zhang for the class "FLy on the wall" between Parsons and Tongji University

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255, 255, 255);
     
    ofSetFrameRate(100);

    fly.loadImage("fly.png");
    
    time=0;
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    time+=0.01;
    
    posx =ofNoise(time)*1024;
    posy = ofNoise(time+10)*768;
    float nextposx=ofNoise(time+0.01)*1024;
    float nextposy=ofNoise(time+10+0.01)*768;
    
    //compare the X and Y value difference of the two closest positions
    float dx= nextposx-posx;
    float dy= nextposy-posy;
    
    //calculate the angle (in radians) between the two positions
    angle = atan2(dy, dx);
    
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofEnableAlphaBlending();
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    
    ofPushMatrix();
    ofTranslate(posx, posy);
    ofRotateZ(angle * RAD_TO_DEG);  //turn the radians value to degree value by "RAD_TO_DEG",  set up the rotation of the fly
    
	fly.draw( 0,0);          // draw the fly
	
    
    //ofSetColor(0);
    //ofRect( 0,0, 40,10); // this rectangle shows the same idea   
    
    ofPopMatrix();
    
    
    
    
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