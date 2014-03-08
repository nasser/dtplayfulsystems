#include "testApp.h"

ofPoint testApp:: pointOnLine(float t, ofPoint p1, ofPoint p2){
    t = ofClamp(t, 0, 1);
    
    
    return (p2 - p1) * t + p1;
    
    ofVec3f p3 = (p2 - p1) * t + p1;

    
    cout << p3 << endl; 

    //ofPoint returns a point
}

//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofPoint from, to, circleCenter, from1, to1, high, low;
    
    //high =
    //low.set = ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1), ;

    from1.set(0, 0);
    to1.set(ofGetWidth(), 0);
    
    from.set(50,  ofGetHeight()/2);
    //from = pointOnLine(ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1), from1, to1);
    to.set(ofGetWidth() - 50, ofGetHeight()/2); // to make the ball move diagonally you'll move the ofGetHeight to 0;
    
    // this part is about easing ::
    
    float t = ofMap(sin( ofGetElapsedTimef()), -1, 1, 0, 1);
    
    //or this
    
  //  float t = ofGetElapsedTimef() - int(ofGetElapsedTimef());  //this reduces the float to just the part after the decimal
    
    t = pow(t, 2); // t= t^2
    
    //circleCenter = pointOnLine(ofMap(sin( ofGetElapsedTimef()), -1, 1, 0, 1),  from, to);
    
    circleCenter = pointOnLine(t, from, to);
    //cout<< circleCenter <<endl;

    
    ofCircle(circleCenter, 10);
    ofCircle(from, 2);
    ofCircle(to, 2);
    ofLine(from, to);
    
    //ofCircle(from1, 2);
    //ofCircle(to1, 2);
    //ofLine(from1, to1);
    
    
    
    //circleCenter = pointOnLine(t, high, low);



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
