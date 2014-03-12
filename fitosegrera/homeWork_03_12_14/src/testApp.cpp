#include "testApp.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////
// THIS CODE TAKES THE PROCEDURES OF LAST CODE (SLIDING_BETWEEN_LINES) INTO A SET OF FUNCTIONS THAT //
// SIMPLIFIES THE DRAW LOOP AND ALLOWS TO CREATE NEW SETS OF LINES..................................//
//////////////////////////////////////////////////////////////////////////////////////////////////////


//--------------------------------------------------------------
void testApp::setup(){
    
    
}
//--------------------------------------------------------------
//Function that creates the points of the vectors
ofPoint testApp::puntos(ofPoint from1, ofPoint to1, ofPoint from2, ofPoint to2, ofPoint from5, ofPoint to5, ofPoint from6, ofPoint to6){
    
    from3 = pointOnLine(ofMap(sin(ofGetElapsedTimef()*20), -1, 1, 0, 1), from1, to1);
    to3.set  (ofGetWidth()/2, ofGetHeight()/2);
    
    from4 = pointOnLine(ofMap(sin(ofGetElapsedTimef()*20), -1, 1, 0, 1), from2, to2);
    to4.set  (ofGetWidth()/2, ofGetHeight()/2);
    
    circleCenter1 = pointOnLine(ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1), from3, to3);
    circleCenter2 = pointOnLine(ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1), from4, to4);
    
    puntos1.push_back(circleCenter1);
    puntos2.push_back(circleCenter2);
    
    from7 = pointOnLine(ofMap(sin(ofGetElapsedTimef()*50), -1, 1, 0, 1), from5, to5);
    to7.set  (ofGetWidth()/2, ofGetHeight()/2);
    
    from8 = pointOnLine(ofMap(sin(ofGetElapsedTimef()*50), -1, 1, 0, 1), from6, to6);
    to8.set  (ofGetWidth()/2, ofGetHeight()/2);
    
    circleCenter3 = pointOnLine(ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1), from7, to7);
    circleCenter4 = pointOnLine(ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1), from8, to8);
    
    puntos3.push_back(circleCenter3);
    puntos4.push_back(circleCenter4);
    
}
//--------------------------------------------------------------
//Function that draws the lines between the points of the vectors
ofPoint testApp::fractal(vector<ofPoint> puntos1, vector<ofPoint> puntos2, vector<ofPoint> puntos3, vector<ofPoint> puntos4){
    
    ofSetColor(ofMap(sin(ofGetElapsedTimef()*10), -1, 1, 100, 0), ofMap(sin(ofGetElapsedTimef()*10), -1, 1, 0, 255), ofMap(sin(ofGetElapsedTimef()*10), -1, 1, 255, 0));
    
    ofNoFill();
    ofBeginShape();
    for(int i = 0; i < puntos1.size(); i++){
        if (i > 0) {
            ofVertex(puntos1[i]);
        }
    }
    ofEndShape();
    
    ofNoFill();
    ofBeginShape();
    for(int i = 0; i < puntos2.size(); i++){
        if (i > 0) {
            ofVertex(puntos2[i]);
        }
    }
    ofEndShape();
    
    ofSetColor(ofMap(sin(ofGetElapsedTimef()*10), -1, 1, 255, 0), ofMap(sin(ofGetElapsedTimef()*10), -1, 1, 0, 255), ofMap(sin(ofGetElapsedTimef()*10), -1, 1, 100, 0));
    
    ofNoFill();
    ofBeginShape();
    for(int i = 0; i < puntos3.size(); i++){
        if (i > 0) {
            ofVertex(puntos3[i]);
        }
    }
    ofEndShape();
    
    ofNoFill();
    ofBeginShape();
    for(int i = 0; i < puntos4.size(); i++){
        if (i > 0) {
            ofVertex(puntos4[i]);
        }
    }
    ofEndShape();
}

//--------------------------------------------------------------
void testApp::update(){
    
    from1.set(0, 0);
    to1.set(ofGetWidth(), 0);
    
    from2.set(0, ofGetHeight());
    to2.set(ofGetWidth(), ofGetHeight());
    
    from5.set(0, 0);
    to5.set(0, ofGetHeight());
    
    from6.set(ofGetWidth(), 0);
    to6.set(ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
ofPoint testApp::pointOnLine(float t, ofPoint p1, ofPoint p2) {
    
    t = ofClamp(t, 0, 1);
    
    return (p2 - p1) * t + p1;
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackground(0);
    
    puntos(from1, to1, from2, to2, from5, to5, from6, to6);
    
    fractal(puntos1, puntos2, puntos3, puntos4);
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
