#include "testApp.h"
//--------------------------------------------------------------
ofPoint testApp::pointOnLine(ofPoint p5, ofPoint p6, float t){
    ofClamp(t, 0, 1);
    
    return((p6 - p5)*t +p5);
}
//--------------------------------------------------------------
void testApp::drawTwoPointsOnTwoLines (ofPoint p1, ofPoint p2, ofPoint p3, ofPoint p4, float t){
    //float ofClamp(float value, float min, float max)
    //restricts a value to be within the min and max
    ofClamp(t, 0, 1);
    
    //set color of lines to pink
    ofSetColor(255,20, 147);
    
    //make the line thickness equal to 0.01
    ofSetLineWidth(0.01);
    
    //create a line between points p2 and p2
    ofLine(p1, p2);
    
    //create a line between points p4 and p3
    ofLine(p3, p4);
    
    //set the color of the circles to black
    ofSetColor(0,0, 0);
    
    //set the center of the points to the interpolated point between p2 and p1
    //radius of circle is 10
    ofCircle((p2-p1)*t+p1, 10);
    
    //set the center of the points to the interpolated point between p3 and p4
    //radius of circle is 10
    ofCircle((p4-p3)*t+p3, 10);
    
}

//--------------------------------------------------------------
void testApp::setup(){
    
    //do not auto erase the background
    ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    //make from and to points to pass the circle back and fourth
    ofPoint from1, to1, from2, to2;
    
    //setting bounds of drawing & halfway points
    ofPoint upLeftCorner, upRightCorner, lowerLeftCorner, lowerRightCorner, half2, half3;
    upLeftCorner.set(0, 0);
    upRightCorner.set(ofGetWidth(), 0);
    lowerLeftCorner.set(0, ofGetHeight());
    lowerRightCorner.set(ofGetWidth(), ofGetHeight());
    half2.set(ofGetWidth()/2, ofGetHeight());
    half3.set(ofGetWidth(), ofGetHeight()/2);
    
    float t = ofMap(cos(ofGetElapsedTimef()), -1, 1, 0, 1);
    
    //start center, move down vertically
    from1 = pointOnLine(half2, lowerRightCorner/2, t);
    //ofCircle(from1, 10);
    
    //start lower right corner; move horizontally to the lower left corner
    to1 = pointOnLine(half3, lowerRightCorner/2, t);
    //ofCircle(to1, 10);
    
    //start at center, move up vertically
    from2 = pointOnLine(upRightCorner/2, lowerRightCorner/2, t);
    //ofCircle(from2, 10);
    
    
    to2 = pointOnLine(lowerLeftCorner/2, lowerRightCorner/2, t);
    //ofCircle(to2, 10);
    
    //move points along the path of a diamond
    drawTwoPointsOnTwoLines(half2, to2, from2, to2, t);
    drawTwoPointsOnTwoLines(half2, to1, from1, to2, t);
    drawTwoPointsOnTwoLines(upRightCorner/2, to2, from2, to1, t);
    drawTwoPointsOnTwoLines(upRightCorner/2, to1, from1, to1, t);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

    //toggle background refresh with t and f
    if( key == 't'){
        ofSetBackgroundAuto(true);
    } else if (key == 'f'){
        ofSetBackgroundAuto(false);
    }
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
