#include "testApp.h"

int myCircleX;
int myCircleY;
int myCircleRadius; 

//--------------------------------------------------------------
void testApp::setup(){
    
    myCircleX= 300;
    myCircleY = 300;
    myCircleRadius = 100;

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofCircle(myCircleX, myCircleY, myCircleRadius);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
    cout<< "mouseMoved:" << x << "," << y << endl; 

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
    cout<< "mouseDragged" << x<< "," << y << "button: " << button << endl; 

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
    myCircleRadius++; 
    
    cout<<"mousePressed: " << x << "," << y << "button" << button << endl; 

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

    cout<<"mouseReleased: " << x << "," << y << "button" << button << endl;

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
