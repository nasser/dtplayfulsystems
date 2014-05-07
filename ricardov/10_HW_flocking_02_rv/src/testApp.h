#pragma once

#include "ofMain.h"

//BASED ON 
//RAMSEY NASSER EXAMPLE

#define NUM_ELEMENTS 200

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
    
    //Declaring vectors vector< type > name
    vector<ofPoint> points;
    vector<float> angles;
    vector<float> speeds;
    vector<float> sizes;
    vector<float> colors;
    
    ofPoint manualTarget;
    
    //R
    float wMedio, hMedio;
    
    string text;
    float amount;
    float sz;
    ofTrueTypeFont	font1;
    
    float myTypoPointsX;
    float myTypoPointsY;
    
    
    
    //TEST
    vector<ofTTFCharacter> characters;
    ofPoint startPos;


    
};
