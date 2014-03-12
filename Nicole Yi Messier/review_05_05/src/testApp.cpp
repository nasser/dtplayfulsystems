#include "testApp.h"



//drawShape is inside the class testApp
void testApp:: drawShape(float x, float y){
    
    ofRect(x, y, 50, 50);
    ofRect(x + 100, y, 50, 50);
    
}

//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------
void testApp::update(){
    halfTime = ofGetElapsedTimef()/2;
}

//--------------------------------------------------------------
void testApp::draw(){
    //using a returned value
    ofRectangle smallRect;
    smallRect.set(0, 0, 3, 5);
    float a = smallRect.getArea();
    //side effecting method call
    smallRect.growToInclude(100, 200);
    
    //drawing line at x = half time
    ofLine(halfTime, 0, halfTime, 100);
    
    
    
    //drawShape(400, 300);
    drawShape(halfTime, ofGetHeight()/2);
    
    cout << "&halftime: ";
    cout << &halfTime << endl;

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
