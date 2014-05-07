#include "testApp.h"

//BASED ON
//RAMSEY NASSER FLOCKING EXAMPLE
//AND
//JEFF CROUSE FONT EXAMPLE




//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);
    ofSetBackgroundAuto(true);
    ofBackground(0, 0, 0);
    float colorStart = 10.0;
    
    manualTarget = ofPoint(ofGetWidth()/2, ofGetHeight()/2);
    
    for (int i=0; i<NUM_ELEMENTS; i++) {
        points.push_back(ofPoint(ofRandomWidth(), ofRandomHeight()));
        angles.push_back(0);
        speeds.push_back(0);
        //R
        sizes.push_back(0);//intitialize circle sizes
        colors.push_back(colorStart);
    }
    
    //R
    wMedio = ofGetWidth()/2;
    hMedio = ofGetHeight()/2;
    
    amount = 0.2;
    text = "A";

    // Load the font
    string filename = "Verdana.ttf";
    int fontSize = 260;
    bool bAntiAliased = true;
    bool bFullCharacterSet = true;
    bool makeContours = true;
    float simplifyAmt = 0.3; // uses ofPolyline::simplify
    font1.loadFont(filename, fontSize, bAntiAliased, bFullCharacterSet, makeContours, simplifyAmt);
    
    
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
    
//    /*
     // move towards manualTarget
     for (int i=0; i<points.size(); i++) {
     points[i].interpolate(manualTarget, 0.01);
     }
  //   */
    
    // steer randomly
 //   /*
     for (int i=0; i<angles.size(); i++) {
     angles[i] += ofSignedNoise(ofGetElapsedTimef(), i) * 0.1;
     }
    // */
    
    // speed up/slow down randomly
 //   /*
     for (int i=0; i<speeds.size(); i++) {
     speeds[i] += ofSignedNoise(ofGetElapsedTimef(), i) * 0.1;
     }
  //   */
    
    // move
    for (int i=0; i<points.size(); i++) {
        points[i].x += cos(angles[i])*speeds[i];
        points[i].y += sin(angles[i])*speeds[i];
        sizes[i] = 1;

/*
 //test typo pint pos and change size
        float myDist = ofDist(points[i].x, points[i].y, myTypoPointsX, myTypoPointsY);
        
        //R - check distance bt flock and typopoints, then changesomething
        if(myDist < 50 || myDist < -50){
            sizes[i] = 10;
            
        }else{
            sizes[i] = 1;
        }

*/        
//ramsey code
//        if(font1.getStringAsPoints(text)[0].getOutline()[0].inside(points[i].x, points[i].y)) {
        
//        if(font1.getStringAsPoints(text)[0].getOutline()[0].inside(points[i].x, points[i].y)    ) {
//            sizes[i] = 200;
//        } else {
//            sizes[i] = 2;
//        }
////*/
    }

    
}

//--------------------------------------------------------------
void testApp::draw(){
//R    ofBackground(0, 0, 0);
    ofPushMatrix();
    ofSetColor(0, 0, 0, 10);
        ofRect(0, 0, ofGetWidth(), ofGetHeight());
    ofPopMatrix();
    
    
    //R FONT
    //Size of typo rects boundaries
    ofRectangle rect = font1.getStringBoundingBox(text, 0,0);
    float typoPosX = rect.width/2;
    float typoPosY = rect.height/2;
    
    
    ofPushMatrix();
//RN - FLOCK
    ofSetColor(155, 100, 20);
    for (int i=0; i<points.size(); i++) {
        ofCircle(points[i], sizes[i]);
    }
    
    

    
// / / / / / / / / /
    int nVerts = 0;
    
        //    {
//        ofTranslate(    ofGetWidth()/2.0, ofGetHeight()/2.0 );
        
        // Create a bunch of Letter objects
        vector<ofPath> letterPaths = font1.getStringAsPoints(text);
        for(int i=0; i<letterPaths.size(); i++) {
            
            vector<ofPolyline> lines = letterPaths[i].getOutline();
            for(int j=0; j<lines.size(); j++) {
                ofPolyline line = lines[j];
                line.simplify();
                
                ofBeginShape();
                for(int k=0; k<line.size(); k++)
                {
                    //R
                    myTypoPointsX = line[k].x  - typoPosX + wMedio;
                    myTypoPointsY = line[k].y  + typoPosY + hMedio;

                    //LINES font1
                    ofSetColor(180, 50);
                    //ofVertex(line[k].x  - typoPosX, line[k].y  + typoPosY );
                    ofVertex( myTypoPointsX, myTypoPointsY );
                    
                    
                    //POINTS FONT
                    ofFill();
                    ofCircle( myTypoPointsX, myTypoPointsY, 3);

                    
//                    if( font1.getStringAsPoints(text)[0].getOutline()[0].inside(points[i].x, points[i].y)    ) {
                    if( font1.getStringAsPoints(text)[0].getOutline()[0].inside( points[i])    ) {
                            sizes[i] = 2;
                        }   else {
                            sizes[i] = 20;
                        }
                    

                    
                    
                    nVerts++;

                }
                ofEndShape(true);
            }
        }
        //}
    
    ofPopMatrix();
// / / / / / / / / /

    
    
    
    
    
    
    
    
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    ofBackground(0, 0, 0);
    text = key;
        
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