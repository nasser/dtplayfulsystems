#include "testApp.h"
//--------------------------------------------------------------
void testApp::star(float x, float y, float size){
    
    ofBeginShape();
    ofVertex(x, y-size);
    ofVertex(x+1, y-size/5);
    ofVertex(x+size/2, y-size/2);
    ofVertex(x+size/5, y-1);
    ofVertex(x+size, y);
    ofVertex(x+size/5, y+1);
    ofVertex(x+size/2, y+size/2);
    ofVertex(x+1, y+size/5);
    ofVertex(x, y+size);
    ofVertex(x-1, y+size/5);
    ofVertex(x-size/2, y+size/2);
    ofVertex(x-size/5, y+1);
    ofVertex(x-size, y);
    ofVertex(x-size/5, y-1);
    ofVertex(x-size/2, y-size/2);
    ofVertex(x-1, y-size/5);
    ofEndShape();
    
}


//--------------------------------------------------------------
void testApp::setup(){
    
    /*image credit: http://sorceress2000.deviantart.com/art/Tardis-Vector-206143625*/
    
    tardis.loadImage("images/tardis.png");
    tardis.resize(tardis.width / 8, tardis.height / 8);

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackground(40,5,40);
    
    ofSetColor(255, 255, 255);
    
    for(float i=0; i<400; i++){
        
        float posx = ofRandom(0, ofGetScreenWidth());
        float posy = ofRandom(0, ofGetScreenHeight());
        star(posx,posy,ofRandom(3, 15));
    }
    
    ofPushMatrix();
    ofRotate(-(ofGetElapsedTimef()*80));
    tardis.draw(ofGetScreenWidth()-600, ofGetScreenHeight()-450);
    ofPopMatrix();

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
