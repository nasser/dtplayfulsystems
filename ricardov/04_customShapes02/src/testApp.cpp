#include "testApp.h"


void testApp::myForm(float _x, float _y) {

    ofPushMatrix();
    ofTranslate(-150, -150);

    ofBeginShape();//begin drawing the shape -- It's a big star
        ofVertex(150 + _x, 10 + _y);
        ofVertex(190 + _x, 100 + _y);
        ofVertex(290 + _x, 100 + _y);
        ofVertex(200 + _x, 175 + _y);
        ofVertex(265 + _x, 290 + _y);
        ofVertex(150 + _x, 215 + _y);
        ofVertex(35 + _x,  290 + _y);
        ofVertex(100 + _x, 175 + _y);
        ofVertex(10 + _x,  100 + _y);
        ofVertex(110 + _x, 100 + _y);
    ofEndShape();//end of the shape
    ofPopMatrix();
    
}


//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0);
    ofSetBackgroundAuto(false);

    w = ofGetWidth();
    h = ofGetHeight();

    angle01 = 0;
    
}

//--------------------------------------------------------------
void testApp::update(){
    //BACKGROUND SQUARE
    ofSetColor(20, 20, 0, 20);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());

    angle01 += 0.05;

}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    // CURVES - - - - - - - - - - - - - - - - - - - - - - - -
    float sz = 200; //Size of curve area
    float x = w/2 + sin(angle01 * cos(10) )  * sz;
    float y = h/2 + cos(angle01 * sin(10) ) * sz;
    
    
        ofSetColor(200*x, 100, 20, 100);
        myForm(x, y);
//      ofCircle(x, y, 1);

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
