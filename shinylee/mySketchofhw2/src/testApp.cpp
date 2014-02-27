#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
ofBackground(255, 255, 255);

ofSetColor(24, 65, 125); 
        
//diamond outline
ofLine(300, 100, 700, 100);
ofLine(200, 300, 800, 300);
ofLine(200, 300, 500, 700);
ofLine(800, 300, 500, 700);
ofLine(300, 100, 200, 300);
ofLine(700, 100, 800, 300);
ofLine(300, 100, 500, 300);
ofLine(700, 100, 500, 300);
ofLine(350, 300, 500, 700);
ofLine(650, 300, 500, 700);
ofLine(350, 300, 500, 100);
ofLine(650, 300, 500, 100);
    

//inside
    
    ofSetColor(73, 120, 191, 100);
    
    for (int i=0 ; i<30 ;i++){
        ofLine(500, 700, 200+i*20, 300);
    }
    
    for (int i=0 ; i<30 ;i++){
        ofLine(300, 100, 200+i*20, 300);
    }
    
    for (int i=0 ; i<30 ;i++){
        ofLine(700, 100, 200+i*20, 300);
    }
   
    for (int i=0 ; i<20 ;i++){
        ofLine(500, 300, 300+i*20, 100);
    }
    
    
    
//    for (int i=0 ; i<10 ;i++){
//        ofLine(200+i*10,0,200+i*20,500);
//        }
//    
//    for (int i=0 ; i<10 ;i++){
//        ofLine(300+i*10,200,200+i*30,100);
//    }

   
    

    
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
