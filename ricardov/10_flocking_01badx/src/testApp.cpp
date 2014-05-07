#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0, 0, 0);
    manualTarget = ofPoint(ofGetWidth()/2, ofGetHeight()/2);
    
    
    //1- populate values
    for (int i=0; i<100; i++) {
        //point[i] will not work
//        points.push_back(		ofPoint(ofGetWidth()/2, ofGetHeight()/2) 	);
                points.push_back(		ofPoint(ofRandomWidth(), ofRandomHeight()) 	);
    }
    
    
    
}

//--------------------------------------------------------------
void testApp::update(){
    manualTarget.x = mouseX;
    manualTarget.y = mouseY;
    
    
    //2-
//    if(    (int)ofGetElapsedTimef() % 10 == 0  ){
//        for (int i=0; i<points.size(); i++) {
//            points[i].x = ofRandom( ofGetWidth()/2  );
//            points[i].y = ofRandom( ofGetHeight()/2  );

                //move towards target 
  //              points[i].interpolate(manualTarget, 0.01);
//        }
//    }
    


    
    //cohesion - move towards acerage posirtion
    //ofPoint flockAverage = ofPoint(500,0);
   
    ofPoint flockAverage = ofPoint(manualTarget.x, manualTarget.y);
   
    
    for (int i=0; i<points.size(); i++) {
        //this methods calculate all points ,so is not very good
        //find neigbors
        for (int j=0; j<points.size(); j++) {
            if( points[i].distance(points[j]) <= 5 ) {
                //we know points[j] is a neighbor
                points[j];
            }
            
        }
        //ca;lculate neigbor average point
        //move towards
        points[i].interpolate(flockAverage, 0.01);
    }
    
    //calculate average point of the flock
    for (int i=0; i<points.size(); i++) {
        flockAverage += points[i];
    }
//    flockAverage = flockAverage/ points.size();
    
//    for (int i=0; i<points.size(); i++) {
//        points[i].interpolate(flockAverage, 0.01);
//    }


    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0, 0, 0);
    
    //3-
     ofBeginShape();
    for(int i=0;  i<points.size(); i++){
        
 //       ofVertex(points[i]);
         ofCircle(points[i], 5);// one on top of another
    }
    ofEndShape();
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

    manualTarget = ofPoint( mouseX, mouseY );

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
