#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofSetBackgroundAuto(false);

    ofBackground(0);

    circleCenter.set(ofGetWidth()/2, ofGetHeight()/2);
    
    fish.loadImage("images/fishTest1.png");
    fish.resize(fish.width / 4, fish.height / 4);

    startPoint.set(mousePosX, mousePosY);
    cP1.set(ofRandom(20,ofGetWidth()-20),ofRandom(20,ofGetHeight()-20),0);
    cP2.set(ofRandom(20,ofGetWidth()-20),ofRandom(20,ofGetHeight()-20),0);
    
    endPoint.set(ofRandom(400,ofGetWidth()-400),ofRandom(400,ofGetHeight()-400),0);

    
}

//--------------------------------------------------------------
void testApp::update(){
//    if(circleCenter.x == destination.x){
//        circleCenter.x = destination.x;
//    }
//    else{
//    circleCenter.x += 1;
//    }
    
//    circleCenter.interpolate(destination, 0.05);
    

    
    if(circleCenter.distance(destination) <= 4.4){
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
    
    
    
    ofSetColor(255, randomColor, 9, 15);


    fish.draw(circleCenter);

    ofSetColor(0, ofRandom(34, 200), 255, 5);

    ofFill();
    ofDrawBitmapString(ofToString(circleCenter.distance(destination)), 10, 10);
    ofCircle(destination, 5);
    

  
    
    from2.set(ofGetWidth()/2, ofGetHeight());//(0, y)
    to2.set(ofGetWidth()/2, ofGetHeight());
    from1.set(0, ofGetHeight());
    to1.set(0,0);
    from.set(0, ofGetHeight()/2);
    //to.set(ofGetWidth()-100, ofGetHeight()/2);
    
    from = pointOnLine(ofMap(sin(ofGetElapsedTimef()*2), -1, 1, 0, 1), from1, to1, from2, to2);
    to.set(ofGetWidth(), ofGetHeight()/2);    
    //float t = ofMap(sin(ofGetElapsedTimef()));
    
    //circleCenter = pointOnLine(ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1), from, to, from2, from1);
    circleCenter2 = pointOnLine(ofMap(sin(ofGetElapsedTimef()-.1), -1, 1, 0, 1), from, to, from1, from2);
    circleCenter3 = pointOnLine(ofMap(sin(ofGetElapsedTimef()-.2), -1, 1, 0, 1), from, to, from2, from1);
    
    circleCenter4 = pointOnLine(ofMap(sin(ofGetElapsedTimef()-.3), -1, 1, 0, 1), from, to, from2, from1);
    circleCenter5 = pointOnLine(ofMap(sin(ofGetElapsedTimef()-.5), -1, 1, 0, 1), from, to, from2, from1);
//    
//    ofCircle(circleCenter, 10);
//    ofCircle(circleCenter2, 10);

    
    //ofCircle(circleCenter, 40);
//    ofSetColor(0, 34, 255, 50);
    //ofLine(circleCenter2, circleCenter3);
//    ofCircle(circleCenter2, 30);
//    ofSetColor(0, 56, 255, 50);
//    ofCircle(circleCenter3, 20);
//    ofSetColor(0, 32, 255, 50);
//    ofCircle(circleCenter4, 10);
    
    
//    ofCircle(startPoint.x,startPoint.y,6);
    ofCircle(cP1.x,cP1.y,3);
    ofCircle(cP2.x,cP2.y,3);
//    ofCircle(endPoint.x,endPoint.y,6);
    
    
    
    glBegin(GL_LINE_STRIP);
    
    for( int i = 0; i < 101; i++)
    {
//        ofSetColor(0, ofRandom(34, 200), 255, 5);
//        ofPoint pt = getBezier4Pt( startPoint,cP1, cP2,endPoint, i / 100.f );
//        glVertex3f(pt.x,pt.y,0);
//        glVertex3f(pt.x,pt.y,0);
        
    }
    
    glEnd();
    
    
    ofCircle(getBezier4Pt( startPoint,cP1, cP2,endPoint, ofMap(sin(ofGetElapsedTimef()-.1), -1, 1, 0, 1)), 10);
        
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    from1.set(ofRandom(20,ofGetWidth()-20),ofRandom(20,ofGetHeight()-20),0);
    
    to1.set(ofRandom(20,ofGetWidth()-20),ofRandom(20,ofGetHeight()-20),0);
    from2.set(ofRandom(20,ofGetWidth()-20),ofRandom(20,ofGetHeight()-20),0);
    
    to2.set(ofRandom(400,ofGetWidth()-400),ofRandom(400,ofGetHeight()-400),0);

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

    cP1.set(ofRandom(20,ofGetWidth()-20),ofRandom(20,ofGetHeight()-20),0);
    cP2.set(ofRandom(20,ofGetWidth()-20),ofRandom(20,ofGetHeight()-20),0);
    
    endPoint.set(ofRandom(400,ofGetWidth()-400),ofRandom(400,ofGetHeight()-400),0);
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
    mousePosX = x;
    mousePosY = y;
    
    destination.set(mouseX-20, mouseY-10);

    startPoint.set(x, y);

    //destination.set(x, y);
    //circleCenter.set(x, y);

    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
   // circleCenter.set(mouseX, mouseY);
   // destination.set(ofRandom(0, ofGetWidth()-50), ofRandom(0, ofGetHeight()));
   // destination.set(mouseX, mouseY);

    randomColor = ofRandom((0, 255));
    
    userX = x;
    userY = y;
    
    mousePosX = x;
    mousePosY = y;
    startPoint.set(x, y);
    

    
    
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
