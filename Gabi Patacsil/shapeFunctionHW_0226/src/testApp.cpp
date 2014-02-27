#include "testApp.h"

    void testApp::drawThis(float x1, float y1, float x2, float y2, float z, float angle, float radius1, float radius2) {

    ofPoint center;
    center.set(x1, y1);
    ofTranslate(center);
    //ofRotate(ofGetFrameNum(), 0, cos(ang<#float radius#>le), 0);

    
    }


void testApp::drawTwoLines(float spacing, float x1, float y1, float x2, float y2) {
    ofLine(x1, y1, x2, y2);
    ofLine(x1, y1 + spacing, x2, y2 + spacing);
}




//--------------------------------------------------------------
void testApp::setup(){
//    ofBackground(0);
//    ofSetFrameRate(30);
//	ofEnableAlphaBlending();

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

    //drawThis(400,
    ofSetColor(255, 255, 255);
	float x0 = 200;
	float y0 = 200;
	float x1 = 250;//cos(ofGetElapsedTimef()*1.0f);

	float y1 = 100+10*sin(ofGetElapsedTimef()*1.0f);
	float x2 = 300;//*cos(ofGetElapsedTimef()*2.0f);
	float y2 = 100+10*sin(ofGetElapsedTimef()*1.0f);
	float x3 = 200;
	float y3 = 200;
	
	
	
	ofFill();
    ofSetColor(255, 255, 255);
    ofBeginShape();
	ofVertex(x0,y0);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    ofVertex(x0-50,y0-50);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);

    ofEndShape();

	



    
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
