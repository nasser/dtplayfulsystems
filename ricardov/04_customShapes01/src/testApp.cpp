#include "testApp.h"



//--------------------------------------------------------------
void testApp::heart(float x2, float y2, float scale, float color) {

    float myLenght = sin(myRotation/6.5) *20;
    
    //LINES BG
    ofPushMatrix();
        ofRotate(myRotation * 1.5);
        ofFill();
        ofSetColor(0, 180, 180);

        float myPulse = 130 + myLenght;
        ofLine(0, 0, 0,  myPulse);
        ofLine(0, -myPulse, 0,  0);
    
        ofSetColor(110, 0, 150, 100 );
        ofCircle(myPulse+10, 0, 1);

    ofPopMatrix();
    
    
    //HEART
    ofPushMatrix();
    ofSetColor(250, 0, 0);

    ofTranslate(0, -25);
    ofBeginShape();
        ofVertex(0, 20);
        ofBezierVertex(0, -35, 80, 10, 0, 60);
        ofVertex(0, 20);
        ofBezierVertex(0, -35, -80, 10, 0, 60);
    ofEndShape();
    ofPopMatrix();
 

}


//--------------------------------------------------------------
void testApp::myShape01(float x1, float y1, float sz, float myColor){
    
    ofTranslate(x1, y1);

    //Creating positions for the shape
    for (int i=0; i<NUM_SIDES; i++) {
        xPos[i] = sz * sin(angle * i);
        yPos[i] = sz * cos(angle * i);
    }
    
    //CREATING SHAPE
    ofBeginShape();
        ofSetColor(20 + myColor, 80 + myColor, 0);
        ofRotate(myRotation);
        for (int i=0; i<NUM_SIDES; i++) {
            ofVertex(xPos[i], yPos[i]);
        }
    ofEndShape();
    

}



//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0);
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();

    //ROTATIO FOR LINES
    myRotation = 0;
    
}


//--------------------------------------------------------------
void testApp::update(){
    //Angle
    angle = 2 * PI / NUM_SIDES;
    myRotation += 1;
}


//--------------------------------------------------------------
void testApp::draw(){
    ofFill();
    ofSetColor(100, 10, 10, 10);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    
    int numb_of_objects = NUM_SIDES;
    int dist = 150;
    angle_inc = TWO_PI / numb_of_objects;


    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);

    //CENTRAL HEART
    ofPushMatrix();
        ofScale(2, 2);
        heart(0, 0, 60, 60);
    ofPopMatrix();
    
    //DRAWING A LOT OF MyShapes01
    ofRotate(myRotation);
    for (int i=0; i<numb_of_objects; i++) {

        float offsetX = cos(angle_inc * i) * dist;
        float offsetY = sin(angle_inc * i) * dist;
    
        ofPushMatrix();
            myShape01(offsetX, offsetY, 50, 50*i);
        ofPopMatrix();
    
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
