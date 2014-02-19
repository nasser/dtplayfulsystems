#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackground(0);
    
    
    //top to right
    
    
    int t = 1; 
    
    if(t == 1){
    for(int i = 0; i<1000; i+=10){
    ofSetColor(20, 1+i, 200+i);

    ofLine(x+i, 0, 600, y+i);
        t=2;
        
    }
    }
    
    //bottom right
    if(t ==2){
        //sleep(10);


    for(int i = 0; i<1000; i+=10){
        ofSetColor(20, 10+i, 20+i);
        ofLine(x+i, 600, 600 , y-i);
        t=3; 
        
    }
    }
    
    //bottom left
    if(t==3){

    for(int i = 0; i<1000; i+=10){
        ofSetColor(10+i, 1+i, 20+i);
        ofLine(600-i, 600, 0 , 300-i);
        t=4; 
        
        
    }
    }
    
    if(t==4){

    for(int i = 0; i<1000; i+=10){
        ofSetColor(i, 1+i, 20+i);
       ofLine(0, 600-i, 300+i , 0);
        
        
    }
        
    }
    
    
    
    
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
