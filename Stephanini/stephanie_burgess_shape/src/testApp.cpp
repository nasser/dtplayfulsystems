#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetBackgroundAuto(false);
    
    
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
//    ofSetColor(y3, y4, y3);
//   flower(x, y, x1);
//ofSetColor(255,130,0);
//     flower(x2, y, x1);
//    ofSetColor(222,80,170);
//    for (int i=0; i<5; i++) {
//    flower(x1, y, y*i);
////        flower(x, y, y);
////        flower(50, 10, 5);
//        
//  //      flower2(x,y,y1);
//    
//  //  flower (50, 30, 10);
// //  }
//    }
    
    
    
    
    
    for(int i = 0; i < 2; i++){
        
        ofSetColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
        thisFunction(ofRandom(ofGetWindowWidth()), ofRandom(ofGetWindowHeight()), ofRandom(10, 100));
        
    }
    
    
     ofSetColor(255, 0, 0);
     thisFunction(ofGetMouseX(), ofGetMouseY(), 10);
    
}

void testApp::thisFunction(float xPos, float yPos, float size){
    
    float circleSpacing = 50;
    
    
    ofSetCircleResolution(50);
    
    
    ofFill();

    ofCircle(xPos + circleSpacing, yPos, size);
    ofCircle(xPos - circleSpacing, yPos, size);

    
    ofPushStyle();
    ofSetColor(0, 255, 0);
    ofCircle(xPos, yPos + circleSpacing, size);
    
    ofPopStyle();
    
    ofCircle(xPos, yPos - circleSpacing, size);
    
    

    ofNoFill();
    ofSetLineWidth(5);
    ofSetColor(0);
    ofCircle(xPos + circleSpacing, yPos, size);
    ofCircle(xPos - circleSpacing, yPos, size);
    ofCircle(xPos, yPos + circleSpacing, size);
    ofCircle(xPos, yPos - circleSpacing, size);

    
    
    ofSetColor(255, 0, 0);
    ofCircle(xPos, yPos, size / 2);


    
}


//--------------------------------------------------------------
void testApp::flower(float x, float y, float x1){
 
    x=300 ;
    y=50;
    x1=500;
    y1=20;
    y2=400;
    x2= 350;
    y3 = 100;
    y4 = 200;
    y5 = 450;
    
    //  ofSetColor(y3, y4, y3);
    ofCircle(x2, x2, y);
    ofCircle(x2, y5, y);
    ofCircle(y5, x2, y);
    ofCircle(y5, y5, y);
    ofCircle(x1, x1, y1);
    ofCircle(x1, x, y1);
    ofCircle(x, x1, y1);
    ofCircle(x, x, y1);
    ofCircle(y2, x1, y1);
    ofCircle(x1, x1, y1);
    ofCircle(y2, x, y1);
    ofCircle(x, y2, y1);
    ofCircle(x1, y2, y1);
    
  //  ofCircle(x, y, x1); //ofCircle  (50, 30, 10);
    //ofCircle(y, x1, x1); //ofCircle (30, 10, 10);
    
    
    
}

//void testApp::flower2(float x2, float y, float x){
//    ofCircle(x2, x2, y);
//    ofCircle(x2, y5, y);
//    ofCircle(y5, x2, y);
//    ofCircle(y5, y5, y);
//    ofCircle(x1, x1, y1);
//    ofCircle(x1, x, y1);
//    ofCircle(x, x1, y1);
//    ofCircle(x, x, y1);
//    ofCircle(y2, x1, y1);
//    ofCircle(x1, x1, y1);
//    ofCircle(y2, x, y1);
//    ofCircle(x, y2, y1);
//    ofCircle(x1, y2, y1);
//    
//    
//    
//}

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
