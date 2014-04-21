#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    manualTarget = ofPoint(ofGetWidth()/2, ofGetHeight()/2);
    
    for (int i=0; i<200; i++) {
        Flocker f;
        f.point = ofPoint(ofRandomWidth(), ofRandomHeight());
        f.speed = 1;
        f.angle - 0;
        flockers.push_back(f);
    }
}

//--------------------------------------------------------------
void testApp::update(){
    manualTarget.x = mouseX;
    manualTarget.y = mouseY;
    
    
    // steer randomly
    
    for (int i=0; i<flockers.size(); i++) {
    
    }
    
    
    // speed up/slow down randomly
    
    for (int i=0; i<flockers.size(); i++) {
       
    }
    
    
    // move
    for (int i=0; i<flockers.size(); i++) {
        flockers[i].move();
       
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0, 0, 0);
    ofSetColor(255, 255, 255);
    //    ofNoFill();
    //    ofBeginShape();
    for (int i=0; i<flockers.size(); i++) {
        //        ofVertex(points[i]);
        
        flockers[i].draw();
       
    }
    //    ofEndShape();
    
    // ofSetColor(255, 0, 0);
    // ofCircle(manualTarget, 10);
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
    //    points.push_back(ofPoint(ofRandomWidth(), ofRandomHeight()));
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