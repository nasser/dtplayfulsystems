#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofBackground(255, 255, 255);
    ofSetCircleResolution(100);
    
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofEnableAlphaBlending();    
    ofSetColor(24, 58, 117,150);

    ofEnableSmoothing();      
    ofSetLineWidth(1);
    
    
//draw multiple of lines
    for(int i=0; i<12; i++){
             ofLine(0, i*20, 1024, 150);
            }
    
//draw multiple of circles
    for(int i=0; i<6; i++){
             ofCircle(200, 300+i*50, 50);
           }
    
    
//draw multiple of rectangles
    for(int i=0; i<5; i++) {
          ofRect(300, 270+i*80, 200, 50);
        }  
    
    
//    for (<#initialization#>; <#condition#>; <#increment#>) {
//        <#statements#>
//    }
    
       

    

    
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