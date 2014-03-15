#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------
void testApp::update(){

    
}

//--------------------------------------------------------------


void testApp::star(float starx, float stary, float size){
    
    ofBeginShape();
    ofVertex(starx, stary-size);
    ofVertex(starx+size/10, stary-size/5);
    ofVertex(starx+size/2, stary-size/2);
    ofVertex(starx+size/5, stary-size/10);
    ofVertex(starx+size, stary);
    ofVertex(starx+size/5, stary+size/10);
    ofVertex(starx+size/2, stary+size/2);
    ofVertex(starx+size/10, stary+size/5);
    ofVertex(starx, stary+size);
    ofVertex(starx-size/10, stary+size/5);
    ofVertex(starx-size/2, stary+size/2);
    ofVertex(starx-size/5, stary+size/10);
    ofVertex(starx-size, stary);
    ofVertex(starx-size/5, stary-size/10);
    ofVertex(starx-size/2, stary-size/2);
    ofVertex(starx-size/10, stary-size/5);
    ofEndShape();
    
}

//--------------------------------------------------------------

ofPoint testApp::pointOnLine(float t, ofPoint p1, ofPoint p2){
    t = ofClamp(t, 0, 1);
        
    return (p2 - p1) * t + p1;
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackground(40, 10, 40);
    
    
    ofPoint from, to, circleCenter;
    
    from.set(100, ofGetHeight()/2);
    to.set(mouseX, mouseY);
    
    float t = ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1);
    
    t = pow(t, 2); //t = t^2

    
    
    circleCenter = pointOnLine(t, from, to);
    
    ofSetColor(150);

    ofCircle(from, 2);
    
    ofLine(from, to);
    
    
    //ofCircle(circleCenter, 10);
    star(circleCenter.x, circleCenter.y, 50);
    
    ofSetColor(200, 200, 100);
    star(to.x, to.y, 50);

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
