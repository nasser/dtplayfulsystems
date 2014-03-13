#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255, 255, 255);
    ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------

ofPoint testApp::pointOnLine(ofPoint from, ofPoint to, float t) {
    return ((1-t)*from+(t)*to);
}

//--------------------------------------------------------------


void testApp::draw(){

    //TOP DOWN
    
    ofPoint p1, p2;
    
    p1.set(ofGetWidth()/2, 0+ sin(ofGetElapsedTimef())*(-50));
    p2.set(ofGetWidth()/2+ ofGetElapsedTimef()*20, ofGetHeight());
    
    /*
    ofSetColor(0,0,255);
    ofLine(p1, p2);
 */
 
    ofPoint p3, p4;
    
    p3=p1;
    
    p4.set(ofGetWidth()/2+ ofGetElapsedTimef()* -20, ofGetHeight());
    
    
    //BOTTOM UP
    
    ofPoint p5, p6;
    
    p5.set(ofGetWidth()/2, ofGetHeight()+ sin(ofGetElapsedTimef())*(-50));
    p6.set(ofGetWidth()/2+ ofGetElapsedTimef()*20,0);
    
    /*
    ofSetColor(255, 0, 0);
    ofLine(p5, p6);
    */
    
    
    ofPoint p7, p8;
    
    p7=p5;
    
    p8.set(ofGetWidth()/2+ ofGetElapsedTimef()*-20, 0);
    
    /*
     ofSetColor(255, 0, 0);
     ofLine(p7, p8);
     */
    
    
    
    
    /*
    ofLine(p3,p4);
    
 
    ofSetColor(255, 0, 0);
    ofCircle(p1, 10);
    
    
  
    ofSetColor(0,255,0);
    ofCircle(p2, 10);
 */
    
   
  
     
     
    /*
    sin(ofGetElapsedTimef());
    ofSetBackgroundAuto(false); 
     
    */
    
    
    
    
    ofSetColor(255, 155, 55);
    ofPoint a=pointOnLine(p1, p2, (0.2));
    ofCircle(a,2);
    
    ofSetColor(255, 200, 100);
    ofPoint b=pointOnLine(p1, p2, 0.3);
    ofCircle(b,2);
    
    ofSetColor(255, 55, 155);
    ofPoint c=pointOnLine(p1, p2, 0.4);
    ofCircle(c,2);
    
    ofSetColor(55, 155, 155);
    ofPoint d=pointOnLine(p1, p2, 0.5);
    ofCircle(d,2);
    
    ofSetColor(210, 50, 255);
    ofPoint e=pointOnLine(p1, p2, 0.6);
    ofCircle(e,2);
    
    
    ofSetColor(100, 200, 255);
    ofPoint f=pointOnLine(p1, p2, 0.7);
    ofCircle(f,2);
    
    ofSetColor(5, 5, 155);
    ofPoint g=pointOnLine(p1, p2, 0.8);
    ofCircle(g,2);
    
    ofSetColor(100, 25, 50);
    ofPoint h=pointOnLine(p1, p2, 0.9);
    ofCircle(h,2);
    
    
    
    ofSetColor(255, 155, 55);
    ofPoint i=pointOnLine(p3, p4, (0.2));
    ofCircle(i,2);
    
    ofSetColor(255, 200, 100);
    ofPoint j=pointOnLine(p3, p4, 0.3);
    ofCircle(j,2);
    
    ofSetColor(255, 55, 155);
    ofPoint k=pointOnLine(p3, p4, 0.4);
    ofCircle(k,2);
    
    ofSetColor(55, 155, 155);
    ofPoint l=pointOnLine(p3, p4, 0.5);
    ofCircle(l,2);
    
    ofSetColor(210, 50, 255);
    ofPoint m=pointOnLine(p3, p4, 0.6);
    ofCircle(m,2);
    
    
    ofSetColor(100, 200, 255);
    ofPoint n=pointOnLine(p3, p4, 0.7);
    ofCircle(n,2);
    
    ofSetColor(5, 5, 155);
    ofPoint o=pointOnLine(p3, p4, 0.8);
    ofCircle(o,2);
    
    ofSetColor(100, 25, 50);
    ofPoint p=pointOnLine(p3, p4, 0.9);
    ofCircle(p,2);

    
    ofSetColor(255, 155, 55);
    ofPoint q=pointOnLine(p5, p6, (0.2));
    ofCircle(q,2);
    
    ofSetColor(255, 200, 100);
    ofPoint r=pointOnLine(p5, p6, 0.3);
    ofCircle(r,2);
    
    ofSetColor(255, 55, 155);
    ofPoint s=pointOnLine(p5, p6, 0.4);
    ofCircle(s,2);
    
    ofSetColor(55, 155, 155);
    ofPoint t=pointOnLine(p5, p6, 0.5);
    ofCircle(t,2);
    
    ofSetColor(210, 50, 255);
    ofPoint u=pointOnLine(p5, p6, 0.6);
    ofCircle(u,2);
    
    ofSetColor(100, 200, 255);
    ofPoint v=pointOnLine(p5, p6, 0.7);
    ofCircle(v,2);
    
    ofSetColor(5, 5, 155);
    ofPoint w=pointOnLine(p5, p6, 0.8);
    ofCircle(w,2);
    
    ofSetColor(100, 25, 50);
    ofPoint x=pointOnLine(p5, p6, 0.9);
    ofCircle(x,2);

    
    ofSetColor(255, 155, 55);
    ofPoint a1=pointOnLine(p7, p8, (0.2));
    ofCircle(a1,2);
    
    ofSetColor(255, 200, 100);
    ofPoint b1=pointOnLine(p7, p8, 0.3);
    ofCircle(b1,2);
    
    ofSetColor(255, 55, 155);
    ofPoint c1=pointOnLine(p7, p8, 0.4);
    ofCircle(c1,2);
    
    ofSetColor(55, 155, 155);
    ofPoint d1=pointOnLine(p7, p8, 0.5);
    ofCircle(d1,2);
    
    ofSetColor(210, 50, 255);
    ofPoint e1=pointOnLine(p7, p8, 0.6);
    ofCircle(e1,2);
    
    ofSetColor(100, 200, 255);
    ofPoint f1=pointOnLine(p7, p8, 0.7);
    ofCircle(f1,2);
    
    ofSetColor(5, 5, 155);
    ofPoint g1=pointOnLine(p7, p8, 0.8);
    ofCircle(g1,2);
    
    ofSetColor(100, 25, 50);
    ofPoint h1=pointOnLine(p7, p8, 0.9);
    ofCircle(h1,2);
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
