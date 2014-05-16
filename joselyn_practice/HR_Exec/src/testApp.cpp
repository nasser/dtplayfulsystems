#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    x1= 0;
    y1= 0;
    
    x2= ofGetWidth()-10;
    y2= ofGetHeight()/2;
    
    

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
   
    ofBackground(0);
    ofDrawBitmapString("Welcome to XCorp", ofGetWidth()/2-40, ofGetHeight()/2);
    ofDrawBitmapString("Press A to begin work", ofGetWidth()/2-60, ofGetHeight()/2+20);

    
    if (next == true){
    ofBackground(255); 
    ofSetColor(255, 0, 0);
    ofFill();
    ofRect(x1, y1, size, size);
        ofSetColor(0);
        
    ofDrawBitmapString("Drag Resumes to Trash Bin", ofGetWidth()/2-75, ofGetHeight()/2);
        ofRect(ofGetWidth()-70, ofGetHeight()-90, 70, 90);
        

        
        if (add == true){
            ofSetColor(255, 0, 255);
            ofFill();
            y2 - 10;
            ofRect(x2, y2, 10, 10);

        }
        


    }
    
  
    


}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    if("a" || "A"){
        next = true; 
    }

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
    if(mouseX > x1 && mouseX< x1 + size){
        if(mouseY > y1 && mouseY < y1 +size){
            x1 = mouseX -size/2;
            y1 = mouseY -size/2;
        }
        
    }
    
    
    if (x1 > ofGetWidth() - size && y1 > ofGetHeight()-size){
        x1 = 0;
        y1 = 0;
        
        add = true; 
    }

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
