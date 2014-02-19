#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------
void testApp::update(){
    theColor.r += 1;
}

//--------------------------------------------------------------
void testApp::draw(){
    
    //ofSetColor(0, 255, 255); //set to blue
    ofRect(10, 10, 100, 100);
    
    //this creats an object
    //someColor is a variable
    //ofColor someColor; //ofColor is the type; someColor is the name
    //someColor.r = 255;
    //someColor.g = 0;
    //someColor.b = 128;
    //ofSetColor(someColor);
    
    
    float redValue = 10.5;
    int redValueAsInt = 12; //range is -2^31 and 2^31
    unsigned int redValueisInt = 13; //0....2^32; you get an extra bit of storage with unsigned
    long unsigned int value = 14; //-2^63 ...2^63
    string name = "DT playful systems";
    
    float speed = 50;
    
    //ofRect(200 + ofGetElapsedTimef()*speed, 200, 600, 400);
    
    ofSetColor(theColor);
    ofRect(200 + x, 200, 600, 400);
    x += 5; //x is delcared in testApp.h & x is now moving 1 pixel per frame
    
    
    for (int i = 0; i < x; i++){
        ofLine(i , 0, i, 500);
    }
    
    
    //giant if statement that says if x = 20; 
    switch (x) {
        case 20:
            //do some stuff
            break;
        case 30:
            //do some stuff
            break;
        default:
            break;
    }
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key == ' '){
        theColor.g = 255;
    }

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    if (key == ' '){
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
