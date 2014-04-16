#pragma once

#include "ofMain.h"

class SomeNewClass {
    void someFunction();
    float iReturnAFloat();
};

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
    
        SomeNewClass myObject;
    
        ofPoint myPoint;
    
        ofPoint pointOnLine(ofPoint from, ofPoint to, float t);
        void drawPointOnLine(ofPoint p1, ofPoint p2, float t);
        float ourCircle(ofPoint p, float r);
};
