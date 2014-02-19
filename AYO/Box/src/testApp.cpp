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
     lineH=0;
    lSx=0;
    lSy=0;
    lEx=0;
    lEy=0;
    lSx2=0;
    lSy2=0;
    lEx2=0;
    lEy2=0;

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255);
    
    
    for(int i=0;i<50;i++){
       ofLine(i*lSx,lSy,lEx,i*lEy);
        lEy++;
        lSy++;
        
    if (lEy>50){
        lEy=0;
        lSx++;
        
    }
        
    }
    
    
    for(int i=0;i<50;i++){
        ofLine(i*lSy2,lSx2,lEx2,i*lEy2);
        lEy2++;
        lSy2++;
        
        if (lEy2>50){
            lEy2=0;
            lSx2++;
            
        }
        
    }
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
//    for (int i=0; i<ofGetWidth()/2+200; i++) {
//        ofLine(i*lSx,lSy,lEx,i*lEy);
//        lEy=+5;
//        lSx=+5;
//    }
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    lSy=y;
    lSx=x;
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