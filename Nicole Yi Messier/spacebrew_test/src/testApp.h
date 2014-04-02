#pragma once

#include "ofMain.h"

#include "ofxSpacebrew.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	
	ofVideoPlayer myPlayer;
    
    // create your spacebrew object
    Spacebrew::Connection spacebrew;
    
    // listen to spacebrew Messages
    void onMessage( Spacebrew::Message & m );
    
    int sliderXValue;
    
    //create image objects
    ofImage imageOne;
    ofImage imageTwo;
    
    //create a mesh to pass to object
    ofMesh meshPassOne;
    ofMesh meshPassTwo;
    
    
    //add a camera
    ofEasyCam easyCam;
    
    //variables to allow to toggle oribal on & off
    ofMesh meshCopy;
    bool orbiting;
    float startOrbitTime;
    
    //variables to store the polar coordinates of each vertex
    vector<float> distances;
    vector<float> angles;
    ofVec3f meshCentroid;
    
    ofMesh pixelManipulate(ofImage imageA, ofMesh meshA, float intensityThreshold, ofPoint sketchDepth);
    ofPoint pointOnLine(ofPoint p1, ofPoint p2, float t);


};
