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
        
    
  
ofPoint pointOnLine(ofPoint from, ofPoint to, float t);

    
    float halfTime;

    

    
 //Game modes

    int mode;
   
    
//---------------------------------------------------------
// mode1 - menu
    
    float rectanglex;
    float rectangley;
    float rectangleheight;
    float rectanglewidth;

    

//---------------------------------------------------------
//mode2 - game



//Player1

float player1x;
float player1y;
float player1height;


//Player2

float player2x;//=ofGetWidth()-145;
float player2y;
float player2height;

//Ball

float ballx;
float bally;
float radius;
float xspeed;
float yspeed;

    
};


//------------------------------------------------------------

// mode3 - end 