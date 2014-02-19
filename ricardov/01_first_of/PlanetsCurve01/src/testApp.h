#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    void drawSinWaveWithRects(float angleBase, int amplitude, int rectWidth, int rectHeight);
    void drawPlanets(float posX, float posY, float separation, float velocity, float myColor);

    
    float angle;
    float myX;
    
    float myAngle;
    float myAngleAdder;
    
    ofTrueTypeFont myfont; // 1- here crate the objet whete to load the font
    
};
