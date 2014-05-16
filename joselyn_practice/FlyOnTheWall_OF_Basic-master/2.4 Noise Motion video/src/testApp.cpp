#include "testApp.h"
//made by Yinan Zhang for the class "FLy on the wall" between Parsons and Tongji University


//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255, 255, 255);
    ofSetFrameRate(100);
    
    shipMovie.loadMovie("tracksourcesmall.mp4");
    shipMovie.play();
    
    time=0;

}

//--------------------------------------------------------------
void testApp::update(){

     time+=0.01;
     
     shipMovie.update();
     
     position=ofNoise(time);
   
     //cout << position <<endl;
     mapPosition=ofMap(position, 0.3, 0.7, 0.3, 0.7);  //Map the noise value to movie time position
     shipMovie.setPosition(mapPosition);
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(255);
    shipMovie.draw(20,20);
    ofSetColor(200);
    ofRect(670, position*500,20,20);
    
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