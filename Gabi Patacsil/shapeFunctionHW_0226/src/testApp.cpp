#include "testApp.h"

    void testApp::drawBow(float scale, float x, float y) {

    ofPoint center;
    center.set(x-235, y-225);
    ofTranslate(center);
        float bow = scale;
        float x0 = bow;
        float x1 = bow*2;
        float x2 = bow*3;
        float x3, y1;
        x3 = y1 = bow*5;
        float x4 = bow*6;
        float x5 = bow*7;
        float x6 = bow*8;
        float x7 = bow*11;
        float x8 = bow*13;
        float x9 = bow*14;
        float x10 = bow*16;
        float x11 = bow*17;
        float x12 = bow*18;
        
        float y0 = bow*4;
        //float y1 = x3;
        float y2 = x4;
        float y3 = x5;
        float y4 = x6;
        float y5 = bow*10;
        float y6 = x7;
        float y7 = bow*12;
        float y8 = x8;
        float y9 = x9;
        
        
        ofFill();
        ofSetColor(200, 10, 0);
        ofBeginShape();
        ofVertex(x6,y4);
        ofBezierVertex(x6,y3,x7,y3,x7,y4);
        ofVertex(x7,y4);
        ofBezierVertex(x8,y2,x9,y1,x10,y0);
        ofVertex(x10,y0);
        ofBezierVertex(x11,y2,x12,y4,x10,y9);
        ofVertex(x10,y9);
        ofBezierVertex(x9, y8, x8, y7, x7, y5);
        ofVertex(x7,y5);
        ofBezierVertex(x7,y6,x6,y6,x6,y5);
        ofVertex(x6,y5);
        ofBezierVertex(x4,y7,x3,y8,x2,y9);
        ofVertex(x2, y9);
        ofBezierVertex(x0,y4,x1,y2,x2,y0);
        ofVertex(x2, y0);
        ofBezierVertex(x3,y1,x4,y2,x6,y4);
        ofEndShape();
    
    }







//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0);


}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

    drawBow(15, 300, 500);

    
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
