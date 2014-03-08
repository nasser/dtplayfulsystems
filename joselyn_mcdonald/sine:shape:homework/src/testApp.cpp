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
//--------------------------------------------------------------
void testApp::setup(){
    
   
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    ofSetBackgroundAuto(false);

    
    
    // these are your points that you'll either be moving between or moving from a to b
    ofPoint from, to, circleCenter;
    
    float t = ofGetElapsedTimef() - ((int)ofGetElapsedTimef()); //creates movement
    //t = sqrt(1 - powf(1 - t, 2)); // creates easing 
    
    float a = ofGetHeight()/2 *ofGetElapsedTimef(); //amplitude of the wave!
    
    from.y = ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1) *a; // mapping the sin of the wave to between 0 and 1 because otherwise you'd go offscreen
    
    
    from.x = ofGetElapsedTimef()* 20; // moves your x along the screen to the right
    
    to.set(ofGetWidth(), ofGetHeight()/2); // where you're heading 
    
    circleCenter = pointOnLine(t, from, to); // the circle center of the circles moving down the lines // calls the function above //interpolation 
    ofSetColor(0);
    ofCircle(circleCenter, 3); // moves your circle center 
    //ofNoFill();
    ofSetColor(255);
    ofLine(from, to);
    

    

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
    
   ofSetBackgroundAuto(true);


    ofSetColor(ofRandom(255), ofRandom( 255), ofRandom( 255));
    
	//ofNoFill();
	int spacing = 2;
	ofBeginShape();
	for(int x=0; x<ofGetWidth(); x+= spacing) {
		ofCurveVertex(x, ofGetHeight()/2 + ofGetHeight() * 0.3f * sin(x*0.01f + ofGetFrameNum() * 0.02f));
	}
	ofEndShape(false);
    
    
    
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
