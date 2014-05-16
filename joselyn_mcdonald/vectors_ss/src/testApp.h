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
    
     // a vector list is a dynamic array! Meaning that the size can change once it gets started 
    
    
        vector<ofPoint> points; //this is a list of point objects
    
    
    //  vector<ofPoint*> points; // this is a list of references to objects
    // the (*) is the pointer
    
    
};
