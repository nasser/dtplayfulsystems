#include "testApp.h"

ofPolyline line, line1, line2, line3;


ofPoint testApp:: pointOnLine(float t, ofPoint p1, ofPoint p2){
    t = ofClamp(t, 0, 1);
    
    return (p2 - p1) * t + p1;
    
    //ofPoint returns a point
}


void ofPath::bezierTo(const ofPoint &cp1, const ofPoint &cp2, const ofPoint &p){
 
    
}


//--------------------------------------------------------------
void testApp::setup(){
    ofSetBackgroundAuto(false);



    
}

//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    ofPoint from, to, circleCenter, circleCenter1, from1, to1, circleCenter2, from2, to2, circleCenter3, from3, to3;
    
    
    
    line.addVertex(ofPoint(0, 0));
    line.addVertex(ofPoint(ofGetWidth(), ofGetHeight()));
    line.addVertex(ofPoint(from));
    line.addVertex(ofPoint(to));
    line.addVertex(ofPoint(from1));
    line.addVertex(ofPoint(to1));
    line.addVertex(ofPoint(508, 100));
    line.addVertex(ofPoint(500, 100));
    line.addVertex(ofPoint(ofGetWidth(), 0));
    
    
    line.close();


    ofFill();
    ofSetColor(ofColor::red);
    line.draw();
    line1.draw();
    line3.draw();

    
    //high =
    //low.set = ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1), ;
    
    from3.set(0, ofGetHeight()/3);
    to3.set(ofGetWidth(),ofGetHeight());
    
    from2.set(0, ofGetHeight());
    to2.set(ofGetWidth(),0); 
    
    from1.set(ofGetWidth(), 0);
    to1.set(0, ofGetHeight());
    
    from.set(50,  ofGetHeight()/2);
    //from = pointOnLine(ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1), from1, to1);
    to.set(ofGetWidth() - 50, ofGetHeight()/2); // to make the ball move diagonally you'll move the ofGetHeight to 0;
    
   
    // this part is about easing ::
    
    float t = ofMap(sin( ofGetElapsedTimef()), -1, 1, 0, 1);
    
    //  float t = ofGetElapsedTimef() - int(ofGetElapsedTimef());  //this reduces the float to just the part after the decimal
    
    t = pow(t, 2); // t= t^2
    
    //circleCenter = pointOnLine(ofMap(sin( ofGetElapsedTimef()), -1, 1, 0, 1),  from, to);
    
    circleCenter = pointOnLine(t, from, to);
    circleCenter1 = pointOnLine(t, from1, to1);
    circleCenter2 = pointOnLine(t, from2, to2);
    circleCenter3 = pointOnLine(t, from3, to3);

    
    //cout<< circleCenter <<endl;
    
    
    ofCircle(circleCenter, 10);
    ofCircle(circleCenter1, 10);
    ofCircle(circleCenter2, 10);
    ofCircle(circleCenter3, 10);

 
  
    
    
    
    
    
    
   //this is a sin wave

    
    float a = 0.0;
    float inc = TWO_PI/25.0;
    float prev_x = 0, prev_y = 50, x, y;
    
    for(int i=0; i<2000; i=i+20) {
        x = i;
        y = 50 + sin(a) * 40.0;
        ofLine(prev_x, prev_y, x, y);
        prev_x = x;
        prev_y = y;
        a = a + inc;
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
