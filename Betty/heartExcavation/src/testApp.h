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
    
    void drawPointOnLine(ofPoint p1, ofPoint p2, float t);
    void drawCircleSwarm();
    
    
    int   appFPS;
    float sequenceFPS;
    bool  bFrameIndependent;
    vector <ofImage> images;
    
    void drawHeartGif();
    
    ofImage brush;
    ofImage hand;
    
    ofFbo       maskFbo;
    ofFbo       fbo;
    ofShader    shader;
    bool        bBrushDown;
    
 //   ofxDelaunay triangulation;
    ofxTSPS::Receiver tspsReceiver;
    void onPersonEntered(ofxTSPS::EventArgs & tspsEvent);
    void onPersonUpdated(ofxTSPS::EventArgs &tspsEvent);
    void onPersonWillLeave(ofxTSPS::EventArgs & tspsEvent);

    
    ofPoint p1, p2, a1, a2, b1, b2, c1, c2, d1, d2, e1, e2, f1, f2, g1, g2, h1, h2, j1, j2;
    ofPoint k1, k2, l1, l2, m1, m2, n1, n2, o1, o2, q1, q2, r1, r2, s1, s2, t1, t2;
    
    
};


