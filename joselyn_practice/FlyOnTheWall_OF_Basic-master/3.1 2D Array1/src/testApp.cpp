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
    ofEnableSmoothing();      
    ofSetLineWidth(1);

    
    ofSetColor(24, 58, 117,80);

    
    for(int i=0; i<50; i++){
        for(int j=0; j<30; j++){
            pos.x=i*30;
            pos.y=j*30;
            mouse.x=mouseX;
            mouse.y=mouseY;
            int distance= (pos - mouse*2).length()/55;     // calculate the distance between mouse and each circle
    
        distance=ofClamp(distance, 0, 60); //restricts a value to be within a specified range defined by values min and max  
            ofCircle(pos, distance);   // map the circle size to distance value 
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