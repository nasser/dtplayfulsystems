#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    //   x = 100;
    //   y = 19;
}

//--------------------------------------------------------------
void testApp::update(){
    ofSetBackgroundAuto(true);
}

ofPoint testApp::pointOnLine(float t, ofPoint p1, ofPoint p2) {
    t = ofClamp(t, 0, 1);
    return (p2 - p1) * t + p1;
}

//--------------------------------------------------------------

void testApp:: drawTwoPointsOnTwoLine(ofPoint p1, ofPoint p2, ofPoint p3, ofPoint p4, float t){
    
}

void testApp:: drawPointOnLine(ofPoint p1, ofPoint p2, int r, int g, int b){
    
    
    
    
    
    for(int i = 0; i < 10; i++){
        
        ofSetColor(r, g, b, 255 - i*20);
        ofCircle(p1, 20 + i*5);
        
    }
    
    
    
    for(int i = 0; i < 10; i++){
        
        ofSetColor(r, g, b, 255 - i*20);
        ofCircle(p2, 20 + i*5);
        
        
    }
    
    
    
    
    
}



void testApp::draw(){
    
    ofPoint froma, tob, circleCenter2;
    froma.set(100,100);
    tob.set(200,700);
    circleCenter2 = pointOnLine(ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1), froma, tob);
    
    
    
    //    ofCircle(circleCenter2, 10);
    
    //    ofCircle(froma, 2);
    //    ofCircle(tob, 2);
    //    ofSetColor(0,0,0);
    //    ofLine(froma, tob);
    
    ofPoint from, to, circleCenter, from1, to1, to2;
    from1.set(0,0);
    to1.set(ofGetWidth(),100);
    to2.set(100,100);
    //   to3.set(250,50);
    //   to2.set(ofGetWidth()/2 - 800, ofGetHeight());
    // from.set(100,            ofGetHeight()/2);
    from = pointOnLine(ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1), from1, to1);
    
    
    to.set(circleCenter2);
    //the of circle is the one that takes a point and a radius
    circleCenter = pointOnLine(ofMap(cos(ofGetElapsedTimef()), -1, 1, 0, 1), from, to);
    
    //ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1), from, to);
    
    //draw circle at that point
    ofCircle(circleCenter, 10);
    //draw contol points and line
    //    ofCircle(from, 2);
    //     ofCircle(to, 2);
    ofSetColor(255,83,13);
    //       ofLine(from, to);
    //
    //        ofCircle(from1, 2);
    //      ofCircle(to1, 2);
    //    ofSetColor(0,0,100);
    //      ofLine(from1, to1);
    //makes code much more sustainable.
    
    
    //    ofCircle(to1, to2);
    
    //    ofPoint thisOne = ofPoint(100, 400);
    //    ofPoint thisTwo = ofPoint(350, 175);
    
    
    drawPointOnLine(ofPoint(100, 400), ofPoint(350, 175), 255, 0, 0);
    
    drawPointOnLine(ofPoint(600, 500), ofPoint(90, ofGetWindowHeight() - 50), 0, 255, 255);
    
    drawPointOnLine(ofPoint(400, 300), ofPoint(400, 500), 0, 255, 0);
    
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
