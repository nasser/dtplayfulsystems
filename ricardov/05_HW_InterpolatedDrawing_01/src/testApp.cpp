#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    bgColor = 10;
    ofSetWindowShape(1024, 768);
    ofBackground(bgColor);
    ofSetBackgroundAuto(false);
    
    w = ofGetWidth();
    h = ofGetHeight();

    //POS x & y
    x = w/2;
    y = h/2;
    
    //diameter
    d = h/2 - 80;
    
    k = 1/5.0;

}

//--------------------------------------------------------------
void testApp::update(){
    
    //
    x = cos(k * t) * sin(t) * d;
    y = cos(k * t) * cos(t) * d;
    
    //time is framecount, divided so is no  too big
    t = ofGetElapsedTimef()* 9.0;
}

//--------------------------------------------------------------
void testApp::draw(){
    
    float mx = ofMap(mouseX, 0, w, -w/2, w/2);
    float my = ofMap(mouseY, 0, h, -h/2, h/2);

    
    //Rect on bg
    ofSetColor(0, bgColor, 0, 3);
    ofRect(0, 0, w, h);

    //Titles
    ofSetColor(150);
    ofDrawBitmapString("Homework 5- Interpolation (Ricardov):\n- Drawing Roses\nPress Butotns from 1 to 9\nReference: http://en.wikipedia.org/wiki/Rose_(mathematics)", 20, 20);

    ofTranslate(w/2, h/2); // Sicne point appears i the cornerm move it to the center
    //Line from Center
    ofSetColor(220, 10, 220, 180);
    ofLine(mx, my, x, y);

    //Circle on the line
    ofSetColor(220, 200, 50, 220);
    ofCircle(x, y, 2);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    if (key == '1')
    {
        k = 1/1.0;
        ofBackground(bgColor);
        
    }
    if (key == '2')
    {
        k = 1/2.0;
        ofBackground(bgColor);
  
    }
    
    if (key == '3')
    {
        k = 1/3.0;
        ofBackground(bgColor);
        
    }
    if (key == '4')
    {
        k = 1/4.0;
        ofBackground(bgColor);
    
    }
    if (key == '5')
    {
        k = 2/5.0;
        ofBackground(bgColor);
        
    }
    if (key == '6')
    {
        k = 2/6.0;
        ofBackground(bgColor);
        
    }
    if (key == '7')
    {
        k = 2/7.0;
        ofBackground(bgColor);
        
    }
    if (key == '8')
    {
        k = 3/8.0;
        ofBackground(bgColor);
        
    }
    if (key == '9')
    {
        k = 4/2.0;
        ofBackground(bgColor);
        
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
