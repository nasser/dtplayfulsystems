#pragma once

#include "ofMain.h"

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
    
    // create your spacebrew object
    Spacebrew::Connection spacebrew;
    
    
    // listen to spacebrew Messages
    void onMessage( Spacebrew::Message & m );
    
      int sliderXValue;
    
    int scale;
    
    //create image object
    ofImage image;
    
    //add a mesh called mesh
    ofMesh mesh;
    
    //add a camera
    ofEasyCam easyCam;
    
    //variables to allow to toggle oribal on & off
    ofMesh meshCopy;
    bool orbiting;
    float startOrbitTime;
    
    //variables to store the polar coordinates of each vertex
    vector<float> distances;
    vector<float> angles;
    ofVec3f meshCentroid;
    
    void pixelManipulate(ofImage imageA, ofMesh meshA);
};
