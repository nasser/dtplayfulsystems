#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofScale(10, 10);
    star(80,20,15,8);
     star(40,50,8,15);
    for(int i=0; i<10;i++){
        for(int n=0;n<10; n++){
            star(10+i*10,10+n*10,3,5);
        }
    }
   
    
}



//--------------

void testApp::star(float x,float y, float radius1, float points){
        float angle = TWO_PI / points;
        float halfAngle = angle/2.0;
        float radius2=radius1/5*2;
        ofBeginShape();
        for (float a = 0; a < TWO_PI; a += angle) {
            float sx = x + cos(a) * radius2;
            float sy = y + sin(a) * radius2;
            ofVertex(sx, sy);
            sx = x + cos(a+halfAngle) * radius1;
            sy = y + sin(a+halfAngle) * radius1;
            ofVertex(sx, sy);
        }
        ofEndShape();
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
