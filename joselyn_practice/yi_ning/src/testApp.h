#pragma once

#include "ofMain.h"
//#include "ofxOpticalFlowFarneback.h"
#include "ofxOpenCv.h"
#include "ofxOsc.h"
#include "ofxGui.h"

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
    
    ofLight             pointLight, pointLight2;
    ofMaterial          material;
    
    //---CV images
    ofVideoGrabber      vidGrabber;
    bool                bGetBackground;
    ofxCvGrayscaleImage bgImg, vidGrayImg, diffImg;
    ofxCvColorImage     vidColorImg;
    
    ofShader            shader;
    ofImage             colormap, bumpmap;
    GLUquadricObj       *quadric;
    
    ofxOpticalFlowLK    flowSolver;
    ofFbo               fbo, texFbo;
    ofPixels            pix, texPix;
    ofImage             img, perlinImg, texImg, smallVidImg;
    int                 yPos;
    
    //---GUI
    ofxIntSlider        thres;
    //ofxIntSlider        blur;
    ofxPanel            gui;
    bool                bDrawGui;
    
    //---blob tracker & sound buttons
    ofxCvContourFinder  contourFinder;
    bool                bDrawBtn;
    ofRectangle         myRect;
    vector<ofRectangle> leftBtns;
    vector<bool>        bLeftBtnTrue;
    
    //---OSC
    ofxOscSender        mSender;
    
};
