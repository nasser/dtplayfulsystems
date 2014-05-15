#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    manualTarget = ofPoint(ofGetWidth()/2, ofGetHeight()/2);
    
    for (int i=0; i<200; i++) {
        Flocker f;
        f.point = ofPoint(ofRandomWidth(), ofRandomHeight());
        f.speed = 1;
        f.angle = 0;
        flockers.push_back(f);
        
        // points.push_back(ofRandomWidth(), ofRandomHeight());
        // angles.push_back(0);
        // speeds.push_back(0);
    }
}

//--------------------------------------------------------------
void testApp::update(){
    manualTarget.x = mouseX;
    manualTarget.y = mouseY;
    
    // cohesion - move towards average position
    /*
    for (int i=0; i<points.size(); i++) {
        ofPoint neighborAverage = ofPoint(0, 0);
        int neighborCount = 0;
        
        // find neighbors
        for (int j=0; j<points.size(); j++) {
            if( points[i].distance(points[j]) <= 100 ) {
                // we know points[j] is a neighbor
                neighborAverage = neighborAverage + points[j];
                neighborCount++;
            }
        }
        
        // calculate neighbor average point
        neighborAverage = neighborAverage / neighborCount;
        
        // move towards neighbor average point
        points[i].interpolate(neighborAverage, 0.1);
    }
    */
    
    /*
    ofPoint flockAverage = ofPoint(0, 0);
    for (int i=0; i<points.size(); i++) {
        flockAverage += points[i];
    }
    flockAverage = flockAverage / points.size();
    
    for (int i=0; i<points.size(); i++) {
        points[i].interpolate(flockAverage, 0.01);
    }
    */
    
    /*
    // move towards manualTarget
    for (int i=0; i<points.size(); i++) {
        points[i].interpolate(manualTarget, 0.01);
    }
    */
    
    // steer randomly
    /*
    for (int i=0; i<angles.size(); i++) {
        angles[i] += ofSignedNoise(ofGetElapsedTimef(), i) * 0.1;
    }
    */
    
    // speed up/slow down randomly
    /*
    for (int i=0; i<speeds.size(); i++) {
        speeds[i] += ofSignedNoise(ofGetElapsedTimef(), i) * 0.1;
    }
    */

    // move
    for (int i=0; i<flockers.size(); i++) {
        flockers[i].move();
        
        // points[i].x += cos(angles[i])*speeds[i];
        // points[i].y += sin(angles[i])*speeds[i];
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0, 0, 0);
    ofSetColor(255, 255, 255);
    for (int i=0; i<flockers.size(); i++) {
        flockers[i].draw();
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
//    points.push_back(ofPoint(ofRandomWidth(), ofRandomHeight()));
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
