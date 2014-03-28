#include "testApp.h"


void testApp::drawGram(ofPoint position, int radius, int internalLines, ofColor lineColor, int strokeWeight){
    ofSetColor(lineColor);
    ofSetCircleResolution(internalLines);
    ofCircle(position, radius);

}

//--------------------------------------------------------------
void testApp::setup(){
    offsetJump = 30;
    scaleJump = 1;
    scale = 2;
    pointValue = 3;
    cout << "USE WASD TO CONTROL OFFSET" << endl;
    cout << "USE LEFT AND RIGHT TO CONTROL NUMBER OF POINTS" << endl;
    cout << "USE Q AND E TO CONTROL SCALE" << endl;
    ofBackground(150,150,150);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    for (int i = 0; i < 100; i++){
        ofPoint randomPos;
        randomPos.set(ofRandom(0, ofGetWidth()) + offsetX, ofRandom(0, ofGetHeight() + offsetY));
        ofColor myColor;
        myColor.set(i, ofRandom(0,255), i);
        drawGram(randomPos, i*scale, pointValue, myColor, 5);

    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key == OF_KEY_LEFT){
        if (pointValue > 2){
            pointValue -= 1;}
    } else if (key == OF_KEY_RIGHT){
        pointValue += 1;
    }
    if (key == 'w') {
        offsetY -= offsetJump;
    }
    if (key == 's') {
        offsetY += offsetJump;
    }
    if (key == 'a') {
        offsetX -= offsetJump;
    }
    if (key == 'd') {
        offsetX += offsetJump;
    }
    if (key == 's') {
        offsetY += offsetJump;
    }
    if (key == 'q') {
        scale -= scaleJump;
    }
    if (key == 'e') {
        scale += scaleJump;
    }
    scale = ofClamp(scale, 1, 10000);

    cout << "OFFSET = ("<<offsetX<<","<<offsetY<<")"<<endl;
    cout << "POINTS = "<<pointValue<<endl;
    cout << "SCALE  = "<<scale<<endl;


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
