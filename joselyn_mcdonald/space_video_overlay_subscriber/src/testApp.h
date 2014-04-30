#pragma once

#include "ofMain.h"

#include "ofxSpacebrew.h"  /// this must be in your addons to work


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
    
    // These are the integers we'll be getting from Spacebrew via Processing via Arduino and Capsense
    int A1Value;
    int A2Value;
    int balloonValue;
    
    // these are our video file names --- make sure the source file is located in the oF data file
    ofVideoPlayer gem;
    ofVideoPlayer geode;
    ofVideoPlayer geode_white;

    
		
};
