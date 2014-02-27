#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    backr=22;
    backg=40;
    backb=200;
    backa=4;
    width=800;
    height=600;
    speed1=10;
    lineW=0;
    lineInt=0;
    lSx=0;
    lSy=20;
    lEx=0;
    lEy=0;
    l2Sx=0;
    l2Sy=0;
    l2Ex=0;
    l2Ey=0;
    
//    lSx=ofGetWidth()/2+200;
//    lSy=ofGetHeight()/2-200;
//    lEx=ofGetWidth()/2+200;
//    lEy=ofGetHeight()/2+200;
    
    ofBackground(backr,backg,backb,backa);

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255);
    //ofRect(50,speed1,50,50);
    //ofRect(0,0,ofGetWidth()/2,ofGetHeight()/2);
   
    speed1++;
//    lEx+=10;
//    lEy+=10;
    
//    for (int i=0; i<ofGetHeight()/2+200; i++) {
//         ofLine(i*lSx,i*lSy,i*lEx,i*lEy);
//        lSy=+5;
//        lEx=+5;
//    }
    
    
    for (int i=0; i<600; i++) {
        ofLine(lSx,i*lSy,i*lEx,lEy);
        ofLine(800-l2Sx,i*l2Sy,800-(i*l2Ex),l2Ey);
        
        lSy=20;
        lEx=20;
        l2Sy=20;
        l2Ex=20;
    }
    

if(lSx>800){
    lSx=0;}
    
    if(l2Sx<0){
        l2Sx=800;}
    
    
  cout << "keyPressed " << lineInt << endl;
    
    lSy++;
    lSx++;
    l2Sx--;
    lineInt++;
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    lSx=x;
    lEy=y;
    l2Sx=x;
    l2Ey=y;
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