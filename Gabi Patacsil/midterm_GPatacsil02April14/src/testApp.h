#pragma once

#include "ofMain.h"
#include "ofEvents.h"

//struct Key {
//    ofPoint pos;
//
//    float radius;
//    float volume;
//    ofSoundPlayer sound;
//    
//
//};

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
    
	ofImage				bgImage;
	ofTrueTypeFont		font;
    ofTrueTypeFont      smallFont;
	ofArduino	ard;
	bool		bSetupArduino;			// flag variable for setting up arduino once
    bool                frameByframe;

    //vector<Key>  keys;
    
    ofSoundPlayer keyA;
    ofSoundPlayer keyB;
    ofSoundPlayer keyC;
    ofSoundPlayer keyD;
    ofSoundPlayer keyE;
    ofSoundPlayer keyF;
    
    ofPoint pointOnLine(float t, ofPoint p1, ofPoint p2);
    void burst(float size, int key);

    
    
    
    
    
    bool ardOn;
    
    
private:
    
    void setupArduino(const int & version);
    void digitalPinChanged(const int & pinNum);
    void analogPinChanged(const int & pinNum);
	void updateArduino();
    string buttonState;
    string potValue;

    
};

