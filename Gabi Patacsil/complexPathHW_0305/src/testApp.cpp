#include "testApp.h"



//--------------------------------------------------------------
void testApp::setup(){
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();
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
    
    
    
        ofSetColor(0,100,200,10);
        ofTranslate(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
    if(ofGetElapsedTimef()<10){
        for(int i = 0; i <100; i++){
            ofPoint from, to, circleCenter;
            from.set(i, 0);
            to.set(10, 20+i);
            
            ofRotate(60);
            float t = ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, .75);
            circleCenter = pointOnLine(t, from-(sin(ofGetElapsedTimef())*10), to+sin(ofGetElapsedTimef()));
            ofSetColor(200-i,50+i,200,10);
            ofCircle(circleCenter, 1);
        }
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
