#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"


//video link:https://www.youtube.com/watch?v=nmqQSy36MiE&feature=youtu.be
//========================================================================
int main( ){

    ofAppGlutWindow window;
	ofSetupOpenGL(&window, 1024, 768, OF_FULLSCREEN);
    // can be OF_WINDOW or OF_FULLSCREEN
    
    // <-------- setup the GL context

	// this kicks off the running of my app
    ofRunApp( new testApp());
	// pass in width and height too:

}
