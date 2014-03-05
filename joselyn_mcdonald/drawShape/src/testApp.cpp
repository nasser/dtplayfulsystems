#include "testApp.h"

ofPoint testApp:: danceStar(ofPoint center, float angle, float length){ //spinning black lined function
    float outerX = x + cos(ofDegToRad(angle)) *length; //sets outer x and y based on the 
    float outerY = y + sin(ofDegToRad(angle)) * length;
    
    ofSetColor(0); // set color to black
    ofLine(center.x, center.y, outerX, outerY); //parameters for function
    


}



//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255, 0, 255); //pink


}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
        ofPoint center;
    
   
    
        center.x = ofGetWidth()/2;
        center.y = ofGetHeight()/2;
   
       for(int i = 0; i<=360;  i+=20){
           
           danceStar(center, i * ofGetElapsedTimef(), 400); //center (x1, y1), angle, length parameters
           
    }
    
    

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key == ' '){
        ofBackground(255);
    }

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    if (key == ' '){
        ofBackground(255, 0, 255);
    }

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
