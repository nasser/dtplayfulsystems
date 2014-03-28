#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------
void testApp::update(){
    cout << ofNoise(5) <<endl; //look up what this shit is

}

//--------------------------------------------------------------
void testApp::draw(){
//    for(int i=0; i<10; i++){
//        for(int j=0; j<10; j++){
//            ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
//            ofRect(i*10,j*10,10,10);
//        }
//    }
    
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            ofSetColor(255* ofNoise(i,j, mouseY * 0.001, 1), 255* ofNoise(i,j, mouseY * 0.001, 2), 255* ofNoise(i,j, mouseY * 0.001, 3)); //ofNoise(x,y,z,w);
            ofRect(i * 10,j * 10,10,10);
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
