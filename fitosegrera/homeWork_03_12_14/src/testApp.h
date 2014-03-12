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
    
    ofPoint circleCenter1, circleCenter2, circleCenter3, circleCenter4, from1, to1, from2, to2, from3, to3, from4, to4, from5, to5, from6, to6, from7, to7, from8, to8;
    
    ofPoint pointOnLine(float t, ofPoint p1, ofPoint p2);
    
    //Function that creates the points of the vectors
    ofPoint puntos(ofPoint from1, ofPoint to1, ofPoint from2, ofPoint to2, ofPoint from5, ofPoint to5, ofPoint from6, ofPoint to6);
    
    //Function that draws the lines between the lines of the vectors
    ofPoint fractal(vector<ofPoint> puntos1, vector<ofPoint> puntos2, vector<ofPoint> puntos3, vector<ofPoint> puntos4);
    
    vector<ofPoint> puntos1;
    vector<ofPoint> puntos2;
    vector<ofPoint> puntos3;
    vector<ofPoint> puntos4;
};
