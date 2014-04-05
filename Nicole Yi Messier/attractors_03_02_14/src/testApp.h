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
	
	//a list of objects
    //c++
    //without the *, it will be a list of point objects (IE THIS IS NOT A POINTER)
    //with the *, it is a list of references to objects (IE THIS IS A POINTER)
    //std::vector<ofPoint*> points;
    
    vector<ofPoint> points;
    
    
};
