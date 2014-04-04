#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    cout << ofNoise(x) << endl;
    x += 0.8;
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0);
    ofPushMatrix();
    ofTranslate(ofGetWindowSize()/2);
    
    
    for (int i=0; i<3000; i++) {
        ofSetColor(ofRandom(0, 25), ofRandom(0, 60), ofRandom(0, 105));
        ofCircle( (ofSignedNoise(i*0.1+x)*100) -400, ofSignedNoise((i+1)*0.1+x)*500, 1);
    }
    
    for (int i=0; i<3000; i++) {
        ofSetColor(ofRandom(0, 55), ofRandom(0, 55), ofRandom(0, 55));
        ofCircle( (ofSignedNoise(i*0.1+x)*100) -300, ofSignedNoise((i+1)*0.1+x)*500, 1);
    }
    
    for (int i=0; i<3000; i++) {
        ofSetColor(ofRandom(0, 100), ofRandom(0, 90), ofRandom(0, 155));
        ofCircle( (ofSignedNoise(i*0.1+x)*100) -200, ofSignedNoise((i+1)*0.1+x)*500, 1);
    }
    
    for (int i=0; i<3000; i++) {
        ofSetColor(ofRandom(0, 15), ofRandom(0, 15), ofRandom(0, 155));
        ofCircle( (ofSignedNoise(i*0.1+x)*100) -100, ofSignedNoise((i+1)*0.1+x)*500, 1);
    }
    
    for (int i=0; i<3000; i++) {
        ofSetColor(ofRandom(0, 153), ofRandom(0, 55), ofRandom(0, 15));
        ofCircle( (ofSignedNoise(i*0.1+x)*100), ofSignedNoise((i+1)*0.1+x)*500, 1);
    }
    
    for (int i=0; i<3000; i++) {
        ofSetColor(ofRandom(0, 153), ofRandom(0, 55), ofRandom(0, 125));
        ofCircle( (ofSignedNoise(i*0.1+x)*100) +100, ofSignedNoise((i+1)*0.1+x)*500, 1);
    }
    
    for (int i=0; i<3000; i++) {
        ofSetColor(ofRandom(0, 13), ofRandom(0, 155), ofRandom(0, 125));
        ofCircle( (ofSignedNoise(i*0.1+x)*100) +200, ofSignedNoise((i+1)*0.1+x)*500, 1);
    }
    
    for (int i=0; i<3000; i++) {
        ofSetColor(ofRandom(0, 130), ofRandom(0, 100), ofRandom(0, 59));
        ofCircle( (ofSignedNoise(i*0.1+x)*100) +300, ofSignedNoise((i+1)*0.1+x)*500, 1);
    }
    
    for (int i=0; i<3000; i++) {
        ofSetColor(ofRandom(0, 90), ofRandom(0, 50), ofRandom(0, 90));
        ofCircle( (ofSignedNoise(i*0.1+x)*100) +400, ofSignedNoise((i+1)*0.1+x)*500, 1);
    }
    
    
    ofPopMatrix();
    x += 0.001;
    //  particles.publishScreen();
}



//        for (int j=0; j<100; j++) {
//            ofSetColor(255 * ofNoise(i * 0.01, j, mouseY * 20, 1), 255 * ofNoise(i * 0.01, j, mouseY * 20, 2), 255 * ofNoise(i * 0.01, j, mouseY* 20, 3));
//            ofRect(i * 10, j * 10, 10, 10);
//        }

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
