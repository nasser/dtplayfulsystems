#pragma once

#include "ofMain.h"
#include "meebs.h"
#include "ofxSpacebrew.h"

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
    
    Meeba meebOne;
    vector<Meeba> rainbow;
    
    //-----------------3d----------------------
    ofEasyCam easyCam;  //add a camera
    
    
    // create your spacebrew object
    Spacebrew::Connection spacebrew;
    
    // listen to spacebrew Messages
    void onMessage( Spacebrew::Message & m );
    
    //these are the names of the three integers we are getting from capsense... name them whatever you want
    
    int meebVal1;
    int meebVal2;
    int meebVal3;
};
