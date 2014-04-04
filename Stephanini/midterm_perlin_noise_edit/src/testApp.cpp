#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
	ofBackground(255,255,255);
	//ofSetFrameRate(5);
	ofSetVerticalSync(true);
	
	colorScheme.loadImage("IMG_0274.jpg");
}

//--------------------------------------------------------------
void testApp::update(){
    
	cout << ofNoise(x) << endl;
    x += 0.8;
}

//--------------------------------------------------------------
void testApp::draw(){
    
	ofEnableAlphaBlending();
	ofSetColor(25,25,55,100);
    // colorScheme.draw( ofGetWindowRect() );
    //   return;
    
	ofSeedRandom(0); // always pick the same random numbers.
	
	for (int i = 0; i < mouseX*6; i++){
		float x = ofNoise(ofGetElapsedTimef()*0.1, i*0.3)*ofGetWidth();
		float y = ofNoise(ofGetElapsedTimef()*0.1, i*0.3)*ofGetHeight();
		
		ofColor col = getColorForPixel(ofMap(x,0,ofGetWidth(), 0, colorScheme.width),
									   ofMap(y,0,ofGetHeight(), 0, colorScheme.height));
        
		col.a = 10;	// set some alpha.
		ofSetColor(col);
		ofCircle(x,y,ofRandom(4,40));
	}
	
    for (int i = 0; i < mouseX*6; i++){
		float x = ofNoise((i*0.1+x)*100)*ofGetWidth();
		float y = ofNoise(ofGetElapsedTimef()*0.1, i*0.3)*ofGetHeight();
		
		ofColor col = getColorForPixel(ofMap(x,0,ofGetWidth(), 0, colorScheme.width),
									   ofMap(y,0,ofGetHeight(), 0, colorScheme.height));
        
		col.a = 10;	// set some alpha.
		ofSetColor(col);
		ofCircle(x,y,ofRandom(4,40));
	}
    
    for (int i = 0; i < mouseX*6; i++){
		float x =  ofNoise(ofGetElapsedTimef()*0.1, i*0.3)*ofGetHeight();
		float y = ofNoise((i*0.1+x)*100)*ofGetWidth();
        
		
		ofColor col = getColorForPixel(ofMap(x,0,ofGetWidth(), 0, colorScheme.width),
									   ofMap(y,0,ofGetHeight(), 0, colorScheme.height));
        
		col.a = 10;	// set some alpha.
		ofSetColor(col);
		ofCircle(x,y,ofRandom(4,40));
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


ofColor testApp::getColorForPixel(int x, int y){
    
	if (x < 0) x = 0;
	if (y < 0) y = 0;
	if (x >= colorScheme.width) x = colorScheme.width-1;
	if (y >= colorScheme.height) y = colorScheme.height-1;
	
	return colorScheme.getColor(x,y);
}
