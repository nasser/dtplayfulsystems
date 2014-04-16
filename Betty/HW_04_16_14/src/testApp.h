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
    
    void boid(float x, float y);
    
    vector<ofPoint> points;
    vector <float> angles;
    vector <float> speeds;
    
    ofPoint target;
    ofPoint manualTarget;
    
    vector <ofPoint> location;
    vector <ofPoint> velocity;
    vector <ofPoint> acceleration;

    float r;
    float maxforce;    // Maximum steering force
    float maxspeed;    // Maximum speed
};
