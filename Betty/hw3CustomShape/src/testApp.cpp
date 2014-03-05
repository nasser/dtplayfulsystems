#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(0, 140, 240);
    ofEnableSmoothing();
	verdana14.loadFont("verdana.ttf", 14, true, true);
    verdana14.setLineHeight(18.0f);
	verdana14.setLetterSpacing(1.037);


}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::drawBird(float positionX, float positionY, float size){
    

    ofPushMatrix();
    ofTranslate(positionX, positionY);
    ofScale(size, size);
    ofTriangle(50, 30, 30, 60, 50, 60);//beak
    ofTriangle(50, 30, 90, 30, 50, 80); //neck
    ofTriangle(105, 10, 105, 80, 50, 80); //chest
    ofTriangle(105, 10, 160, 10, 105, 80); //wings
    ofTriangle(50, 80, 105, 80, 90, 130); //torso
    ofTriangle(90, 130, 105, 80, 160, 80); //tail
    ofPopMatrix();

    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(255);

    ofNoFill();
    drawBird(50, 60, .5);
    drawBird(300, 50, 3);

    
    
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
