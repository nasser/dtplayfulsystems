#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    // - - - - - - - - - - - - - - - - - - - - - - - -
    // 1 -LOOP COLOR
//    int x = mouseX/10;
//    int y = mouseY/10;

    int x = 10;
    int y = 10;

    for (int i=0; i < 255; i++) {
        for ( int j=0; j < 255; j++) {
            
            ofSetColor(i, j, 20);
            ofRect(x * i, y * j, 10, 10);
        
        }
    }

    // - - - - - - - - - - - - - - - - - - - - - - - -
    // 2 -
    float mouseX01 = ofClamp( (float)mouseX / ofGetWidth(), 0, 1);
    
    int minGrey = 0;
    int maxGrey = 255;
    
    float g = (maxGrey - minGrey) * mouseX01 + minGrey;

    ofPushMatrix();
    ofSetColor(g, g, g);
    ofRect(700, 20, 200, 200);
    ofPopMatrix();
    
    // - - - - - - - - - - - - - - - - - - - - - - - -
    // 3 -

    //true enables clamping
    float circleX = ofMap(mouseX, 0, ofGetWidth(), 50, 350, true);
    float circleY = ofMap(mouseY, 0, ofGetHeight(), 100, 350, true);
    
    ofCircle(circleX, circleY, 20);
    
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
