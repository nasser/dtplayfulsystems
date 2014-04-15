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
    
    void drawPointOnLine(ofPoint p1, ofPoint p2, float t);

    
    float beginX = 20.0;  // Initial x-coordinate
    float beginY = 10.0;  // Initial y-coordinate
    float endX = 570.0;   // Final x-coordinate
    float endY = 320.0;   // Final y-coordinate
    float distX;          // X-axis distance to move
    float distY;          // Y-axis distance to move
    float exponent = 4;   // Determines the curve
    float x = 0.0;        // Current x-coordinate
    float y = 0.0;        // Current y-coordinate
    float step = 0.01;    // Size of each step along the path
    float pct = 0.0;      // Percentage traveled (0.0 to 1.0)

    void drawFboTest();
    void drawFish();
    
    //32 bits red, 32 bits green, 32 bits blue, from 0 to 1 in 'infinite' steps
    ofFbo rgbaFboFloat; // with alpha
    
    int fadeAmnt = 5;
    
    ofPoint pointOnLine(float t, ofPoint p1, ofPoint p2, ofPoint p3, ofPoint p4);
    
    int userX, userY;
    
    ofImage fish;

};
