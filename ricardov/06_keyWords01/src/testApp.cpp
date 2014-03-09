#include "testApp.h"






//in cpp file
/*
Person ric;
ric.height = 170;
ric.job = "designer";


Persons mj;
mj.height = 155;
mj.job = "artist";

*/

void testApp::drawShape(float x, float y){
    ofRect(x, y, 20, 20);
}





//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------
void testApp::update(){

    halfTime = ofGetElapsedTimef() ;
}

//--------------------------------------------------------------
void testApp::draw(){

    
    
//    this.drawShape(400, 400);
    drawShape(400, 400);
    drawShape(halfTime, 400);

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
