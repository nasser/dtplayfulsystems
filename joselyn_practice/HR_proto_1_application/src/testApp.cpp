#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    application.loadImage("application.png");
    
    verdana30.loadFont("verdana.ttf", 30);
	verdana30.setLineHeight(34.0f);
	verdana30.setLetterSpacing(1.035);
    
    //savedTime = ofGetElapsedTimef();

    

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    application.draw(0, 0, ofGetWidth()/2, ofGetHeight());
    application.draw(ofGetWidth()/2, 0, ofGetWidth()/2, ofGetHeight());
   
    
    //ofSetColor(0);
    ofDrawBitmapString("woman", 20, 20);
    ofDrawBitmapString("man", ofGetWidth()/2, 20);

 
    
    if (flip1 == true){
        
        ofBackground(0);
        
        savedTime = ofGetElapsedTimef();

        passedTime = ofGetElapsedTimef() - savedTime; 
        
        
        cout<< passedTime << endl; 
        
        if(passedTime >= totalTime){
            ofBackground(255);
            
            
            //application.draw(0, 0, ofGetWidth()/2, ofGetHeight());
            //application.draw(ofGetWidth()/2, 0, ofGetWidth()/2, ofGetHeight());
        }
        
        
    }
    
    if(flip2 == true){
        ofBackground(255,0, 255);
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
    
    if (mouseX <= ofGetWidth()/2){
        
        flip1 = true;
    } else if (mouseX > ofGetWidth()/2){
        
        flip2 = true; 
    }

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
