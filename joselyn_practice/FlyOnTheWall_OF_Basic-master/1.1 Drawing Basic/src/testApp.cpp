#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){


            // Set up background color in Hex
    //ofBackgroundHex(0xEFDC9E);   
    
            // Set up background color in RGB value
    ofBackground(255, 255, 255);
    
     
            //Sets the resolution for the ofCircle command. By default, the circle is 22 points, but if you need to draw larger circles, you can adjust the resolution using this command.
    ofSetCircleResolution(100);
    

     
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

    
   
    ofEnableAlphaBlending();    // turn on alpha blending
    ofSetColor(24, 58, 117,150);


    
    //--------------------------- lines
    ofSetLineWidth(1);
    
    ofSetLineWidth(3);
    ofLine(50, 200, 150, 500);
      ofEnableSmoothing();        //Turns on smoothing, only works for lines.    
    ofSetLineWidth(1);
    ofLine(80, 200, 180, 500);
    ofSetLineWidth(3);
    ofLine(110, 200, 210, 500);
     ofDisableSmoothing();       //Turns off smoothing

    
    //--------------------------- circles
    ofCircle(350, 350, 50);
    ofCircle(350, 350, 100);
    ofCircle(350, 350, 150);

    //--------------------------- rectangles
    ofRect(550, 270, 200, 50);
    ofNoFill();
    ofRect(550, 380, 200, 50);
    ofFill();
    
    ofDisableAlphaBlending();   // turn off alpha blending
    
    
    //--------------------------- ellipse
    ofSetColor(100);
    ofEllipse(850, 350, 50, 150);
       

    //--------------------------- trangle
     ofTriangle(900, 200, 950, 230, 925, 450);
    
    
    
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