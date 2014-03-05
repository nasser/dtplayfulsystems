#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0,0,0);
    theColor.set(0,0,0);

}

//--------------------------------------------------------------
void testApp::update(){
    theColor.r+=1;

}

//--------------------------------------------------------------
void testApp::draw(){
    
    float redValue=10.5;
    int redValueAsInt=12; //-2*63..2*63
    string name="DT";
    float speed=10;
    
    ofColor someColor;
    someColor.r=255;
    someColor.g=0;
    someColor.b=60;
    ofSetColor(someColor);
      ofSetColor(theColor);
    ofRect(50,ofGetElapsedTimef()*speed,50,50);
    ofSetColor(255,255,255);
    ofRect(50,x*speed,50,50);
    x+=5;
    
    
    ofSetColor(someColor);
    
   }

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    switch (key) {
        case 'a':
            theColor.b=255;
            break;
        case 'b':
            theColor.g=255;
            break;
            
        default:
            //if nothing matches
            break;
    }

    
    
    //theColor.g=255;

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
//theColor.g=0;
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
