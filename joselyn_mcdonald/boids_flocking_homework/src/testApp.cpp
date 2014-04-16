#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    donut.loadImage("mouth.png");

    donut.loadImage("donut2.png");
    donut.resize(100, 100);
    int w = donut.getWidth();
    int h = donut.getHeight();
    
    
    //create random points
    for(int i=0; i<400; i++){
        points.push_back(ofPoint(ofRandomWidth(), ofRandomHeight()));
        speeds.push_back(2);
        angles.push_back(0);
    }
    
}

//--------------------------------------------------------------
void testApp::update(){
    //cohesion - move towards an average position
    
    for(int i=0; i<points.size(); i++){
        
        //set initial value of point to (0,0)
        ofPoint  neighborAverage = ofPoint (0,0);
        
        //the total number of neighbors within the proximity
        int neighborCount = 0;
        
        for(int j=0; j<points.size(); j++){
            if(points[i].distance(points[j]) <= 150){
                neighborAverage += points[j];
                neighborCount++;
            }
        }
        
        //find average of the neighbors
        neighborAverage /= neighborCount;
        
        //move towards the average neighbor point
        points[i].interpolate(neighborAverage, 0.01);
    }
    
    
    
    //move towards the
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(255, 0, 255);
    
    
    
    
    for(int i=0; i<angles.size(); i++){
        int w = donut.getWidth();
        int h = donut.getHeight();
        
        //set random color for each point
        ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
        
        //create a circle for each point with a radius of 4
        //ofCircle(points[i], 4);
        OF_RECTMODE_CENTER;
        donut.draw(ofPoint(points[i].x-w/2, points[i].y-h/2));
        
        //ofLine(points[i], points[i] + ofPoint(10,0));
        
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
