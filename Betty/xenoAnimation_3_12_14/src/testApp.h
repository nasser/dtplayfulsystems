#pragma once

#include "ofMain.h"
#include "bezierCurve.h"

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
		
    
    ofPoint circleCenter;
    ofPoint destination;
    ofImage fish;
    
    //bezier points
    
    ofPoint      startPoint, cP1, cP2, endPoint;
    
    int mousePosX, mousePosY, userX, userY;
    
    int randomColor = 0;
    
    ofPoint pointOnLine(float t, ofPoint p1, ofPoint p2, ofPoint p3, ofPoint p4);
    
    
    ofPoint from, to, from1, to1, from2, to2, circleCenter2, circleCenter3, circleCenter4, circleCenter5;

};
