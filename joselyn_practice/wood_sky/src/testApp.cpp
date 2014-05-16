#include "testApp.h"

void testApp:: drawSine(float spacing){
    
    ofSetBackgroundAuto(true);
    
    ofSetColor(ofRandom(255), ofRandom( 255), ofRandom( 255));
    
    //ofNoFill(); could do no fill and you would have a different output/less chunky
    ofBeginShape();
    for(int x=0; x<ofGetWidth(); x+= spacing) {
        ofCurveVertex(x, ofGetHeight()/2 + ofGetHeight() * 0.3f * sin(x*0.01f + ofGetFrameNum() * 100));
    }
    ofEndShape(false);
    
    ofBeginShape();
    for(int x=0; x<ofGetWidth(); x+= (spacing+5)) {
        ofCurveVertex(x, ofGetHeight()/2 + ofGetHeight() * 0.3f * sin(x*0.01f + ofGetFrameNum() * 100));
    }
    ofEndShape(false);
    
    ofBeginShape();
    for(int x=0; x<ofGetWidth(); x+= (spacing+1)) {
        ofCurveVertex(x, ofGetHeight()/2 + ofGetHeight() * 0.3f * sin(x*0.01f + ofGetFrameNum() * 100));
    }
    ofEndShape(false);
}

//--------------------------------------------------------------
void testApp::setup(){

    myPlayer.loadMovie("movies/swinging.mov");
    myPlayer.play();
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    myPlayer.update(); // get all the new frames


}

//--------------------------------------------------------------
void testApp::draw(){
    
    myPlayer.draw(0, 0, 600, 400);
    

    
    if (drawLine == true){
        
        
        drawSine(3); 
        
        
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
    
    drawLine = true;


}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
    drawLine = false;


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
