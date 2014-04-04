#include "testApp.h"


//--------------------------------------------------------------
void testApp:: drawPointOnLine(ofPoint p1, ofPoint p2, float t){
    t = ofClamp(t, 0, 1);
    ofPoint circleCenter = p1.getInterpolated(p2, t);
        
    ofCircle(circleCenter, 50);
//    ofSetLineWidth(3);
////    ofLine(p1, p2);
//    ofCircle(p1, 30);
//    ofCircle(p2, 30);
}

//--------------------------------------------------------------
void testApp::setup(){
    
    
    ofSetBackgroundAuto(false);
    ofBackground(0);


    
     rgbaFboFloat.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F_ARB);
    
    rgbaFboFloat.begin();
	ofClear(255,255,255, 0);
    rgbaFboFloat.end();
    
    
    fish.loadImage("images/fishTest1.png");
    fish.resize(fish.width/4, fish.height/4);




}

//--------------------------------------------------------------
void testApp::update(){
    
    rgbaFboFloat.begin();
    drawFboTest();
	rgbaFboFloat.end();
    
}
//--------------------------------------------------------------
ofPoint testApp::pointOnLine(float t, ofPoint p1, ofPoint p2, ofPoint p3, ofPoint p4){
    t = ofClamp(t, 0, 1);
    
    return(p2 - p1)*t+p1;
}

//--------------------------------------------------------------
void testApp::drawFboTest(){
    
	//1 - Fade Fbo
	
	//this is where we fade the fbo
	//by drawing a rectangle the size of the fbo with a small alpha value, we can slowly fade the current contents of the fbo.
	ofFill();
	ofSetColor(255,255,255, fadeAmnt);
	ofRect(0,0,ofGetWidth(),ofGetHeight());
    
	//Draw circle based on mouse position
    ofSetColor(255,0,0);
    ofFill();
	ofCircle(ofGetMouseX()-40, ofGetMouseY()-40, 8);

    
}

//----

void testApp:: drawFish(){
    
}


//--------------------------------------------------------------
void testApp::draw(){
    
    

    
    ofSetColor(255, 0, 9, 15);
    
    
    fish.draw(userX, userY);
    
    
    
    ofSetColor(0,0,0);
    rgbaFboFloat.draw(0,0);
    
    ofSetColor(20, 2, 200, 1);

    
    ofPoint from, to, from1, to1, from2, to2, circleCenter, circleCenter2, circleCenter3, circleCenter4, circleCenter5;
    
    from2.set(ofGetWidth()/2, ofGetHeight());//(0, y)
    to2.set(ofGetWidth()/2, ofGetHeight());
    from1.set(0, ofGetHeight());
    to1.set(0,0);
    from.set(0, ofGetHeight()/2);
    to.set(ofGetWidth()-100, ofGetHeight()/2);
    
    from = pointOnLine(ofMap(sin(ofGetElapsedTimef()*2), -1, 1, 0, 1), from1, to1, from2, to2);
    to.set(ofGetWidth(), ofGetHeight()/2);
    
    //float t = ofMap(sin(ofGetElapsedTimef()));
    
    circleCenter = pointOnLine(ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1), from, to, from2, from1);
    circleCenter2 = pointOnLine(ofMap(sin(ofGetElapsedTimef()-.1), -1, 1, 0, 1), from, to, from2, from1);
    circleCenter3 = pointOnLine(ofMap(sin(ofGetElapsedTimef()-.2), -1, 1, 0, 1), from, to, from2, from1);
    
    circleCenter4 = pointOnLine(ofMap(sin(ofGetElapsedTimef()-.3), -1, 1, 0, 1), from, to, from2, from1);
    circleCenter5 = pointOnLine(ofMap(sin(ofGetElapsedTimef()-.5), -1, 1, 0, 1), from, to, from2, from1);
    
    ofCircle(circleCenter, 40);
    ofSetColor(0, 34, 255, 50);
    ofCircle(circleCenter2, 30);
  ofSetColor(0, 56, 255, 50);
    ofCircle(circleCenter3, 20);
  ofSetColor(0, 32, 255, 50);
    ofCircle(circleCenter4, 10);
    
    
    //ofCircle(circleCenter5, 5);
//    ofCircle(from, 2);
//    ofCircle(to, 2);

    
//    ofCircle(userX, userY, 10);
//    fish.draw(userX, userY);
    

//    ofSetColor(51, 204, 204, fadeAmnt);
//    ofPoint p1, p2, d1, d2, a1, a2;
//    
//    
//    ofTranslate(0, 0);
//    p1.set(sin(ofGetElapsedTimef())/2, cos(ofGetElapsedTimef()));
//    p2.set(ofGetWidth()/2, ofGetHeight()/2);
//    d1.set(ofGetWidth()/2, 10);
//    d2.set(0, ofGetHeight()/2);
//    a1.set(ofGetWidth()/2, 10);
//    a2.set(ofGetWidth(), ofGetHeight()/2);
    
//    for (int i = 0; i <100; i++){
//        drawPointOnLine(p1 + ofPoint(i+15, 5*i), p2, cos(ofGetElapsedTimef()+100*i));
//    }
//    for (int i = 0; i <100; i++){
//        drawPointOnLine(d1 + ofPoint(i*5, 5*i), d2*i, cos(ofGetElapsedTimef()+.01*i));
//    }
//    for (int i = 0; i <100; i++){
//        drawPointOnLine(a1 + ofPoint(i*5, 5*i), a2, cos(ofGetElapsedTimef()+.01*i));
//    }
    

    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    userX = x;
    userY = y;
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    pct = 0.0;
    beginX = x;
    beginY = y;
    endX = mouseX;
    endY = mouseY;
    distX = endX - beginX;
    distY = endY - beginY;
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
