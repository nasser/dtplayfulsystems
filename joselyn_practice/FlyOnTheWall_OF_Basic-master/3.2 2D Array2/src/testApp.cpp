#include "testApp.h"
//made by Yinan Zhang for the class "FLy on the wall" between Parsons and Tongji University

//--------------------------------------------------------------
void testApp::setup(){



    ofBackground(255, 255, 255);
    ofSetCircleResolution(100);
    
        for(int i=0; i<NUM; i++){
         pos[i].set(ofRandom(0,ofGetWidth()), ofRandom(0,ofGetHeight()));   // set the random position of every circle
        }
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofEnableAlphaBlending();    
    ofEnableSmoothing();      
    ofSetLineWidth(1);

    
    
//draw two dimensional array
    
    ofSetColor(24, 58, 117,50);
   
    ofSeedRandom(0);
    for(int i=0; i<NUM; i++){
            mouse.x=mouseX;
            mouse.y=mouseY;
            int distance= (pos[i] - mouse).length()/6;
            distance=ofClamp(distance, 0, ofRandom(5,100));
            ofCircle(pos[i], distance);        
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