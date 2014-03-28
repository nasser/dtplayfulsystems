#include "testApp.h"



//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------
void testApp::update(){
}
    

    float testApp::yCoordinateOnLine(float t, float y1, float y2){
        t = ofClamp(t, 0, 1);
        
        return (y2 - y1) * t + y1;
    }
    
    
    float testApp::xCoordinateOnLine(float t, float x1, float x2){
        t = ofClamp(t, 0, 1);
        
        return (x2 - x1) * t + x1;
    }
    
ofPoint testApp::pointOnLine(float t, ofPoint p1, ofPoint p2){
    t = ofClamp(t, 0, 1);
    return (p2 - p1) * t + p1;
}
    


//--------------------------------------------------------------
void testApp::draw(){

    //ofNoise random generator
//    for(int i = 0; i < 10; i++){
//        for(int j = 0; j < 10; j++){
//            ofSetColor((255 * ofNoise(i, j, mouseY, 1)), (255 * ofNoise(i, j, mouseY, 1)), (255 * ofNoise(i, j, mouseY, 1)));
//            ofRect(i*10, j*10, 10, 10);
//        }
//    }
    
    
    
//    float mouseX01 = (float)mouseX/ofGetWidth();
//    ofBackground(mouseX01 * 100, mouseX01 * 100,mouseX01 * 100);
    
    
//    float circleX = ofMap(mouseX, 0, ofGetWidth(), 50, 350, true); // true enables clamping
//    float circleY = ofMap(mouseX, 0, ofGetWidth(), 100, 300 + (sin(ofGetElapsedTimef()) * 50), true);;

//    float circleX = xCoordinateOnLine(mouseX01, 50, 350);
//    float circleY = yCoordinateOnLine(mouseX01, 100, 350);
//
//    ofCircle(circleX, circleY, 20);
    
    ofSetColor(0);
    
    ofPoint from, to, circleCenter, test;
    from.set(50, ofGetHeight()/2);
    to.set(ofGetWidth() - 50, ofGetHeight()/2);
//
//    
//    circleCenter = pointOnLine(ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1), from, to);
//    ofCircle(circleCenter, 20);
//    
//    ofCircle(from,2);
//    ofCircle(to, 2);
//    ofLine(from, to);
    
    float t = ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1);
    
    
    
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
