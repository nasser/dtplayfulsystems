#pragma once

#include "ofMain.h"

class gui : public ofBaseApp{

	public:

		void drawButton(int posX, int posY, int scaleX, int scaleY, int transparency, string name);
		void drawSlide(int posX, int posY, int scaleX, int scaleY, int tranSlide, string slideName);
		void drawBackground(int posX, int posY, int scaleX, int scaleY, int transBackground, string title, string description);
		void drawSaveBox(int posX, int posY, int scaleX, int scaleY, int transSaveBox, string fileName);

		int checkPosX, checkPosY, checkScaleX, checkScaleY;
		int checkSlidePosX, checkSlidePosY, checkSlideScaleX, checkSlideScaleY;
		int checkIntSlideScaleX = 0;
		int color = 10;
		int red = 10;
        int green = 10;
        int blue = 10;
        int saveButColor = 100;

		ofTrueTypeFont myFont, myFont2, myFont3, saveBoxFont;

		int posButCancelX;
		int posButCancelY;
		int posButSaveX;
		int posButSaveY;
		int scaleButtonsX;
		int scaleButtonsY;
		int transButtons;

		int saveTextPosX;
		int saveTextPosY;

};

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

		void setLightOri(ofLight &light, ofVec3f rot);

		//--------------------------------------------------------------------//
		//The folowing part of the GUI allows this to have a text input box for the "save image box"
		//the original code was created by elliot woods / Simple-text-buffer-for-openFrameworks please visit:
		//https://github.com/elliotwoods/Simple-text-buffer-for-openFrameworks/tree/VerySimple
		void drawText();
		void typeKey(int key);
		string	text;
		int	position;
		int	cursorx;
		int cursory;
		//--------------------------------------------------------------------//

		ofTrueTypeFont initMessageFont;
		ofMesh mesh;
		ofImage image;
		ofImage screenCapture;
        ofEasyCam easyCam;
        ofLight light;
        ofVec3f light_rot;
        ofSoundPlayer snapSound;
        ofSoundPlayer ambient;

        gui background;
        gui button1;
        gui buttonClear;
        gui buttonLines;
        gui buttonLight;
        gui slide1;
        gui slide2;
        gui slideBackColorR;
        gui slideBackColorG;
        gui slideBackColorB;
        gui slideLightRotX;
        gui slideLightRotY;
        gui slideLightRotZ;
        gui saveBox;

        ofColor color;
        int snapCounter = 0;
        int w;
        int h;
       
        bool generate = false;
        bool clear = false;
        bool generateStop = false;
        bool checkLines = false;
        bool checkLight = false;
        bool menu = false;
        bool initMessage = false;
        bool saveButState = false;
        bool saveBoxState = false;
        bool captureImageState = false;
};


