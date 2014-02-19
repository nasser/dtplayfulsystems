#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    theColor.set(0, 0, 0);
}

//--------------------------------------------------------------
void testApp::update(){
    theColor.r += 1;
}

//--------------------------------------------------------------
void testApp::draw(){
    //background color
    ofBackground(0, 0, 0);
    
    //ofsetColor == fill
    ofSetColor(255, 0, 0);
    ofLine(10, 10, 500, 500);
    
    ofSetColor(0, 0, 255);
    ofLine(10, 10, 200, 200);
    
    float redValue = 10.5;
//    double float

    int redValuesInt = 12;// int range: -2"31 to 2"31
//    unsigned int
//    long int
//    long long int: -2"63 to 2"63
    
    string name = "DT Playful Systems"; //string for text
    
    ofColor someColor; //create new valuable
    someColor.r = 255;
    someColor.g = 0;
    someColor.b = 120;
    
    ofSetColor(theColor);
    ofRect(200 + x, 200, 600, 400);
    x += 1;
    
    //for loop example
    ofSetColor(255, 255, 0);
    for (int i = 0; i < x; i ++) {
        ofLine(200+i, 0, 200+i, 500);
    }
    
    switch (x) {
        case 20:
            //do some stuff
            break;
        case 30:
            //do some stuff
        default:
            break;
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key == OF_KEY_LEFT) {
        theColor.g = 255;
    }

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    if (key == OF_KEY_F3) {
        theColor.g = 0;
    }
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
