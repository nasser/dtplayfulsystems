#include "testApp.h"


void testApp::drawTriangles(float x1, float y1, float x2, float y2, float x3, float y3){

   
    
    ofNoFill();
    ofCircle(x1, y1, 40);

    ofSetLineWidth(10); 
    ofTriangle(x1*ofGetElapsedTimef(), y1, x2*ofGetElapsedTimef(), y2, x3, y3);
    
    //ofSetColor(255,0,255, 100);
    ofTriangle(x1+20*ofGetElapsedTimef(), y1, mouseX, y2+300, x3*ofGetElapsedTimef(), y3);
    
    //ofSetColor(0, 100);
    ofTriangle(ofRandom(40)*ofGetElapsedTimef(), y1, mouseX, y2+500, x3*ofGetElapsedTimef(), y3+40);
    
    ofTriangle(x1+30*ofGetElapsedTimef(), y1, mouseX, y2+500, x3*ofGetElapsedTimef(), y3+40);

    ofTriangle(x1+30*ofGetElapsedTimef(), y2, mouseX, y2+500, x3*ofGetElapsedTimef(), y3+40);

    ofTriangle(x1+30*ofGetElapsedTimef(), y1, mouseX, y2+300, x3*ofGetElapsedTimef(), y3+100);

    ofTriangle(x1+30*ofGetElapsedTimef(), y1, mouseX, y2+300, x3*ofGetElapsedTimef(), y3+40);


}

void testApp::drawDrop(float x1, float y1, float size){
    

    
    for (int i = 0; i<200; i++){
        
        ofSetLineWidth(10);
        ofRect(x1, y1+i, size, size);
    }
}

//--------------------------------------------------------------
void testApp::setup(){
//    
  
    background.loadImage("images/femTech.jpg");
    
    donut.loadImage("images/donut.png");
    donut2.loadImage("images/donut2.png");
    background.resize(ofGetWidth(), ofGetHeight());
    
    
    speedX = 1; 
    speedY = 1; 
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofHideCursor();

    background.draw(0,0);
    donut.draw(40, 40);
    donut2.draw(300, 70);  
    drawTriangles(10, 10, 200, 20, 100, 400);
    
    if (flip == true){
        drawDrop(0, -20, 40);
        
    }

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    flip = true;

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
