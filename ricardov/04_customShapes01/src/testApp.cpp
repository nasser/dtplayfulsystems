#include "testApp.h"



//--------------------------------------------------------------
void testApp::heart(float x2, float y2, float scale, float color) {
    ofPushMatrix();
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
    
    //Creating positions
    for (int i=0; i<NUM_SIDES; i++) {
        xPos[i] = sz * sin(angle * i);
        yPos[i] = sz * cos(angle * i);
    }
    ofTranslate(x1, y1);
    
    //1 CREATING SHAPE
    ofBeginShape();
    ofSetColor(20 + myColor, 80 + myColor, 0);
    for (int i=0; i<NUM_SIDES; i++) {
        ofVertex(xPos[i], yPos[i]);
    }
    ofEndShape();
    
    //SECUNDARY SHAPE
    ofFill();
    ofSetColor(0, 200, 200);
    ofLine(60, 0, 160, 0);


}




//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(20, 20, 20);
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();

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

    //CENTRAL heart
    ofPushMatrix();
        ofScale(2, 2);
    ofSetColor(250, 0, 0);
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
