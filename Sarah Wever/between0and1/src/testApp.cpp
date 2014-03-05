#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------
void testApp::update(){
}

    float testApp::xCoordinateOnLine(float t, float x1, float x2){
        
        t = ofClamp(t, 0, 1);
        
        return (x2 - x1) * t + x1;
        
    }
    
    float testApp::yCoordinateOnLine(float t, float x1, float x2){
        
        t = ofClamp(t, 0, 1);
        
        return (y2 - y1) * t + y1;
        
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    
    float mouseX01 = ofClamp((float)mouseX / ofGetWidth(), 0, 1);
    
    cout << mouseX01 << endl;
    
    int mingrey = 0;
    int maxgrey = 150;
    
    float g = (maxgrey  - mingrey) * mouseX01 + mingrey;
    
    ofBackground(50, 50, g);
    
//    float circleX = ofMap(mouseX, 0, ofGetWidth(), 50, 350, true);
//    float circleY = ofMap(mouseY, 0, ofGetWidth(), 450, 300 + sin(ofGetElapsedTimef() * 5)*20, true);

    float circleX = xCoordinateOnLine(mouseX01, 50, 350);
    float circleY = yCoordinateOnLine(mouseX01, 100, 300);
    
    ofCircle(circleX, circleY, 40);

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
