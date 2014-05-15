#include "testApp.h"

//BASED ON
//RAMSEY NASSER FLOCKING EXAMPLE
//AND
//JEFF CROUSE FONT EXAMPLE


void testApp::myShape1(int _x, int _y, int _rot) {
    //HEART
    ofPushMatrix();
        ofSetColor(250, 0, 0, 10);

        ofTranslate(_x, _y);
        ofRotate(_rot);
        ofBeginShape();
            ofVertex(0, 20);
            ofBezierVertex(0, -35, 80, 10, 0, 60);
            ofVertex(0, 20);
            ofBezierVertex(0, -35, -80, 10, 0, 60);
        ofEndShape();
    ofPopMatrix();
}



//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);
    ofSetBackgroundAuto(false);//false to allow redraw of shapes
    ofBackground(255, 255, 255);
    colorStart = 10.0;
    
    manualTarget = ofPoint(ofGetWidth()/2, ofGetHeight()/2);
    
    for (int i=0; i<NUM_ELEMENTS; i++) {
        points.push_back(ofPoint(ofRandomWidth(), ofRandomHeight()));
        angles.push_back(0);
        speeds.push_back(0);
        //R
        sizes.push_back( 0 );//intitialize circle sizes
        colors.push_back(colorStart);
    }
    
    //R
    displaceToTop = 250;
    wMiddle = ofGetWidth()/2;
    hMiddle = ofGetHeight()/2-displaceToTop;
    amount = 0.2;
    

    // Load the font
    string filename = "Verdana.ttf";
    int fontSize = 50;
    bool bAntiAliased = true;
    bool bFullCharacterSet = true;
    bool makeContours = true;
    float simplifyAmt = 0.3; // uses ofPolyline::simplify
    font1.loadFont(filename, fontSize, bAntiAliased, bFullCharacterSet, makeContours, simplifyAmt);
    
    
    //R - SVG
    rX = ofRandomWidth();
    rY = ofRandomHeight();
    
    
    for(int i=0; i<NUM_FILES; i++)
    {
        string fileNum = ofToString(i);
        mySvgFiles.push_back(ofxSVG());
        mySvgFiles.back().load("svg/form_"+fileNum+".svg");

        mySvgPoints.push_back(  ofPoint(wMiddle,hMiddle) );
        mySvgRotation.push_back( 0 );
        mySvgScale.push_back( 1.0 );

    }
    
    //R POEM
    text = "The \nImaginary \nMan";
    ofBuffer file = ofBufferFromFile("poem1.txt");
    poemAsString = file;

    
    //R SAVE IMG
	snapCounter = 0;
	bSnapshot = false;
	memset(snapString, 0, 255);		// clear the string by setting all chars to 0
}

//--------------------------------------------------------------
void testApp::update(){
        
    manualTarget.x = mouseX;
    manualTarget.y = mouseY;

//    manualTarget.x = wMedio;
//    manualTarget.y = hMedio;

    
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
    
    
    
    // steer randomly
     for (int i=0; i<angles.size(); i++) {
     angles[i] += ofSignedNoise(ofGetElapsedTimef(), i) * 0.1;
     }
    
    
    
    // speed up/slow down randomly
     for (int i=0; i<speeds.size(); i++) {
     speeds[i] += ofSignedNoise(ofGetElapsedTimef(), i) * 0.9;
     }

    
    
    // move
    for (int i=0; i<points.size(); i++) {
        points[i].x += cos(angles[i])*speeds[i];
        points[i].y += sin(angles[i])*speeds[i];
        sizes[i] = 10;
    }
    
    
    //test typo pint pos and change size
        
/*
    float myDist = ofDist(points[i].x, points[i].y, myTypoPointsX, myTypoPointsY);
    float myDist = ofDist(points[i].x, points[i].y, manualTarget.x, manualTarget.y);
      
        //R - check distance bt flock and typopoints, then changesomething
        if(myDist < 250 || myDist < -250){
            sizes[i] = 10;
            colors[i] = 255;
        }else{
            sizes[i] = 1;
            colors[i] = 0;
        }
    }
 
//ramsey code
        if(font1.getStringAsPoints(text)[0].getOutline()[0].inside(points[i].x, points[i].y)) {
        
        if(font1.getStringAsPoints(text)[0].getOutline()[0].inside(points[i].x, points[i].y)    ) {
            sizes[i] = 200;
        } else {
            sizes[i] = 2;
        }
*/
    


    
}


//--------------------------------------------------------------
void testApp::draw(){
    //R TO PDF - NOT WORKING VERY WELL
    /*
    if( oneShot ){
		ofBeginSaveScreenAsPDF("screenshotXXXX-"+ofGetTimestampString()+".pdf", false);
	}*/

    
    //R    ofBackground(255, 255, 255);
    ofPushMatrix();
        ofSetColor(255, 255, 255, 2);
        ofRect(0, 0, ofGetWidth(), ofGetHeight());
    ofPopMatrix();
    
    
    //R - SVG
    for(int i=0; i<NUM_FILES; i++) {
        ofPushMatrix();
            ofSetColor(5);
            ofTranslate(mySvgPoints[i].x, mySvgPoints[i].y);
            ofRotate(mySvgRotation[i]);
            ofScale(mySvgScale[i], mySvgScale[i]  );
        mySvgFiles[i].draw();

        ofPopMatrix();
    }
    
    
    //R FONT
    //Size of typo rects boundaries
    ofRectangle rect = font1.getStringBoundingBox(text, 0,0);
    float typoPosX = rect.width/2;
    float typoPosY = rect.height/2;
   
    
    ofPushMatrix();
    //RN - FLOCK
    for (int i=0; i<points.size(); i++) {
        ofPushMatrix();
            ofSetColor(colors[i], 10, 0, 50);
            ofCircle(points[i], 1);
            //myShape1(points[i].x, points[i].y, 100);
            //ofRect(points[i], sizes[i], 100);
            //ofLine(points[i].x, points[i].y, points[i].y, points[i].x);
        ofPopMatrix();
    }
    
    
// / / / / / / / / /
    int nVerts = 0;
        // Create a bunch of Letter objects
        vector<ofPath> letterPaths = font1.getStringAsPoints(text);
        for(int i=0; i<letterPaths.size(); i++) {
            
            vector<ofPolyline> lines = letterPaths[i].getOutline();
            for(int j=0; j<lines.size(); j++) {
                ofPolyline line = lines[j];
                line.simplify();
                
                ofBeginShape();
                for(int k=0; k<line.size(); k++) {
                    //R
                    myTypoPointsX = line[k].x  - typoPosX + wMiddle-100;
                    myTypoPointsY = line[k].y  + typoPosY + hMiddle;

                    
                    //RECT
                    ofSetColor(0);
                    //rect.set(myTypoPointsX-typoPosX, myTypoPointsY-typoPosY, typoPosX, typoPosY);
                    //ofRect(myTypoPointsX-rect.width/2, myTypoPointsY-rect.height/2, rect.width, rect.height);

                    //LINES font1
                    ofSetColor(200);
                    //ofVertex(line[k].x  - typoPosX, line[k].y  + typoPosY );
                    //ofVertex( myTypoPointsX, myTypoPointsY );
                    
                    //POINTS FONT
                    //ofFill();
                    //ofCircle( myTypoPointsX, myTypoPointsY, 3);
                    /*
                    if( font1.getStringAsPoints(text)[0].getOutline()[0].inside(points[i].x, points[i].y)    ) {
                    if( font1.getStringAsPoints(text)[0].getOutline()[0].inside( points[i])    ) {
                            sizes[i] = 2;
                        }   else {
                            sizes[i] = 20;
                        }
                     */
                   //nVerts++;

                }
                ofEndShape(true);
            
            }
        }
    
    ofPopMatrix();
// / / / / / / / / /
    
    
    //POEM TITLE
    ofSetColor(10);
    //THE
    ofRect(wMiddle - typoPosX, hMiddle-60, 135, 75);
    //IMAGINARY
    ofRect(wMiddle - typoPosX, hMiddle+10, 350, 80);
    //MAN
    ofRect(wMiddle - typoPosX, hMiddle+80, 150, 75);
    ofSetColor(0, 200, 200);
    font1.drawString(text, wMiddle - typoPosX, hMiddle);
    
    
    //POEM BOX
    ofDrawBitmapStringHighlight(poemAsString, wMiddle, hMiddle+150, 0, 250);
    

    //R TO PDF - NOT WORKING VERY WELL
    /*
    if( oneShot ){
		ofEndSaveScreenAsPDF();
		oneShot = false;
	}
     */
    
    
    //FOMR OPENFRAMEWORKS EXAMPLE
    if (bSnapshot == true){
		// grab a rectangle at 200,200, width and height of 300,180
		img.grabScreen(0,0,ofGetWidth(),ofGetHeight());
        
		string fileName = "imageSaved_"+ofToString(1000+snapCounter)+".png";
		img.saveImage(fileName);
		sprintf(snapString, "saved %s", fileName.c_str());
		snapCounter++;
		bSnapshot = false;
	}


    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    ofBackground(255, 255, 255);
//    text = key;
//    myRotation = ofRandom(0, TWO_PI);
//    myRotation = angles;


    if( key == ' ' ){

        //R - init pos mySvgPoints
        for (int i=0; i<NUM_FILES; i++) {
            rX = ofRandom(  150, ofGetWidth()-150 );
            rY = ofRandom(  100, ofGetHeight()-250 );

            mySvgPoints[i].x = rX;
            mySvgPoints[i].y = rY;
            mySvgRotation[i] = ofRandom(200);

            if(i>=0 && i<=9){
                mySvgScale[i]    = ofRandom(8.0, 12.0) ;
            }
            if(i>=10 && i<=18){
                mySvgScale[i]    = ofRandom(3.0, 14.0) ;
            }
            if(i>=19 && i<=25){
                mySvgScale[i]    = ofRandom(1.0, 5.5) ;
            }else {
                mySvgScale[i]    = ofRandom(0.3, 4.0) ;
            }

        }
            
        }
    
    //R TO IMg
    if( key == 's' ){
		bSnapshot = true;
	}




    
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