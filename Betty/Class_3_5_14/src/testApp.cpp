#include "testApp.h"

//--------------------------------------------------------------
void testApp::drawShape(float x, float y){
    ofRect(x, y, 50, 50);
    ofCircle(x, y, 80);
}


//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------
void testApp::update(){
    halfTime = ofGetElapsedTimef();

}

//--------------------------------------------------------------
void testApp::draw(){
    ofRectangle smallRect;
    smallRect.set(500, 40, 86, 46);
    float a = smallRect.getArea();
    cout << a << endl;
    smallRect.growToInclude(100, 200);
    ofRect(smallRect);
    
    ofLine(halfTime, 0, halfTime, 100);
    drawShape(400, ofGetHeight()/2);

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
