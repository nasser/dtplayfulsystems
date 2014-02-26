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

      //  void drawPeace(ofPoint, float x1, float y1, float x2, float y2);

        ofPoint danceStar(ofPoint center, float angle, float length);

       float x = ofGetWidth()/2;
       float y = ofGetHeight()/2;
       float length = 200;
       float angle = 90;


//void danceStar(float xpos, float ypos, float radius, int npts);
};
