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
		
    float x1 = 0;
    float x2 = 0;
    float y1 = 0;
    float y2 = 0;
    
    float x3 = 0;
    float x4 = 0;
    float y3 = 0;
    float y4 = 0;
    
    float x5 = 0;
    float x6 = 0;
    float y5 = 0;
    float y6 = 0;
    float step = 0;
    
    float x7 = 0;
    float x8 = 0;
    float y7 = 0;
    float y8 = 0;
};
