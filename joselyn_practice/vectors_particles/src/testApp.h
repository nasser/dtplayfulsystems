#pragma once

#include "ofMain.h"

// create the particle class in the header for brevity

class Particle{
public:
    Particle(){
        pos.set( 0, 0, 0 );
        vel.set( ofRandom(-5,5), ofRandom(-4,-8), 0);
    }
    
    void update(){
        pos += vel;
        vel.y += .1;
    }
    
    void draw(){
        ofEllipse(pos.x,pos.y,10,10);
    }
    
    ofPoint pos;
    ofVec3f vel;
    
};

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    // declare the vector of particles
    vector<Particle> particles;
};