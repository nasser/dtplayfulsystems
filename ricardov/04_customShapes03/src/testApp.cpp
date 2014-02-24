#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(10, 10, 0);
    ofSetBackgroundAuto(true);

    w = ofGetWidth();
    h = ofGetHeight();

    angle01 = 0;
    
    //CREATION OF HEIGHTS
    for(int i = 0; i< 30; i++){
        heights[i] = ofRandom( 300 );
    }

}

//--------------------------------------------------------------
void testApp::update(){
    sz = 200;
    angle01 += 0.05;

}

//--------------------------------------------------------------
void testApp::draw(){
    
    // MOVEMENT - - - - - - - - - - - - - - - - - - - - - - - -
    float x = w/2 + sin(angle01)  * sz;
    float y = h/4 + cos(angle01) * sz;

    
    //MOUNTAINS SHAPE - - - - - - - - - - - - - - - - - - - - - - - -
    float border = 100; //TOTAL DISTANCE FROM THE BORDER
    float widthElements = (w-border*2) /30;
    
    ofTranslate(border/2, h/2);
    
    for(int i = 0; i< 30; i++){
        float montain_sz = heights[i];
        
 //       ofRect(widthElements * i, h/2 + (montain_sz)/2, widthElements, montain_sz/500);
        
        ofBeginShape();
            ofSetColor(20, 120, 200, 20);
            ofVertex(0, 0);
            ofVertex(widthElements * i,  -heights[i]+y);
            ofVertex(w - border, 0);
        ofEndShape();

        //CIRCLES ON TOP THE SHAPES
        ofSetColor(250, 50, 0);
        ofCircle(widthElements * i, -heights[i] + y, 5);
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
