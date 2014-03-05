#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------
void testApp::update(){

    
}

ofPoint testApp::pointOnLine(float t, ofPoint p1, ofPoint p2){

    t = ofClamp(t, 0, 1);
    
    return (p2 - p1) * t + p1;
    
}




//--------------------------------------------------------------
void testApp::draw(){

    ofPoint from, to, circleCenter;

//    from.set(50,            ofGetHeight()/2);
    from.set(50,            ofGetHeight()/2 * sin(  ofGetElapsedTimef() ) );

    to.set(ofGetWidth()-50, ofGetHeight()/2);
    
//    circleCenter = pointOnLine(0.25, from, to);
    
//    circleCenter = pointOnLine( sin(ofGetElapsedTimef()), from, to);

    circleCenter = pointOnLine( ofMap(  sin(ofGetElapsedTimef()), -1, 1, 0, 1), from, to);

    
    //drawline
    ofCircle(circleCenter, 10);
    
    //Drawcontrol points
    ofCircle(from, 2);
    ofCircle(to, 2);
    ofLine(from, to);
    
    //interpolate();
    
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
