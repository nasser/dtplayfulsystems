#include "testApp.h"

void testApp::drawTwoLines(float spacing, float y1, float x2, float y2){
    ofLine(x1, y1, x2, y2);
    ofLine(x1, y1 + spacing, x2, y2 + spacing);
}

void testApp::drawTwoLines(ofPoint center, float angle, float length){
    
    ofPoint outer;//ofPoint allows users perform graphical operations, set positions and more with a better organization and control
    
    float outer.x = cos(ofDegToRad(angle)) * length;// degree To Radian
    float outer.y = sin(ofDegtoRad(angle)) * length;
    
    ofLine(center, center + outer * length);
    
}

//--------------------------------------------------------------
void testApp::setup(){
    
    //cout <<ofGetWidth() << endl;
    //ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
//    drawTwoLines(20 + sin(ofGetElapsedTimef() * 20) * 50, 0, 0, 100, 200);
    
    ofPoint center;
    center.set (ofGetLength()/2. ofGe
    center.y = ofGetWidth()/2;
    drawAngledLine(center, 45 + ofGetElapsedTimef() * 50, 100);//easiest way to animate objects is to assign the function ofGetElapsedTimef()
    
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
    if(clickBox.inside(x,y)){
        cout << "clicked me";
    }
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
