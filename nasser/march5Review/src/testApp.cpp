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
    smallRect.set(0, 0, 3, 5);
    float a = smallRect.getArea();
    // side effecting method call
    smallRect.growToInclude(100, 200);
    
    // drawing line at x = half time
    ofLine(halfTime, 0, halfTime, 100);
    
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
