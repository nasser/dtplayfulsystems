#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    for(int i = 0; i<100; i++){
        for(int j= 0; j<100; j++){
            ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
            ofRect(i *10, j * 10, 10, 10); 
        }
    }

    
    //this is perlin noise example
    
    for(int i = 0; i<100; i++){
        for(int j= 0; j<100; j++){
            ofSetColor( 255 *ofNoise(i, j, mouseY * 0.001), 255 *ofNoise(i, j, mouseY * 0.001), 255 *ofNoise(i, j, mouseY * 0.001)); // take out the 0.001 if you want to move more quickly through the randomness
            ofRect(i *10, j * 10, 10, 10);
            
            //learning about the hypercube and perlin noise // will be black and white because the RGB are all the same, if you add a 4th parameter after the mouseY * 0.0001, 4)
            
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
