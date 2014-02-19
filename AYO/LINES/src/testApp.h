#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    int backr, backg, backb, backa, width,lineInt, height;
    float speed1,alp,lSx,lSy,lEx,lEy,l2Sx,l2Sy,l2Ex,l2Ey,l3Sx,l3Sy,l3Ex,l3Ey,lineW;
    bool s1,s2,s3,s4,space,q;
    	ofTrueTypeFont	verdana14;
};
