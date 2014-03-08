#include "testApp.h"


//LORENZ SYSTEM
//source: http://en.wikipedia.org/wiki/Lorenz_system


//--------------------------------------------------------------
void testApp::star(float x, float y, float z, float size){
    
    ofBeginShape();
    ofVertex(x, y-size, z);
    ofVertex(x+size/10, y-size/5, z);
    ofVertex(x+size/2, y-size/2, z);
    ofVertex(x+size/5, y-size/10, z);
    ofVertex(x+size, y, z);
    ofVertex(x+size/5, y+size/10, z);
    ofVertex(x+size/2, y+size/2, z);
    ofVertex(x+size/10, y+size/5, z);
    ofVertex(x, y+size, z);
    ofVertex(x-size/10, y+size/5, z);
    ofVertex(x-size/2, y+size/2, z);
    ofVertex(x-size/5, y+size/10, z);
    ofVertex(x-size, y, z);
    ofVertex(x-size/5, y-size/10, z);
    ofVertex(x-size/2, y-size/2, z);
    ofVertex(x-size/10, y-size/5, z);
    ofEndShape();
    
}

//--------------------------------------------------------------
void testApp::setup(){
    
    last.x=0.1;

}

//--------------------------------------------------------------
void testApp::update(){
    
    if(ofGetFrameRate() > 5){
    
        current.x = sigma * ( last.y - last.x);
        current.y = ( last.x * ( rohm - last.z) ) - last.y;
        current.z  = (last.x * last.y) - (beta * last.z);
        current = current*dt;
        starpos.push_back(current);
        last += current;
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackground(30, 15, 30);
    ofSetColor(255);
    
    cam.begin();
    
    for (int i = 0; i<starpos.size() ; i++){
    
        star(starpos[i].x*100, starpos[i].y*100, starpos[i].z*100, ofRandom(2, 7));
        
    }
    
    cam.end();

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
