#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    myPerlin.allocate(640, 480, OF_IMAGE_GRAYSCALE);
    

    
}

//--------------------------------------------------------------
void testApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    unsigned char* pixels = myPerlin.getPixels();
    
    for (int i=0; i<640; i++) {
        for (int j = 0; j <480; j++) {
            pixels[j*640+i]= ofNoise(i*0.001+mouse.x,j*0.01+mouse.y, ofGetElapsedTimef())*255;
        }
        
    }
    
    myPerlin.update();
    
}

//--------------------------------------------------------------
void testApp::draw(){

    myPerlin.draw(0,0, ofGetWindowWidth(), ofGetWindowHeight());
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

    mouse.x = x;
    mouse.y = y;
    
    
    
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
