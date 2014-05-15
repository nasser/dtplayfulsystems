#pragma once

#include "ofMain.h"
#include "ofxSvg.h"

//BASED ON 
//RAMSEY NASSER EXAMPLE

#define NUM_ELEMENTS 100
#define NUM_FILES 30

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
    
    //Declaring vectors vector< type > name
    vector<ofPoint> points;
    vector<float> angles;
    vector<float> speeds;
    vector<float> sizes;
    vector<float> colors;
    
    ofPoint manualTarget;
    
    
    // Format sheet= 24 x 19 // 1368 x 1728
    
    //R
    float wMiddle, hMiddle;
    
    string text;
    float amount;
    float sz;
    ofTrueTypeFont	font1;
    
    float myTypoPointsX;
    float myTypoPointsY;
    
    //SVG
    void myShape1(int _x, int _y, int _rot);

    
    vector <ofxSVG> mySvgFiles;
    vector <ofPoint> mySvgPoints;
    vector <float> mySvgRotation;
    vector <float> mySvgScale;
    float rX;
    float rY;
    float displaceToTop;
    float colorStart;

    //R POEM
    string poemAsString;
    
    //R TO PDF
    bool oneShot;
    
    //R SAVE IMAGE
    int 				snapCounter;
    char 				snapString[255];
    ofImage 			img;
    bool 				bSnapshot;

    

};
