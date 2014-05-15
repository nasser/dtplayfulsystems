#pragma once

#include "ofMain.h"
#include "oF_Make_Shapes.h"

#define NBALLS 10 



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

    ofVideoPlayer myPlayer;
    
    bool flip = false;
    
    int x = 10;
    
    int y = 10;
    
    void drawCircles(float x1, float y1, float radius);
    
    
    oF_Make_Shapes makeShape[NBALLS];
    
    //oF_Make_Shapes makeShape;

    ofImage flower;

    

private:
   // ofBall *myBall;
    
		
};

