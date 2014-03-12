#pragma once

#include "ofMain.h"

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
    void starflake(float x, float y, float size, float angle, float red);
    ofPoint twoPointsOnLine(ofPoint p1, ofPoint p2, ofPoint p3, ofPoint p4, float t);
    ofPoint pointOnLine(float t, ofPoint p1, ofPoint p2);

};
