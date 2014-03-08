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
		
      
        void drawTwoLines(float spacing, float x1, float y1, float x2, float y2);
       // void drawAngledLine(float x, float y, float angle, float length);
    
    //void drawAngledLine(ofPoint center, float angle, float length);
    ofPoint drawAngledLine(ofPoint center, float angle, float length);

    ofRectangle clickBox;
    
    void drawStar(float xpos, float ypos, float radius, int npts); 
 
};
