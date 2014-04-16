#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetBackgroundAuto(FALSE);
    ofSetFrameRate(60);
    for (int i=0; i<200; i++) {
    P.push_back(ofPoint(ofRandomWidth(),ofRandomHeight()));
    }
}

//--------------------------------------------------------------
void testApp::update(){
//cohesion
        for (int i=0; i<P.size(); i++) {
        ofPoint neighborAve=ofPoint(0,0);
        int counter=0;
        for (int j=0; j<P.size(); j++) {
            if(P[i].distance(P[j])<=100){
                neighborAve= neighborAve + P[j];  //calculate the sum of the points
                counter++; //how many points
            }
        }
        neighborAve= neighborAve / counter; // The average point of all points
             P[i].interpolate(neighborAve, 0.01); // get closer to the new average point
        
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    for(int i=0; i<P.size(); i++){
        ofSetColor(ofRandom(255),ofRandom(255),ofRandom(255));
    //    ofSetColor(sin(ofMap(ofGetElapsedTimef(),-1,1,0,1))*255);
        
    ofCircle(P[i]+ofPoint(ofSignedNoise(ofRandom(100))*100,ofSignedNoise(ofRandom(100))*100), 2);
        
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
