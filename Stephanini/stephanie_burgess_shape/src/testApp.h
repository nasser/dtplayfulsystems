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
    void flower(float x, float y, float x1);
    void flower2(float y, float x, float y1);
    int x;
    int y;
    int x1;
    int y1;
    int y2;
    int x2;
    int y3;
    int y4;
    int y5;
    
    void thisFunction(float xPos, float yPos, float size);
    
    
};
