#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "Clone.h"
#include "ofxFaceTracker.h"
#include "ofxFaceTrackerThreaded.h"

class testApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
	void dragEvent(ofDragInfo dragInfo);
	void loadFace(string face);

	void keyPressed(int key);

	void recordImageFrames();
	int frameSelect;

	void drawStatic();
	int pixelSize;

	ofxFaceTrackerThreaded camTracker;
	ofVideoGrabber cam;

	ofxFaceTracker srcTracker;
	ofImage src;
	vector<ofVec2f> srcPoints;

	bool cloneReady;
	Clone clone;
	ofFbo srcFbo, maskFbo;

	ofDirectory faces;
	int currentFace;
	bool capBool;
};
