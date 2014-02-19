#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    myfont.loadFont("coders_crux.ttf", 12);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0, 0, 0);
    ofSetColor(255, 255, 255);
    myfont.drawString("Intricate Geometric Shape", 25,30);
    myfont.drawString("CREATIVE CODING CLASS DT", 25,42);
    myfont.drawString("Parsons, The New School", 25,54);
    myfont.drawString("New York - 02/18/2014", 25,66);
    myfont.drawString("fito_segrera", 25,78);
    ofNoFill();

    for(int i = 0; i <500; i+=10){
        ofLine(leftPointX + i, leftPointY - i/factor, topPointX + i/factor, topPointY + i);
        ofLine(topPointX + i/factor, topPointY + i, rightPointX - i, rightPointY + i/factor);
        ofLine(rightPointX - i, rightPointY + i/factor, bottomPointX - i/factor, bottomPointY - i);
        ofLine(bottomPointX - i/factor, bottomPointY - i, leftPointX + i, leftPointY - i/factor);
    }
    
    for(int i = 0; i <500; i+=10){
        ofLine(leftPointX2 + i, leftPointY2 - i/factor2, topPointX2 + i/factor2, topPointY2 + i);
        ofLine(topPointX2 + i/factor2, topPointY2 + i, rightPointX2 - i, rightPointY2 + i/factor2);
        ofLine(rightPointX2 - i, rightPointY2 + i/factor2, bottomPointX2 - i/factor2, bottomPointY2 - i);
        ofLine(bottomPointX2 - i/factor2, bottomPointY2 - i, leftPointX2 + i, leftPointY2 - i/factor2);
    }
    
    for(float i = 0; i <14; i+=0.5){
        ofEllipse(ofGetWidth()/2, ofGetHeight()/2, i*i, i*i);
    }
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
