#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){



    ofBackground(255, 255, 255);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofEnableAlphaBlending();    
    ofEnableSmoothing();      
    ofSetLineWidth(1);
    
    
//draw multiple of lines 
    
//       ofSetColor(24, 58, 117);
//       for(int i=0; i<50; i++){
//             ofLine(0, i*20, 1024, i*20);
//            }
//     
//       ofSetColor(0,255,0);
//       for(int i=0; i<55; i++){
//              ofLine(i*20, 0 , i*20, 768 );
//             }
    
    
    
    
//draw two dimensional array
    
    ofSetColor(24, 58, 117,200);
   
    for(int i=0; i<100; i++){
        for(int j=0; j<55; j++){
        
             ofCircle(i*15, j*15, 7);
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