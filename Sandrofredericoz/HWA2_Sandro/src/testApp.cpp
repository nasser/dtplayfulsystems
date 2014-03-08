#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

    /*
    ofLine(ofGetWidth()/2,ofGetHeight()/2, 10, ofGetHeight());
    ofLine(ofGetWidth()/2,ofGetHeight()/2, 100, ofGetHeight());
    */
       
    //Black Backgrounud
    ofBackground(0, 0, 0);
    
    //Type
    
    string title = "Creative Coding";

    ofDrawBitmapString(title, ofGetWidth()/2 - (title.length()*8)/2, 30);
    ofDrawBitmapString("Homework Assignment" ,ofGetWidth()/2, 45);
    ofDrawBitmapString("Due February 19", ofGetWidth()/2, 60);
    ofDrawBitmapString("Sandrofredericoz",ofGetWidth()/2, 75);
    
    ofSetColor(255, 255, 255);
    

    
    //Triangle
    
    
    //Circle in the middle
    for(float i = 1; i <150; i+=1){
        ofEllipse(ofGetWidth()/2, ofGetHeight()/2, i*2, i*2);
    }
    

    //ofLine top right
   
        
        for(int i = 0; i<1000; i = i + 10){
            
            ofSetColor(255, 0, 255);
            
            ofLine(i+1, i+i, ofGetWidth(), ofGetHeight());
            
        
    }
        
    //ofLine Top lefts
    
                
        for(int i = 0; i<1000; i = i+ 10){
            
            ofSetColor(255, 255, 255);
        
            ofLine(i+1, i+i, 0, ofGetHeight());
        }
   
  
 
    //mirror ofLine top right
    
        
        for(int i = 0; i<1000; i = i + 10){
            
            ofSetColor(255, 0, 0);
            
            ofLine(ofGetWidth()-(i-1), i+i, 0, ofGetHeight());
            
        }
        
   
    //mirror ofLine bottom right
    
    
    for(int i = 0; i<1000; i = i+ 10){
        
        ofSetColor(0, 255, 255);
        
        ofLine(ofGetWidth(), ofGetHeight(),ofGetWidth()-(i-1), i+i);
    }
    


    
    
    
     //Notes
            
    /*
     i = i + 1
     i += 1
     i++
     */
    
    
    /*
     
     for (int i=0; i<100; i++) {
     for (int j=0; j<100; j++) {
     ofSetColor(i, j, i+j);
     ofRect(i*10, j*10, 10, 10);
     
     */
    

}
//----------------------------------------------------------






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
