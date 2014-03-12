//command for the compilier
//insures header file is only included once
#pragma once

//includes all of openFrameWorks
#include "ofMain.h"

//class is the template of a function - used to make copies
class Person {
    
    public:
        float height; //variable declaration
        int age;
        string job;
    
        void work();
        string getIdentifyString();
        void sayHelloTo(string pal);
};

//child is a subclass of person
//...in ccp file
/*
class child : public Person {
    
};


Person ramsey;
ramsey.height = 170;
ramsey.job = "hacker";
ramsey.getIdentifyString();

Person tim;
tim.height = 180;
tim.job = "accountant";
*/

//testApp is a subclass of ofBaseApp
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
		
    float halfTime;
    void drawShape(float x, float y);
};
