#include "testApp.h"


void testApp::zigzag(float newY) {

    ofSetColor(newY, 50, 10);
    ofNoFill();
    
    ofPushMatrix();
    ofTranslate(0, newY);
    ofBeginShape();
    
    for(int i=0; i<24; i++){
        for (int j=0; j<200; j++) {
            
            float x = i;
            int y = i%2;
            
            ofVertex(x * 40 , y * 40);
        }
    }
    ofEndShape();
    ofPopMatrix();

}


//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0);
    ofSetBackgroundAuto(false);
    posX = 0;
    posY = 0;
    displacement = 10;
    length = 500;

    angle = 0;
    
}

//--------------------------------------------------------------
void testApp::update(){

    angle += 50;
}

//--------------------------------------------------------------
void testApp::draw(){
    ofPushMatrix();
    ofTranslate(50, 50);
    // a - zigzag
    for (int i=0; i<10; i++) {

        zigzag(60*i);
    }
    ofPopMatrix();
    
    
    // circle
    float posX = ofGetWidth()/2;
    float posY = ofGetHeight()/2;
    
    float newX1 = posX + cos(ofGetElapsedTimef()) * 150;
    float newY1 = posY + sin(ofGetElapsedTimef()) * 150;
    float newX2 = posX + cos(angle) * 350;
    float newY2 = posY + sin(angle) * 350;

    
    ofSetColor(130, 150, 50, 50);
    ofLine(newX1, newY1, newX2, newY2);
    
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
