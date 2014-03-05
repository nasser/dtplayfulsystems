#include "testApp.h"


//--------------------------------------------------------------
ofPoint testApp::pointOnLine(float t, ofPoint p1, ofPoint p2){
    ofClamp(t, 0, 1);
    
    return((p2-p1)*t+p1);
    
}

//--------------------------------------------------------------
void testApp::setup(){
    ofSetBackgroundAuto(false);
   
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    ofPoint from, to, circleCenter;
    
    float m = ofGetWindowHeight() - ofGetElapsedTimef()*10;
    cout << m << endl;
    from.y = ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1)*m;
    from.x = 100 + ofGetElapsedTimef()*10;
    to.set(ofGetWidth()-300, ofGetHeight()/2);
    float t = ofGetElapsedTimef()   - ((int)ofGetElapsedTimef());

    circleCenter = pointOnLine(.2 , from, to);
    if( circleCenter.x < to.x){
    

    ofSetColor(255, 255, 255);
    ofCircle(circleCenter, 10);
    
    //draw control points and line
    ofCircle(from,2);
    ofCircle(to, 2);
    
    ofSetColor(20, 20, 20);
    ofLine(from, to);
    } else {
        
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
