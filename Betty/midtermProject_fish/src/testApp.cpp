#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetBackgroundAuto(false);

    ofBackground(0);
    
    circleCenter.set(ofGetWidth()/2, ofGetHeight()/2);
    
    fishRight.loadImage("images/fishRight.png");
    fishRight.resize(fishRight.width / 4, fishRight.height / 4);
    
    fishLeft.loadImage("images/fishLeft.png");
    fishLeft.resize(fishLeft.width / 4, fishLeft.height / 4);
    
    startPoint.set(mousePosX, mousePosY);
    cntrlP1.set(ofRandom(20,ofGetWidth()-20),ofRandom(20,ofGetHeight()-20),0);
    cntrlP2.set(ofRandom(20,ofGetWidth()-20),ofRandom(20,ofGetHeight()-20),0);
    endPoint.set(ofRandom(400,ofGetWidth()-400),ofRandom(400,ofGetHeight()-400),0);
    
    
}

//----------------------------------------------------------------------------------

ofPoint testApp:: getBezier4Pt( ofPoint p1, ofPoint p2, ofPoint p3, ofPoint p4,float mu )
{
    double mum1,mum13,mu3;
    ofPoint p;
    
    mum1 = 1 - mu;
    mum13 = mum1 * mum1 * mum1;
    mu3 = mu * mu * mu;
    
    p.x = mum13*p1.x + 3*mu*mum1*mum1*p2.x + 3*mu*mu*mum1*p3.x + mu3*p4.x;
    p.y = mum13*p1.y + 3*mu*mum1*mum1*p2.y + 3*mu*mu*mum1*p3.y + mu3*p4.y;
    p.z = mum13*p1.z + 3*mu*mum1*mum1*p2.z + 3*mu*mu*mum1*p3.z + mu3*p4.z;
    
    return(p);
}

//--------------------------------------------------------------
void testApp::update(){
    
    if(circleCenter.distance(destination) <= 3.0){
        circleCenter = destination;
    }
    else{
        circleCenter.interpolate(destination, 0.05);
    }
}

//--------------------------------------------------------------
ofPoint testApp::pointOnLine(float t, ofPoint p1, ofPoint p2, ofPoint p3, ofPoint p4){
    t = ofClamp(t, 0, 1);
    
    return(p2 - p1)*t+p1;
}

//--------------------------------------------------------------
void testApp::draw(){
    

    //sets colors to different shades of red
    ofSetColor(255, randomColor, 9, 15);
    
    //flips direction of the fish based on acceleration 
    if(ofGetPreviousMouseX() < mouseX){
        fishRight.draw(circleCenter);
    }
    if(ofGetPreviousMouseX() > mouseX){
        fishLeft.draw(circleCenter);
      //  fish.draw(circleCenter);
//
    }
    
    //sets colors to different shades of blue
    ofSetColor(0, ofRandom(34, 200), 255, 5);
    
    ofFill();
    
    //bezier curve circles
    //    ofCircle(startPoint.x,startPoint.y,6);
    ofCircle(cntrlP1.x,cntrlP1.y,3);
    ofCircle(cntrlP2.x,cntrlP2.y,3);
    //    ofCircle(endPoint.x,endPoint.y,6);
    
    
    
    glBegin(GL_LINE_STRIP);
    for( int i = 0; i < 101; i++)
    {
        ofSetColor(0, ofRandom(34, 200), 255, 5);
        ofPoint pt = getBezier4Pt( startPoint,cntrlP1, cntrlP2,endPoint, i / 100.f );
        glVertex3f(pt.x,pt.y,0);
        glVertex3f(pt.x,pt.y,0);
    }
    glEnd();
    
    //draws circle along the bezier curve
    ofCircle(getBezier4Pt( startPoint,cntrlP1, cntrlP2,endPoint, ofMap(sin(ofGetElapsedTimef()-.1), -1, 1, 0, 1)), 5);
        
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    
    cntrlP1.set(ofRandom(20,ofGetWidth()-20),ofRandom(20,ofGetHeight()-20),0);
    cntrlP2.set(ofRandom(20,ofGetWidth()-20),ofRandom(20,ofGetHeight()-20),0);
    endPoint.set(ofRandom(400,ofGetWidth()-400),ofRandom(400,ofGetHeight()-400),0);
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
    mousePosX = x;
    mousePosY = y;
    
    destination.set(mousePosX, mousePosY);
    
    startPoint.set(x + 39, y+42);
    
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
    randomColor = ofRandom((0, 255));

    mousePosX = x;
    mousePosY = y;
    
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
