#pragma once

#include "ofMain.h"
#include "ofxTSPSReceiver.h"

//#include "ofxDelaunay.h"


class testApp : public ofBaseApp {
    
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
    
    int   appFPS;
    float sequenceFPS;
    bool  bFrameIndependent;
    vector <ofImage> images;
    
    void drawSleeper();
    
    ofImage brush;
    
    ofFbo       maskFbo;
    ofFbo       fbo;
    ofShader    shader;
    bool        bBrushDown;
    
    ofxTSPS::Receiver tspsReceiver;
    void onPersonEntered(ofxTSPS::EventArgs & tspsEvent);
    void onPersonUpdated(ofxTSPS::EventArgs &tspsEvent);
    void onPersonWillLeave(ofxTSPS::EventArgs & tspsEvent);
    
    
    
};
