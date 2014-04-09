/*
 * Created by Betty Quinn
 * DT Playful Systems
 * HW 4/9/14
 *
 * NOTE: This project requires a webcam or kinect connceted to openTSPS to run
 * Real time playback example can be found here: https://vimeo.com/91510974
 */

#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    

	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	ofBackground(0, 0, 0, 0); //sets the background color
    tspsReceiver.connect(12000);
   ofEnableAlphaBlending();
   // ofEnableBlendMode(OF_BLENDMODE_ADD);
        
    
    void onPersonEntered( ofxTSPS::EventArgs & tspsEvent );
    void onPersonUpdated( ofxTSPS::EventArgs & tspsEvent );
    void onPersonWillLeave( ofxTSPS::EventArgs & tspsEvent );
    
    ofxAddTSPSListeners(this);
}

//--------------------------------------------------------------
void testApp::update(){
    //here, you can loop through each person and do stuff
    vector<ofxTSPS::Person*> people = tspsReceiver.getPeople();
    for (int i= 0; i<people.size(); i++){
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(0, 200, 255, 255);

    attractorDance();
    
    //debug the TSPS draw
    //tspsReceiver.draw(ofGetWidth(), ofGetHeight());
}


//draw the model manually
void testApp::attractorDance(){
    vector<ofxTSPS::Person*> people = tspsReceiver.getPeople();
    
    for (int i=0; i<people.size(); i++){
        ofPoint centroid = people[i]->centroid;
        centroid.x *= ofGetWidth();
        centroid.y *= ofGetHeight();
        
        float dancerWidth = people[0]->boundingRect.width*ofGetWidth();
        float dancerHeight = people[0]->boundingRect.width*ofGetWidth();
    
    
    int n = 150000;
    
    float a = 1; //how much it turns
    float b = -1.3; //number of waves vertically
    float c = 2.1+ cos(ofGetElapsedTimef())*1.5; //number of waves horizontally
    float d = -2.1; //number of waves horizontally + how much it turns?
    
    float x0, y0, x1, y1 = 0;
    x0 = y0 = x1 = y1 = 0;
    
   // ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        ofTranslate(centroid.x, centroid.y);

    ofScale(dancerWidth/4, dancerHeight/2, 100); //width, height, depth
    
    for (int i=0; i<n; i++) {
        x1 = sin(a * y0) - cos(b * x0);
        y1 = sin(c * x0) - cos(d * y0);
        
        ofColor(255, 0, 0);
        ofLine(x1, y1, x1+0.001, y1);
        
        x0 = x1;
        y0 = y1;
    }
    }
}
//--------------------------------------------------------------
void testApp::onPersonEntered(ofxTSPS::EventArgs & tspsEvent){
    ofLog(OF_LOG_NOTICE, "New person!");
}

//--------------------------------------------------------------
void testApp::onPersonUpdated(ofxTSPS::EventArgs & tspsEvent){
    ofLog(OF_LOG_NOTICE, "Person updated!");
}

//--------------------------------------------------------------
void testApp::onPersonWillLeave(ofxTSPS::EventArgs & tspsEvent){
    ofLog(OF_LOG_NOTICE, "Person left!");
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
