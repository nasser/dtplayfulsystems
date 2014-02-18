#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255);
    ofSetBackgroundAuto(false);
    posX = 0;
    posY = 0;
    displacement = 10;
    length = 500;
    newLength;

    
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
        ofSetColor(0);
    ofRect(20, 20, 20, 20);
    ofNoFill();
    ofTranslate(100, 100);
    
    ofBeginShape();
    for(int i=0; i<20; i++){
        float x = i;
        int y = i%2;
        ofVertex(40+x*40, 40+y*40);
//        ofVertex(x+ i*40, 40+y*40);
    }
    ofEndShape();
    
    
    /*
    ofBeginShape();
    for(int i=0; i<100; ++i){
        for(int j=0; j<20; ++j){
            x = 10+i ;
            y = 10+j ;

            float myX = x * i;
            float myY = y *j;
            ofVertex(myX, myY);
        }
    }
    ofEndShape();
    */
    
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
