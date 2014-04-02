#include "testApp.h"

ofPoint testApp:: pointOnLine(float t, ofPoint p1, ofPoint p2){
    t = ofClamp(t, 0, 1);
    
    return (p2 - p1) * t + p1;
    
    //ofPoint returns a point
}

float testApp:: xCoordinateOnLine(float t, float x1, float x2) {
    t = ofClamp(t, 0, 1);
    
    return (x2 - x1) * t + x1;
}

ofPoint testApp:: drawTwoPointsOnTwoLine(ofPoint p1, ofPoint p2, ofPoint p3, ofPoint p4, float t){
    t= ofClamp(t, 0, 1);
    

 return(p4 - p3) * t + p4;
    
    
}

void testApp:: drawSine(float spacing){
    ofSetBackgroundAuto(true);
    
    ofSetColor(ofRandom(255), ofRandom( 255), ofRandom( 255));

    //ofNoFill(); could do no fill and you would have a different output/less chunky 
    ofBeginShape();
    for(int x=0; x<ofGetWidth(); x+= spacing) {
        ofCurveVertex(x, ofGetHeight()/2 + ofGetHeight() * 0.3f * sin(x*0.01f + ofGetFrameNum() * 100));
    }
    ofEndShape(false);
}

//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(0);

}

//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    ofSetBackgroundAuto(false);
   

    // these are your points that you'll either be moving between or moving from a to b
    ofPoint from, to, circleCenter, from2, to2, circleCenter2;
    
    float t = ofGetElapsedTimef() - ((int)ofGetElapsedTimef()); //creates movement
    //t = sqrt(1 - powf(1 - t, 2)); // creates easing
    
    float a = ofGetHeight()/2 *ofGetElapsedTimef(); //amplitude of the wave!
    
    from.x = ofGetElapsedTimef()* 20; // moves your x along the screen to the right
    from.y = ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1) * a; // mapping the sin of the wave to between 0 and 1 because otherwise you'd go offscreen
    
    to.set(ofGetWidth(), ofGetHeight()); // where you're heading
    
    circleCenter = pointOnLine(t, from, to); // the circle center of the circles moving down the lines // calls the function above //interpolation
    ofSetColor(0, 0, 200);
    ofCircle(circleCenter, 5); // moves your circle center
    //ofNoFill();
    ofSetColor(255);
    ofLine(from, to);
    
    from2.x = 100 * ofGetElapsedTimef();
    from2.y = 100 * ofGetElapsedTimef();
    to2.x = ofGetWidth();
    to2.y = ofGetHeight(); 
    
    
    //circleCenter2 = drawTwoPointsOnTwoLine(from, to, from2, to2, t);
    circleCenter2 = pointOnLine(t, from2, to2);
    ofSetColor(255, 0, 255);
    ofCircle(circleCenter2, 6);
    ofSetColor(255);
    ofLine(from2, to2);
    
    
    

    if (flip == false){
        drawSine(2);
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
    
    flip = false; 
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
    flip = true; 
    
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
