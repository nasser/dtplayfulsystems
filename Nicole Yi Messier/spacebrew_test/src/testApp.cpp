#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
//spacebrew stuff
    ofSetFrameRate(60);
    string host = Spacebrew::SPACEBREW_CLOUD; // "localhost";
    string name = "snaxx & macs prototype";
    string description = "It's amazing";
    
    spacebrew.addPublish("button", Spacebrew::TYPE_BOOLEAN);
    spacebrew.addSubscribe("backgroundOn", Spacebrew::TYPE_BOOLEAN); //"boolean" ); // just typing "boolean" also works
    spacebrew.connect( host, name, description );
    
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

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
