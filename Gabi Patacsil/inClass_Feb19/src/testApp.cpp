#include "testApp.h"

//writing a function
void testApp::drawTwoLines(float spacing, float x1, float y1, float x2, float y2) {
    ofLine(x1, y1, x2, y2);
    ofLine(x1, y1 + spacing, x2, y2 + spacing);
    
}

ofPoint testApp::drawAngledLine(ofPoint center, float angle, float length){
    ofPoint outer;
    outer.set(cos(ofDegToRad(angle)), sin(ofDegToRad(angle)));
    ofLine(center, center + outer * length);
    
    return center + outer * length;
}


//--------------------------------------------------------------
void testApp::setup(){

    cout << ofGetWidth() << endl;
    
    clickBox.set(0,0,100,100);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofPoint center;
    center.set(ofGetWidth()/2, ofGetHeight()/2);

    
    ofPoint outerPosition = drawAngledLine(center, 45 + (ofGetElapsedTimef()*20), 100); //trig math in oF uses radians
    
    drawTwoLines((sin(ofGetElapsedTimef())*20), 100, 100, 400, 200);
    
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
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    if (clickBox.inside(x,y)) {
        cout << "clicked me!";
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