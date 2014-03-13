#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------


void testApp:: drawStar(float x, float y, float size){
  
    
    //draws star
 
    ofLine(x+0, y+100, x+100, y+100);
    ofLine(x+100, y+100, x+150, y+0);
    ofLine(x+150, y+0, x+200, y+100);
    ofLine(x+200, y+100, x+300, y+100);
    ofLine(x+300, y+100, x+200, y+150);
    ofLine(x+200, y+150, x+250, y+250);
    ofLine(x+250, y+250, x+150, y+200);
    ofLine(x+150, y+200, x+50, y+250);
    ofLine(x+50, y+250, x+100, y+150);
    ofLine(x+100, y+150, x+0, y+100);
   
    

    ofSetColor(255, 0, 0);
    
    /*
    ofBeginShape();
    ofVertex(x + 0, y + 10);
    ofVertex(x + 10, y + 10);
    ofVertex(x + 15, y + 0);
    ofEndShape();
    */
}



//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackground(255, 255, 255);
    
    //Type
    
    string title = "Creative Coding";
    
    ofDrawBitmapString(title, ofGetWidth()/2 - (title.length()*8)/2, 30);
    
    string title1 = "Homework Assignment";
    
    ofDrawBitmapString(title1 ,ofGetWidth()/2 - (title1.length()*8)/2, 45);
    
    string title2 = "Due February 26";
    
    ofDrawBitmapString(title2, ofGetWidth()/2- (title2.length()*8)/2, 60);
    
    string title3 = "Sandrofredericoz";
    
    ofDrawBitmapString(title3,ofGetWidth()/2-(title3.length()*8)/2, 75);

 
    // write code in curly brackets .. stays within the loop and does this code all the time
    
    
    /*
    for (int i=10; i<100; i++){
        
        drawStar(i*10, i*7.5, 10);
    }
    */
    
    
    ofSetColor(0, 0, 255);
    
    for (int i=100; i>50; i = i - 1){
        
        drawStar(i*5, i*2.5, 5);
    }

    
    //Notes
    
    /*
     i = i + 1
     i += 1
     i++
     */
    
    
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
