#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    //disables clearing of background
    ofSetBackgroundAuto(false);

}

//--------------------------------------------------------------
ofPoint testApp::pointOnLine(float t, ofPoint p1, ofPoint p2){
    //restircts a value to be within a specfied range defined by values min and max
    //ofClamp(value, min, max)
    t = ofClamp(t, 0, 1);
    
    //returns a point that interpolated by p1 and p2 and based on the value of k
    return(p2 - p1)*t + p1;
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
// circleCenter = from.getInterpolated(to, ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1));
void testApp::draw(){
    
    ofPoint from, to, circleCenter, from1, to1;
    //from.set(300, ofGetHeight()/2);
    
    from1.set(0, 0);
    to1.set(ofGetWidth(),0);
    
    //from = pointOnLine(ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1), from1, to1);
    //cout << from << endl;
    
    //oscilate the value of from.y
    //from.set(300, ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1)*ofGetWindowHeight());
    
    float m = ofGetWindowHeight() - ofGetElapsedTimef()*10;
    from.y = ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1)*m;
    from.x = 300 + ofGetElapsedTimef()*10;
    //from.x = ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1));
    
    
    to.set(ofGetWidth()-300, ofGetHeight()/2);
    
    //float t = ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1);
    
    //float t = decimal of elapsed time - int of elapsed time
    //returns a value between 0 and 1
    float t = ofGetElapsedTimef()   - ((int)ofGetElapsedTimef());
    
    
    //from.x = ofGetElapsedTimef()*40;
    //from.y = pow(ofGetElapsedTimef(), 2);
    
    
    //print to serial
    //cout << ((int)ofGetElapsedTimef()) << endl;
    
    //eases in
    //t = pow(t, 2); //t to the power of 2; t^2
    
    //eases out
    //t = powf(t, 0.5);
    
    //circleCenter = pointOnLine(t, from, to);
    circleCenter = pointOnLine(.2, from, to);
    cout << circleCenter.x << endl;
    //circleCenter = pointOnLine(ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1), from, to);
    
    //circleCenter = pointOnLine(sin(ofGetElapsedTimef()), from, to);
    
    ofCircle(circleCenter, 10);
    
    //draw control points and line
    ofCircle(from,2);
    ofCircle(to, 2);
    ofLine(from, to);
    
    //second lines control points
    ofCircle(from1,2);
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
