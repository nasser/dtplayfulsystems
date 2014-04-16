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
    
  
    void setInit(ofVec2f initPos);    
    void resetForce();
    void addForce(ofVec2f force);
    void updateForce();
    void updatePos();
    void checkBounds(float xmin, float ymin, float xmax, float ymax);
    void constrain(float xmin, float ymin, float xmax, float ymax);
    
 
    static const int CIRCLE_NUM = 1000;
    
    ofVec2f position[CIRCLE_NUM];
    ofVec2f velocity[CIRCLE_NUM];
    ofVec2f force[CIRCLE_NUM];

    float friction;
};
