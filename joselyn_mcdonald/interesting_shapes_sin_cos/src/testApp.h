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
    
       ofPoint pointOnLine(float t, ofPoint p1, ofPoint p2);

      float doubleCubicSeat(float x, float a, float b);


     void ofCurve(float x0, float y0, float x1, float y1, float x2, float y2, float x3, float y3); 
};
