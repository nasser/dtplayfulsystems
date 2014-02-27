#pragma once

#include "ofMain.h"
#define NUM_SIDES 5

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
		

    //POSITIONS
    //Arrays to store position values
    float xPos[NUM_SIDES];
    float yPos[NUM_SIDES];
    
    //Angle
    float angle;
    float angle_inc;
    float myRotation;
    

    //SHAPE FUNCTIONS
    void myShape01(float x1, float y1, float sz, float myColor);
    void heart(float x2, float y2, float scale, float color);
    

};
