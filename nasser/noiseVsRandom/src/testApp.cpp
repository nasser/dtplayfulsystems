#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
}

//--------------------------------------------------------------
void testApp::update(){
    cout << ofNoise(6) << endl;
}

//--------------------------------------------------------------
void testApp::draw(){
    for (int i=0; i<100; i++) {
        for (int j=0; j<100; j++) {
            ofSetColor(255 * ofNoise(i * 0.01, j, mouseY * 20, 1), 255 * ofNoise(i * 0.01, j, mouseY * 20, 2), 255 * ofNoise(i * 0.01, j, mouseY* 20, 3));
            ofRect(i * 10, j * 10, 10, 10);
        }
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
