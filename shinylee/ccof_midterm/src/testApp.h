#pragma once

#include "ofMain.h"
#include "ofxQuadWarp.h"

class testApp : public ofBaseApp
{
public:
		
    void setup  ();
    void update ();
    void draw   ();

    void keyPressed     ( int key );
    void keyReleased    ( int key );
    void mouseMoved     ( int x, int y );
    void mouseDragged   ( int x, int y, int button );
    void mousePressed   ( int x, int y, int button );
    void mouseReleased  ( int x, int y, int button );
    void windowResized  ( int w, int h );
    void dragEvent      ( ofDragInfo dragInfo );
    void gotMessage     ( ofMessage msg );

    ofxQuadWarp         warper, warper2, warper3;

    ofImage             img;
    ofVideoGrabber      myVideo, myVideo2;
    ofVideoPlayer       myPlayer;
    
    ofFbo               fbo, fbo2, fbo3;
    ofPoint             points[ 10 ];
};
