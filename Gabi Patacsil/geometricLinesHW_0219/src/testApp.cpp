#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
theColor.set(0, 0, 0);
    ofBackground(0, 0, 0);
    


}

//--------------------------------------------------------------
void testApp::update(){


}

//--------------------------------------------------------------
void testApp::draw(){

  //background sweep
    ofSetColor(100, 125, 125);
    for (int i=0; i<400; i+=5) {
        ofLine(1000-(i/9), 500+i, 200-i, 600);
    }
  //large star
    ofSetColor(230, 250, 255);
    for (int i=0; i<300; i+=8) {
        ofLine(200+(i/7), 100+i, 200+i, 450);
    }

    for (int i=0; i<300; i+=8) {
        ofLine(400-(i/7), 100+i, 400-i, 450);
    }

    for (int i=0; i<300; i+=8) {
        ofLine(200+(i/7), 700-i, 200+i, 450);
    }

    for (int i=0; i<300; i+=8) {
        ofLine(400-(i/7), 700-i, 400-i, 450);
    }
    
    for (int i=0; i<300; i+=8) {
        ofLine(10+i, 450-(i/7), 400, 400-i);
    }
    
    for (int i=0; i<300; i+=8) {
     ofLine(10+i, 450+(i/7), 400, 400+i);
    }

    for (int i=0; i<300; i+=8) {
        ofLine(600-i, 450-(i/7), 200, 400-i);
    }
    for (int i=0; i<300; i+=8) {
        ofLine(600-i, 450+(i/7), 200, 400+i);
    }
    
  //small star

    for (int i=0; i<100; i+=6) {
        ofLine(800+(i/8), 50+i, 800+i, 150);
    }
    
    for (int i=0; i<100; i+=6) {
        ofLine(850-(i/8), 50+i, 850-i, 150);
    }
    
    for (int i=0; i<80; i+=6) {
        ofLine(850-(i/7), 200-i, 850-i, 150);
    }
    
    for (int i=0; i<80; i+=6) {
        ofLine(800+(i/7), 200-i, 800+i, 150);
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