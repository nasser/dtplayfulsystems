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
    
    //-----------------video-----------------------
    ofVideoPlayer myPlayer;
    
    //-----------------sound-----------------------
    void audioIn(float * input, int bufferSize, int nChannels);
    vector <float> left;
    vector <float> right;
    vector <float> volHistory;
    int bufferCounter;
    int drawCounter;
    float smoothedVol;
    float scaledVol;
    ofSoundStream soundStream;
    
    //-----------------sphere parameters----------------------
    float radius; //radius of sphere
    ofMesh meshTop; //top half of sphere
    ofMesh meshT; //pass this mesh
    ofMesh meshSphereTop (ofImage imageA, ofMesh meshTop, vector<ofColor> colors, float radius, ofPoint sound);
//    
//    //-----------------interpolate----------------------
    ofPoint interp (ofPoint p1, ofPoint p2, float t);
    ofPoint p1, p2, p3, p4;
    ofPoint sound;
    float range;
//    
    //-----------------image parameters----------------------
    ofImage image;
    vector<ofColor>colors;
    
    
    //-----------------3d----------------------
    ofEasyCam easyCam;  //add a camera
    
    //void drawMeebs
    
};