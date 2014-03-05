#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
    ofSetWindowShape(1024, 768);
    ofBackground(10);
    ofSetBackgroundAuto(true);

    w = ofGetWidth();
    h = ofGetHeight();

    // FOR LINES
    x = 0;
    y = 0;
    angle = 0;


}

//--------------------------------------------------------------
void testApp::update(){
    
 
    
}

//--------------------------------------------------------------
void testApp::draw(){

    // 0 - COLOR GRADIENT
    for (int i = 0; i < NUM_POINTS; i++) {
        for (int j=0; j<h; j++) {
  //          ofSetColor(.3*i, .4*j, 150); // gray
//            ofCircle(i, j, .5);
        }
    }

    // 1 - TITLE
        ofSetColor(200, 200, 100); // gray
        ofDrawBitmapString("Homework 5 - Interpolation, Noise (Ricardov):\nA- Noise\nB- Noise Circle\nC- Random ", 20,20);
 

    
    // 1 - NOISE
    for (int i=0; i<w; i++){
        ofRect(i, h/3 * ofNoise(x), 5, 5);
        x = x + .009;
    }

    
    // 2 - NOISE CIRCLE
    for (int i=0; i<w; i++){

        float nY     = sin(x) ;
        float nX     = sin(y) ;

        float circX = w/2 + sin(angle) *  200;
        float circY = h/2 + cos(angle) *  200;

        
        ofRect(circX + nX, circY + nY, 2, 2);
        angle += .08;
    }

    
    // 3 - RANDOM
    for (int i=0; i<w; i++){
        ofRect(i, h-100 + ofRandom(-30, 30), 5, 5);
    }

    
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
