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
    
    ofPoint pointOnLine(ofPoint from, ofPoint to, float t); 
	//^return type ^name ^variable declarations
    
    
    //the names of things are less important than the types in c++; the types are the edges of your code in c++
    
    
    float ourCircle(ofPoint p, float r);
    
    void drawPointOnLine(ofPoint p1, ofPoint p2, float t);
};
