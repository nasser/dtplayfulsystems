#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    //specify what primitive mode the mesh should use to connect
    //the verticies
    //mesh.setMode(OF_PRIMITIVE_POINTS);
    //mesh.setMode(OF_PRIMITIVE_LINE_LOOP);
    mesh.setMode(OF_PRIMITIVE_LINES);
    //mesh.setMode(OF_PRIMITIVE_LINE_STRIP);
    mesh.enableColors();
    
    //enableIndices() creats an empty array of indicies
    //addIndex() adds values to end of this array
    mesh.enableIndices();
    
    //create verticies
    //vertex is an ofVec3f
    //ofVec3f (x, y, z);
    ofVec3f top(100.0, 50.0, 0.0);
    ofVec3f left(50.0, 150.0, 0.0);
    ofVec3f right(150.0, 150.0, 0.0);
    
    //add verties
    mesh.addVertex(top);
    //add some color
    //ofFloatColor RGB are specified with a float between 0 & 1
    mesh.addColor(ofFloatColor(1, 0, 0));
    
    
    mesh.addVertex(left);
    mesh.addColor(ofFloatColor(0, 1, 0));
    
    mesh.addVertex(right);
    mesh.addColor(ofFloatColor(1, 1, 0));
    
    //addIndex() adds values to end of this array
    //OF loops through array of indices to determine how to create
    //the primitive
    mesh.addIndex(0);
    mesh.addIndex(1);
    mesh.addIndex(1);
    mesh.addIndex(2);
    mesh.addIndex(2);
    mesh.addIndex(0);
    
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0);
    
    //draw the mesh
    mesh.draw();
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
