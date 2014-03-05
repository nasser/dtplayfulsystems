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

    float dt = 0.01;
    float sigma = 10;
    float beta = 8.0 / 3.0;
    float rohm = 28;
    int c = 1;
    
	ofPoint current, last;
    
    ofEasyCam cam;
    
    void star(float x, float y, float z, float size);
    
    vector<ofPoint> starpos;
    
};
