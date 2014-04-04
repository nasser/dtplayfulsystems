#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
<<<<<<< HEAD

=======
    
    
    //ofSetBackgroundAuto(false);
>>>>>>> 0ed8fe02ab85b1ff6ee5165ae8c33b0add53fe43
}

//--------------------------------------------------------------
void testApp::update(){

}

ofPoint testApp::pointOnLine(float t, ofPoint p1, ofPoint p2) {
    t = ofClamp(t, 0, 1);
    
    return (p2 - p1) * t + p1;
}

//--------------------------------------------------------------
// circleCenter = from.getInterpolated(to, ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1));
void testApp::draw(){
    ofPoint from, to, circleCenter, from1, to1;
    from1.set(0, 0);
    to1.set(ofGetWidth(), 0);
    
    // from = pointOnLine( ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1), from1, to1);
    from.set(300,                ofGetHeight()/2);
    to.set  (ofGetWidth() - 300, ofGetHeight()/2);
    
<<<<<<< HEAD
    float t = ofGetElapsedTimef() - ((int)ofGetElapsedTimef());
    
=======
    //float t = decimal of elapsed time - int of elapsed time
    //returns a value between 0 and 1
    float t = ofGetElapsedTimef() - ((int)ofGetElapsedTimef());
    
    //print to serial
    //cout << ((int)ofGetElapsedTimef()) << endl;
    
    
>>>>>>> 0ed8fe02ab85b1ff6ee5165ae8c33b0add53fe43
    t = sqrt(1 - powf(1 - t, 2));
    
    circleCenter = pointOnLine( t, from, to);
    
    // draw circle
    ofCircle(circleCenter, 10);
    
    // draw control points and line
    ofCircle(from, 2);
    ofCircle(to, 2);
    ofLine(from, to);

    ofCircle(from1, 2);
    ofCircle(to1, 2);
    ofLine(from1, to1);
    
    
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
