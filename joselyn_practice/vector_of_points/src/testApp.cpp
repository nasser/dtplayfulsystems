#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    points.push_back(ofPoint(0, ofGetHeight()/2));
    points.push_back(ofPoint(10, ofGetHeight()/2));
    points.push_back(ofPoint(20, ofGetHeight()/2));
    points.push_back(ofPoint(30, ofGetHeight()/2));
    points.push_back(ofPoint(40, ofGetHeight()/2));
    points.push_back(ofPoint(50, ofGetHeight()/2));
    points.push_back(ofPoint(60, ofGetHeight()/2));
    points.push_back(ofPoint(70, ofGetHeight()/2));
    points.push_back(ofPoint(80, ofGetHeight()/2));
    points.push_back(ofPoint(90, ofGetHeight()/2));
    points.push_back(ofPoint(100, ofGetHeight()/2));
    points.push_back(ofPoint(110, ofGetHeight()/2));
    points.push_back(ofPoint(120, ofGetHeight()/2));
    points.push_back(ofPoint(130, ofGetHeight()/2));
    
    points2.push_back(ofPoint(0, ofGetHeight()/2));
    points2.push_back(ofPoint(10, ofGetHeight()/2));
    points2.push_back(ofPoint(20, ofGetHeight()/2));
    points2.push_back(ofPoint(30, ofGetHeight()/2));
    points2.push_back(ofPoint(40, ofGetHeight()/2));
    points2.push_back(ofPoint(50, ofGetHeight()/2));
    points2.push_back(ofPoint(60, ofGetHeight()/2));
    points2.push_back(ofPoint(70, ofGetHeight()/2));
    points2.push_back(ofPoint(80, ofGetHeight()/2));
    points2.push_back(ofPoint(90, ofGetHeight()/2));
    points2.push_back(ofPoint(100, ofGetHeight()/2));
    points2.push_back(ofPoint(110, ofGetHeight()/2));
    points2.push_back(ofPoint(120, ofGetHeight()/2));
    points2.push_back(ofPoint(130, ofGetHeight()/2));

}

//--------------------------------------------------------------
void testApp::update(){
   
    for (int i=0; i<points.size(); i++) {
        points[i].y = ofGetHeight()/2 + sin(i + ofGetElapsedTimef()) * 100;
        points2[i].x = ofGetHeight()/2 + cos(i + ofGetElapsedTimef()) * 200;

        
        cout<< points.size() <<endl;

        
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    for (int i=0; i<points.size()-1; i++) {
        ofLine(points[i], points[i+1]);
        ofLine(points2[i], points2[i+1]);

        
        //cout<< points[i] <<endl;
        
        
        cam.begin();
        float x = 0;
        float y = sin(ofGetElapsedTimef()*0.4)*150;
        float z = cos(ofGetElapsedTimef()*0.4)*150;
        
        light.enable();
        light.setPosition(x,y,z);
        light.draw();
        
        ofPushStyle();
         ofRotateY(10);
         ofSetColor(255, 255, 255);
         ofBox(ofGetWidth()/2, ofGetHeight()/2, 10, 220);
        ofPopStyle();
        
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