#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255, 255, 255);
    ofSetVerticalSync(TRUE);
 
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    

//These are three examples showing basic idea of using ofRandom, you can activate each of them and deactivate others to view differences:
    
    
    
    //--------------------------- wiggling rectangle

    ofSetColor(0);
    ofSetRectMode(OF_RECTMODE_CENTER);
    int posx=ofGetWidth()/2+ofRandom(-3,3);    // set up the randomness of position Y
    int posy=ofGetHeight()/2+ofRandom(-3,3);   // set up the randomness of position Y
    ofRect(posx, posy , 30, 30);
    
    
    
    
   //--------------------------- colored grids (fixed color for each rectangle)
   
//   //Seeds the random number generator to a value passed in (val),
//   //so that random numbers will always be the same using the same seed.
//    ofSeedRandom(0);    
//   
//    
//    for(int i=0; i<100; i++){
//        for(int j=0; j<55; j++){
//            
//            // set up the randomness of R,G,B value
//            ofSetColor(ofRandom(0,255), ofRandom(0,255),ofRandom(0,255));
//            ofRect(i*15, j*15, 12, 12);
//        }
//    }

    
    
    
   //--------------------------- colored grids chaos
//    for(int i=0; i<100; i++){
//        for(int j=0; j<55; j++){
//            ofSetColor(ofRandom(0,255), ofRandom(0,255),ofRandom(0,255));
//            ofRect(i*15, j*15, 12, 12);
//        }
//      }
    
    
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
    ofSetFrameRate(1);

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