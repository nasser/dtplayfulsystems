#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    //manualTarget = ofPoint(ofGetWidth()/2, ofGetHeight()/2);
    
    for(int i=0; i<200; i++){
        //points.push_back(ofPoint(ofGetWidth()/2, ofGetHeight()/2));
        points.push_back(ofPoint(ofRandomWidth(), ofRandomHeight()));
        angles.push_back(0);
        speeds.push_back(2);
    }
}

//--------------------------------------------------------------
void testApp::update(){
    
    //if you need something every five seconds
    //23 % 5 = 3
    //n % 5 = 0
    //THEN n/5 = whole number
    cout << ((int)ofGetElapsedTimef()) % 5 << endl;
    cout << ((int)ofGetElapsedTimef() % 5 == 0) << endl;
    
    manualTarget.x = mouseX;
    manualTarget.y = mouseY;
    
    

    //cohesion - move towards average position
    
    /*
    for (int i=0; i<points.size(); i++){
        
        ofPoint neighborAverage = ofPoint(0,0); //average of the negihbors
        int neighborCount = 0;
        
        //find neighbors
        for(int j=0; j<points.size(); j++ ){
            if(points[i].distance(points[j]) <= 300){
            //if(points[i].distance(points[j]) > 100){ //distance is slow b/c of the squareroot in distance formula
                //we know points[j] is a neighbor
                neighborAverage += points[j];
                neighborCount++;
                
            }

        }
        
        // calculate neighbors average point
        neighborAverage /= neighborCount;
        
        
        //move towards neighbors average point
        points[i].interpolate(neighborAverage, 0.01);
    }
    
    
    
    for (int i=0; i<points.size(); i++){
        flockAverage += points[i];
    }
    
    flockAverage /= points.size();
    
    for(int i=0; i<points.size(); i++){
        //move towards target (boids)
        points[i].interpolate(flockAverage, 0.05); //.interpolate(point, float between 0 and 1)
    }
    
    
    for(int i=0; i<points.size()/2; i++){ //change "points.size()" to change how many points
        
            //this is a side effect
            points[i].x = ofRandomWidth();
            points[i].y = ofRandomHeight();
        
        //move towards target (boids)
        //points[i].interpolate(target, 0.05); //.interpolate(point, float between 0 and 1)
        
    }
     
     */
    
    
    
    //--------steer---------------
    
    for(int i=0; i<angles.size(); i++){
        
        
        //angles[i] += ofRandomf();
        //angles[i] += ofSignedNoise(ofGetElapsedTimef());
       // angles[i] += ofSignedNoise(ofGetElapsedTimef(), i)*0.1; //ofSignedNoise you get a number btwn -1 and 1
        //speeds[i] += ofSignedNoise(ofGetElapsedTimef(), i)*0.1;
    }
     
    
    //------------move---------------
    for(int i=0; i<points.size(); i++){
       points[i].x += cos(angles[i])*speeds[i];
       points[i].y += sin(angles[i])*speeds[i];
    
        //points[i] += cos(angles[i])*speeds[i];
        //points[i].y += sin(angles[i])*speeds[i];
    
    }
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackground(0, 0, 0);
    ofSetColor(255, 255, 255);
    
    //ofNoFill();
    
    //ofBeginShape(); // begin and end shape allow you draw arbitrary shapes
    
    for(int i=0; i<angles.size(); i++){
        //ofVertex(points[i]);
        ofCircle(points[i], 2);
        ofLine(points[i], points[i] + ofPoint(10, 0));
        //ofLine(points[i], points[i] + ofPoint(cos(angles[i])*10, sin(angles[i])*10));
    }
               
        //ofEndShape();
    
    ofSetColor(255, 0, 0);
    ofCircle(manualTarget, 10);
    
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
    /*
    for(int i=0; i<300; i++){
    points.push_back(ofPoint(ofRandomWidth(), ofRandomHeight()));
    }
    */
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
