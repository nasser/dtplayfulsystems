#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
//    ofBackground(172, 19, 111);
    ofBackground(0, 0, 0);
    ofSetFrameRate(5);


}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
 
    // FEATHER SHAPE
//for(int i = 30; i < 1800; i+=10){
//    for(int x = 10; x < 780; x +=40){
//        ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
//        ofSetColor(80, 0, ofRandom(0, 200));
////        ofSetLineWidth(2);
//       ofLine(10+i, x, ofGetWidth()*1.5, ofGetHeight()/4+i);
//    }
//}
    
    //DIAMOND SHAPE
    ofSetColor(0, 0, 0);
    //ofSetColor(80, 0, ofRandom(0, 200));

    for( int i= 10; i < 510; i+=10){ //510 gives it a complete mesh diamond
        ofSetColor(172, 19, ofRandom(50, 250));
        ofSetLineWidth(ofRandom(0.5, 2.5));
        ofLine(10+i, ofGetHeight()/2, ofGetWidth()/2, ofGetHeight()/2+i); //left down
        ofLine(ofGetWidth()-i, ofGetHeight()/2, ofGetWidth()/2, ofGetHeight()/2-i); //right up
        ofLine(10+i, ofGetHeight()/2, ofGetWidth()/2, ofGetHeight()/2-i); //left up
        ofLine(ofGetWidth()-i, ofGetHeight()/2, ofGetWidth()/2, ofGetHeight()/2+i); //ridght down
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
