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
    
    void drawMenu();
    void drawVideo();
    void jitter(int cutChance);
    void fraction(float fraction, int cutChance);

    bool menuDisplay;
    bool fullscreen;
    
    string playbackMode[7];
    
    int currentMode;
    int playbackModeLength;
    
    int mode;
    int act;
    int wiggle;
    
    ofImage menuImg;
    ofTrueTypeFont CousineRegular;
    
    ofVideoPlayer video;
    ofSoundPlayer sound;
		
};
