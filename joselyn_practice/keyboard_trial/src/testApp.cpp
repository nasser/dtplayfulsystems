#include "testApp.h"

int myCircleX;
int myCircleY;

//--------------------------------------------------------------
void testApp::setup(){
    

    myCircleX = 200;
    myCircleY = 300;


}

//--------------------------------------------------------------
void testApp::update(){
    
  
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofCircle(myCircleX, myCircleY, 100);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    if (key == 119){
        myCircleY--; 
    }
    
    if(key==97){
        myCircleX--;
    }

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

    cout << "keyReleased " << key << endl;

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
