#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
  
    points.push_back(ofPoint(0,0)); // pushback pushes the points into the list
    points.push_back(ofPoint(10,0));
    points.push_back(ofPoint(20,0));
    points.push_back(ofPoint(20,0));
    points.push_back(ofPoint(30,0));
    points.push_back(ofPoint(40,0));
    points.push_back(ofPoint(50,0));
    points.push_back(ofPoint(0,0));


}

//--------------------------------------------------------------
void testApp::update(){
    
    int i;
    
    if(mouseX < ofGetWidth()/2){
        i = 2;
        
        else i =3;
        
        for(int i = 0; i<points.size()-1; i++){
    points[3].y = ofGetHeight()/2 + sin(ofGetElapsedTimef())*100;
        
    }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    for (int i=0; i<points.size(); i++){
        ofLine(points[i], points[i+1]); 
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
