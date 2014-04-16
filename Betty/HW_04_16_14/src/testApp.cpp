#include "testApp.h"

///I COULDNT FIGURE IT OUT SORRY :(((((

//--------------------------------------------------------------
void testApp::setup(){
    target = ofPoint(ofGetWidth()/2, ofGetHeight()/2);
    
    for(int i = 0; i < 200; i++){
        points.push_back(ofPoint(ofRandomWidth(), ofRandomHeight()));
        angles.push_back(0);
        speeds.push_back(2);
    }
}

//--------------------------------------------------------------
void testApp::update(){
    
    //avoidance, alignment and coherance
    
        target.x = mouseX;
        target.y = mouseY;
    
    manualTarget.x = mouseX;
    manualTarget.y = mouseY;
    
    
    //    //cohesion move towards average position
    //    for(int i = 0; i<points.size(); i++){
    //        ofPoint neighborAverage = ofPoint(0, 0);
    //        int neighborCount = 0;
    //
    //
    //        //find neighbors
    //        for(int j = 0; j < points.size(); j++){
    //            if(points[i].distance(points[j]) <= 300){
    //                //we know that points[j] is a neighbor
    //
    //                neighborAverage += points[j];
    //                neighborCount++;
    //            }
    //        }
    //        // calculate neighbor average point
    //        neighborAverage /= neighborCount;
    //        // move towards neighbor average point
    //        points[i].interpolate(neighborAverage,  0.01);
    //    }
    
    
    //    ofPoint flockAverage = ofPoint(0, 0);
    //    for(int i = 0; i<points.size();i++){
    //        flockAverage += points[i];
    //    }
    //    flockAverage = flockAverage / points.size();
    //
    //    //move towards manualTarget
    //    for(int i = 0; i<points.size(); i++){
    //        points[i].interpolate(flockAverage, 0.01);
    //    }
    
    ////    if(((int)ofGetElapsedTimef()) % 5 == 0){
    //    for(int i = 0; i<points.size();i++){
    //        //set points at random positions
    ////        points[i].x = ofRandomWidth();
    ////        points[i].y = ofRandomHeight();
    //
    //        //move towards target
    //        points[i].interpolate(target, 0.005);
    ////    }
    //    }
    
    //here we're working with direction
    
    //steer
    for (int i = 0; i <angles.size(); i++){
        //angles[i] += ofRandomf();
        angles[i] += ofSignedNoise(ofGetElapsedTimef(), i) * 0.1;
                
    }
    

    // speed up/slow down
    for (int i = 0; i<speeds.size(); i++){
        speeds[i] += ofSignedNoise(ofGetElapsedTimef(), i) * 0.1;
    }
    
    //move
    for (int i = 0; i <points.size(); i++){
        points[i].x += cos(angles[i])*2;
        points[i].y += sin(angles[i])*2;
        
        ofPoint neighborAverage = ofPoint(0, 0);

        int neighborCount = 0;
        
        //
        //        //find neighbors
        for(int j = 0; j < points.size(); j++){
            
            if(points[i].distance(points[j]) <= 50 && points[i].distance(points[j]) > 0){
                //                //we know that points[j] is a neighbor

                neighborAverage += points[j];
                neighborCount++;
            }
            if(points[i].distance(points[j]) <= 30 && points[i].distance(points[j]) > 0){
                //                //we know that points[j] is a neighbor
                
                //change angle away from neighbor aka repel
                angles[i] += ofSignedNoise(ofGetElapsedTimef(), i) * -0.1;
                                points[j].x += ofRandom(-0.1, 0.1);
                               points[j].y += ofRandom(-0.1, 0.1);
            }
            
        }
        //        // calculate neighbor average point
        neighborAverage /= neighborCount;
        //        // move towards neighbor average point
        points[i].interpolate(neighborAverage,  0.01);

           }
    
    //cohesion = move towards center of all nearby boids
//    for(int i = 0; i<points.size(); i++){
//        
//        ofPoint sum = ofPoint(0, 0);
//        int count = 0;
//        for(int j = 0; j < points.size(); j++){
//            if(points[i].distance(points[j]) <50){
//                points[j].x += 1;
//                points[j].y += 1;
//                count++;
//            }
//        }
//        sum /= count;
//    }
    
    ofPoint acceleration = ofPoint(0, 0);
    
}


//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackground(0,0,0);
    ofSetColor(255, 255, 255);
    ofBeginShape();
    for(int i = 0; i<angles.size(); i++){
        //       ofVertex(points[i]);
        
        ofCircle(points[i], 2);
        ofLine(points[i], points[i] + ofPoint(cos(angles[i])*10, sin(angles[i])*10));
    }
    ofEndShape();
    
    //    ofSetColor(255, 0, 0);
    //    ofCircle(target, 10);
    
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
    
    points.push_back(ofPoint(ofRandomWidth(), ofRandomHeight()));
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
