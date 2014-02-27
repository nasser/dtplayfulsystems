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
    float x=0;
    float y=0;
    ofColor theColor;
    int test1;
    int test2;
    int lnx;
    int lny;
    int count;
    int lnx1;
    int count2;
    int count3;
    int test3;
    int lyn2;
    int lnx3;
    int lnx33;
    int test0;
    int ln;
    int state;
};
