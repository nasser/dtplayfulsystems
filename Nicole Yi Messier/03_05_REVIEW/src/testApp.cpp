#include "testApp.h"

// ... in a cpp file
/*
 
 Person ramsey;
 ramsey.height = 170;
 ramsey.job = "hacker";
 
 ramsey.getIdentityString(); // "my name height is 170.0 and my job is hacker"
 
 Person tim;
 tim.height = 180;
 tim.job = "accountant";
 
 */

//--------------------------------------------------------------
void testApp::setup(){
    
}

//--------------------------------------------------------------
void testApp::update(){
    halfTime = ofGetElapsedTimef() / 2;
}

void testApp::drawShape(float x, float y) {
    ofRect(x, y, 50, 50);
    ofRect(x + 100, y, 50, 50);
}

//--------------------------------------------------------------
void testApp::draw(){
    // using a returned value
    ofRectangle smallRect;
    smallRect.set(0, 0, 30, 50);
 
    
    // side effecting method call
    //Modify the ofRectangle so that the x and y coordinates given are both enclosed within the rectangle. This will potentially change the width, height, x position, and y position of the ofRectangle.
    smallRect.growToInclude(100, 200);
    float a = smallRect.getArea();
    cout << a << endl;
    
    // drawing line at x = half time
    ofLine(halfTime*100, 0, halfTime, 100);
    
    drawShape(halfTime, ofGetHeight()/2);
    
    cout << &halfTime << endl;
    
    float angle = 0;
    while (angle < TWO_PI ) {
        b.curveTo(100*cos(angle), 0, 100*sin(angle));
        b.curveTo(300*cos(angle), 300, 300*sin(angle));
        angle += TWO_PI / 30;
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