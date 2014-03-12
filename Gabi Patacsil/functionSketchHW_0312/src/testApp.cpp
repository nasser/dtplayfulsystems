#include "testApp.h"

void testApp::starflake(float x, float y, float size, float angle, float red){
    ofTranslate(x, y);
    if(ofGetElapsedTimef()<20){
        for(int i = 0; i < size; i++){
            ofPoint from, to, circleCenter;
            from.set(i, 0);
            to.set(15, 10+i);
            
            ofRotate(angle);
            float t = ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, .75);
            circleCenter = pointOnLine(t, from-sin(ofGetElapsedTimef()), to+sin(ofGetElapsedTimef()));
            ofSetColor(red,50+i,200,10);
            ofCircle(circleCenter, 1);
        }
    }
}

ofPoint testApp::twoPointsOnLine(ofPoint p1, ofPoint p2, ofPoint p3, ofPoint p4, float t){
    t = ofClamp(t, 0, 1);
    ofPoint circleCenterOne, circleCenterTwo;
    return circleCenterOne = (p2 - p1) * t + p1;
    return circleCenterTwo = (p4 - p3) * t + p3;
}

    







//--------------------------------------------------------------
void testApp::setup(){
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
   
    starflake(100, 200, 200, 30, 100);
            ofPoint from, to, circleCenters;
            from.set(100, 100);
            to.set(500, 100);
            
            float t = ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, .75);
            circleCenters = twoPointsOnLine(from, to,from+100,to+200,t);
            ofSetColor(100);
            ofCircle(circleCenters, 1);
    


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
