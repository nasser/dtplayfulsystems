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
    
    ofTrueTypeFont myfont;
		
    int rectSize = 500;
    int factor = 5;
    int factor2 = 10;
    
    int leftPointX = ofGetWidth()/2 - rectSize / 2;
    int leftPointY = ofGetHeight()/2 - rectSize / 2;
    int topPointX = ofGetWidth()/2 + rectSize / 2;
    int topPointY = ofGetHeight()/2 - rectSize / 2;
    int rightPointX = ofGetWidth()/2 + rectSize / 2;
    int rightPointY = ofGetHeight()/2 + rectSize / 2;
    int bottomPointX = ofGetWidth()/2 - rectSize / 2;
    int bottomPointY = ofGetHeight()/2 + rectSize / 2;
    
    int leftPointX2 = ofGetWidth()/2 - rectSize / 4;
    int leftPointY2 = ofGetHeight()/2 - rectSize / 4;
    int topPointX2 = ofGetWidth()/2 + rectSize / 4;
    int topPointY2 = ofGetHeight()/2 - rectSize / 4;
    int rightPointX2 = ofGetWidth()/2 + rectSize / 4;
    int rightPointY2 = ofGetHeight()/2 + rectSize / 4;
    int bottomPointX2 = ofGetWidth()/2 - rectSize / 4;
    int bottomPointY2 = ofGetHeight()/2 + rectSize / 4;
};
