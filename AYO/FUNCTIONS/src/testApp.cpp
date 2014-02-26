#include "testApp.h"

void testApp::drawlines (float spacing, float x1, float x2, float y1, float y2){
    ofLine (x1, x2, y1,y2);
    ofLine (x1+spacing, x2, y1+spacing,y2);


}


void testApp::drawangles (float x, float y, float angle, float lenght){
    ofPoint outer;
     outer.x = x +cos(ofDegToRad(angle))* lenght;
     outer.y = y +sin(ofDegToRad(angle))* lenght;
    
    ofLine(center,outer);
}
    
    


//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofPoint center;
     center.y =ofGetWidth ()/2;
    center.y =ofGetHeight()/2;
    
    drawlines (10, 10, 100, 100, 100);
    drawangles(center,45+ofGetElapsedTimef() *5,100);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

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