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

		void nucleotideDraw(int type2, float nucleoPosX, float nucleoPosY, float nucleoPosZ, float rotAngle, float rotX, float rotY, float rotZ);
		void dnaDraw(int number);

		ofEasyCam cam;
		ofLight myLight;
		ofImage dnaImage;
		ofImage bgImage;
		GLUquadricObj *quadric;

		int changeAngle = 0;
		int posChangeY = 0;
		int nucleoNum;
		int pressCounter = 0;
		bool drawState = false;
		bool clicked = false;
		bool invert = false;
		ofVec3f origin;
		int nucleoType2;
		vector<int> nucleoType;
		vector<int>type;
		float posX;
		float posY;
		float posZ;
		float radius;
		float height;
};
