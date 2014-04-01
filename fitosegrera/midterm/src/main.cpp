#include "ofMain.h"
#include "testApp.h"

//========================================================================
int main( ){
	ofSetupOpenGL(800,800,OF_FULLSCREEN);			// <-------- setup the GL context
	//ofSetupOpenGL(800,800,OF_WINDOW);

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new testApp());
	
}

