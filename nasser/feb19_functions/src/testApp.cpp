#include "testApp.h"

void testApp::drawTwoLines(float spacing, float x1, float y1, float x2, float y2) {
    ofLine(x1, y1, x2, y2);
    ofLine(x1, y1 + spacing, x2, y2 + spacing);
}

ofPoint testApp::drawAngledLine(ofPoint center, float angle, float length) {
    ofPoint outer;
    outer.set(cos(ofDegToRad(angle)), sin(ofDegToRad(angle)));
    ofLine(center, center + outer * length);
    
    return center + outer * length;
}

//--------------------------------------------------------------
void testApp::setup(){
    // cout << ofGetWidth() << endl;
    // ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
    
    clickBox.set(0, 0, 100, 100);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    // drawTwoLines(20 + sin(ofGetElapsedTimef() * 20) * 50, 0, 0, 100, 200);
    ofPoint center;
    center.set(ofGetWidth()/2, ofGetHeight()/2);
    
    ofPoint outerPosition = drawAngledLine(center, 45 + ofGetElapsedTimef() * 50, 100);
    
    clickBox.setPosition(outerPosition);
    
    ofRect(clickBox);
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
    if(clickBox.inside(x, y)) {
        cout << "clicked me!" << endl;
    }
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
