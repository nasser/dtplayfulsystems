#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetFrameRate(60);
   // ofBackground(0);
    ofSetCircleResolution(10);//4
    friction = 0.002;
    setInit(ofVec2f(ofGetWidth()/2, ofGetHeight()/2));
}

//--------------------------------------------------------------
void testApp::update(){
     
    resetForce();
    addForce(ofVec2f(0, 0.25));
    updateForce();
    updatePos();
    checkBounds(0, 0, ofGetWidth(), ofGetHeight());
    constrain(0, 0, ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofColor colorOne;
    ofColor colorTwo;
    
    colorOne.set (0, 0, 100);
    colorTwo.set (0, 0, 0);
    
    ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_CIRCULAR);
    
    ofSetHexColor(0xFFCC66);//0x3399cc
    for (int i = 0; i < CIRCLE_NUM; i++) {
        ofCircle(position[i], ofRandom(4));
    }
    
    ofSetHexColor(0xFFFFCC);
    for (int i = 0; i < CIRCLE_NUM; i++) {
        ofCircle(position[i], ofRandom(2));
    }
    
}

//--------------------------------------------------------------

void testApp::setInit(ofVec2f initPos){

    for (int i = 0; i < CIRCLE_NUM; i++) {
        position[i].x = initPos.x;
        position[i].y = initPos.y;
        float length = ofRandom(20);
        float angle = ofRandom(PI * 2);
        velocity[i].x = cos(angle) * length;
        velocity[i].y = sin(angle) * length;
        force[i].set(0, 0);
    }
}

//--------------------------------------------------------------
void testApp::resetForce(){
   
    for (int i = 0; i < CIRCLE_NUM; i++) {
        force[i].set(0, 0);
    }
}

//--------------------------------------------------------------
void testApp::addForce(ofVec2f _force){
    for (int i = 0; i < CIRCLE_NUM; i++) {
        force[i] += _force;
    }
}

//--------------------------------------------------------------
void testApp::updateForce(){
    for (int i = 0; i < CIRCLE_NUM; i++) {
        force[i] -= velocity[i] * friction;
    }
}

//--------------------------------------------------------------
void testApp::updatePos(){
    for (int i = 0; i < CIRCLE_NUM; i++) {
        velocity[i] += force[i];
        position[i] += velocity[i];
    }
}

//--------------------------------------------------------------
void testApp::constrain(float xmin, float ymin, float xmax, float ymax){
  
    for (int i = 0; i < CIRCLE_NUM; i++) {
        if (position[i].x < xmin) {
            position[i].x = xmin + (xmin - position[i].x);
        }
        if (position[i].x > xmax) {
            position[i].x = xmax - (position[i].x - xmax);
        }
        if (position[i].y > ymax) {
            position[i].y = ymax - (position[i].y - ymax);
        }
    }
}

//--------------------------------------------------------------
void testApp::checkBounds(float xmin, float ymin, float xmax, float ymax){
   
    for (int i = 0; i < CIRCLE_NUM; i++) {
        if (position[i].x < xmin || position[i].x > xmax) {
            velocity[i].x *= -1;
        }
        if (position[i].y > ymax) {
            velocity[i].y *= -1;
        }
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key == 'f') {
        ofToggleFullscreen();
    }
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
    setInit(ofVec2f(x, y));
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
