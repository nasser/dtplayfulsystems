#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofEnableSmoothing();
    ofBackground(0, 0, 0);
    ofSetBackgroundAuto(false);

    
    ofSetLineWidth(.1);
        myfont.loadFont("arial.ttf", 32);
}

//--------------------------------------------------------------
void testApp:: drawPointOnLine(ofPoint p1, ofPoint p2, float t){
    t = ofClamp(t, 0, 1);
    ofPoint circleCenter = p1.getInterpolated(p2, t);
    
    ofCircle(circleCenter, 5);
    ofLine(p1, p2);
    ofCircle(p1, 3);
    ofCircle(p2, 3);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

    ofSetColor(51, 204, 204, 1);

    
    drawStar();
    
//    float step = 170;
//    for (float i = 0; i < 8; i++) {
//        for (float z = 0; z <= 340; z+=170) {
//            ofPushMatrix();
//            ofTranslate(z, i*step);
//            drawStar();
//            ofPopMatrix();
//        }
//    }
    
//    ofSetColor(51, 204, 204, 1);
    ofPoint p1, p2, d1, d2, a1, a2;
    ofPoint x, y, x2, y2, x3, y3, x4, y4;
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    for (float i = 15; i < 360; i+=30) {
        float angle = ofDegToRad(i);
        x.set((200/2 + cos(angle)* (min(200, 200)/2)*0.72), (200/2 + sin(angle)* (min(200, 200)/2)*0.72));
        //float y = (200/2 + sin(angle)* (min(200, 200)/2)*0.72);
        //line(width/2, height/2, x, y);
        for (float z = 0; z < 360; z+=30) {
            float angle2 = ofDegToRad(z);
            x2.set((200/2 + cos(angle2)* (min(200, 200)/2)*0.15), ((200/2 + sin(angle2)* (min(200, 200)/2)*0.15)));
            //float y2 = (200/2 + sin(angle2)* (min(200, 200)/2)*0.15);
            //line(width/2, height/2, x2, y2);
            //this line creates the big star and middle star
            ofLine(x2, x);
            x3.set ((200/2 + cos(angle)* (min(200, 200)/2)*0.85), (200/2 + sin(angle)* (min(200, 200)/2)*0.85));
            //float y3 = (200/2 + sin(angle)* (min(200, 200)/2)*0.85);
            //this line extends the big star
            ofLine(x, x3);
            x4.set((200/2 + cos(angle2)* (min(200, 200)/2)*0.88), (200/2 + sin(angle2)* (min(200, 200)/2)*0.88));
            //float y4 = (200/2 + sin(angle2)* (min(200, 200)/2)*0.88);
            //this line closes the extensions
            ofLine(x3, x4);
//            for (int i = 0; i <100; i++){
//                drawPointOnLine(x, x2, cos(ofGetElapsedTimef()+.01*i));
//            }

        }
    }
    
//    
//    ofTranslate(0, 40);
//    p1.set(ofGetWidth()/2, 10);
//    p2.set(ofGetWidth()/2, ofGetHeight()/2);
//    d1.set(ofGetWidth()/2, 10);
//    d2.set(0, ofGetHeight()/2);
//    a1.set(ofGetWidth()/2, 10);
//    a2.set(ofGetWidth(), ofGetHeight()/2);
//    
//    for (int i = 0; i <100; i++){
//        drawPointOnLine(p1 + ofPoint(i*5, 5*i), p2, cos(ofGetElapsedTimef()+.01*i));
//    }
//    for (int i = 0; i <100; i++){
//        drawPointOnLine(d1 + ofPoint(i*5, 5*i), d2, cos(ofGetElapsedTimef()+.01*i));
//    }
//    for (int i = 0; i <100; i++){
//        drawPointOnLine(a1 + ofPoint(i*5, 5*i), a2, cos(ofGetElapsedTimef()+.01*i));
//    }
//    
//    //    for (int i = 0; i <100; i++){
//    //        drawPointOnLine(p1 + ofPoint(i*10, 1*i), p2, sin(ofGetElapsedTimef()+i));
//    //    }
}



//--------------------------------------------------------------
void testApp::drawStar(){
    
    for (float i = 15; i < 360; i+=30) {
        float angle = ofDegToRad(i);
        float x = (200/2 + cos(angle)* (min(200, 200)/2)*0.72);
        float y = (200/2 + sin(angle)* (min(200, 200)/2)*0.72);
        //line(width/2, height/2, x, y);
        for (float z = 0; z < 360; z+=30) {
            float angle2 = ofDegToRad(z);
            float x2 = (200/2 + cos(angle2)* (min(200, 200)/2)*0.15);
            float y2 = (200/2 + sin(angle2)* (min(200, 200)/2)*0.15);
            //line(width/2, height/2, x2, y2);
            //this line creates the big star and middle star
            ofLine(x2, y2, x, y);
            float x3 = (200/2 + cos(angle)* (min(200, 200)/2)*0.85);
            float y3 = (200/2 + sin(angle)* (min(200, 200)/2)*0.85);
            //this line extends the big star
            ofLine(x, y, x3, y3);
            float x4 = (200/2 + cos(angle2)* (min(200, 200)/2)*0.88);
            float y4 = (200/2 + sin(angle2)* (min(200, 200)/2)*0.88);
            //this line closes the extensions
            ofLine(x3, y3, x4, y4);
        }
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
