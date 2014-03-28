#pragma once

#include "ofMain.h"

//#include <stdio.h> //SWITCH BACK ON FOR PI
//#include <wiringPi.h> //SWITCH BACK ON FOR PI
//#include "ledHashTable.h" //hash table

class testApp : public ofBaseApp{

	public:

		void setup();
		//void select_row();
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

		ofVideoGrabber 		vidGrabber;
		unsigned char * 	videoInverted;
		ofTexture			videoTexture;
		int 				camWidth;
		int 				camHeight;
		int                 xPos;
		int                 yPos;
		int                 whiteX;
		int                 whiteY;
		int                 dotColor;
		int                 cols;
		int                 rows;
		int                 videoScale;

        unsigned char                 pixelsB[512];

		ofTrueTypeFont myfont;


		ofTexture           horizontalFlipTexture;
        ofTexture           verticalFlipTexture;
        unsigned char *     horizontalFlip;
        unsigned char *     verticalFlip;
};
