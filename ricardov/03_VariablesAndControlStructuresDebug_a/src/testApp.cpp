#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(200, 200, 0);
    ofSetBackgroundAuto(false);
    posX = 0;
    posY = 0;
    a = 3;
    colorLine.r = 0;
    colorLine.g = 0;
    colorLine.b = 0;

}

//--------------------------------------------------------------
void testApp::update(){
    posX =  cos(a) *200;
    posY =  sin(a) *200;
    sz = cos(a)*20;
    
    cout << posX;
    
    a+= 0.01;
    
    speed = 10;
    
    x = x+5;

    colorRect.r += 1;

}

//--------------------------------------------------------------
void testApp::draw(){
    //RECT
    ofSetColor(50, 50, 0, 20);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());

    //CIRCLE
    ofColor someColor;
    someColor.r = 200;
    someColor.g = 0;
    someColor.b = 0;
    ofSetColor(colorRect);
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofCircle(posX, posY, sz);
    
    //ofGetElapsetTimef
//    float speed = 10;
//    ofRect(20 + ofGetElapsedTimef()*speed, 300, 200, 200);

    //RECT
    ofSetColor(someColor);
    
    ofRect(20 + x, 300, 200, 200);
    
    ofPopMatrix();
    
    //FOR LOOP
    ofSetColor(colorLine);
    for (int i=0; i<100; i++){
        ofLine(2+i, 20, 2+i, 300);
    }

    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key == 'a'){
        colorLine.b = 200;
    }
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    colorLine.b = 0;

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
