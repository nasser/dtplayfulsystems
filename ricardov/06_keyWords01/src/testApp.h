#pragma once

#include "ofMain.h"

class Person {
public:
    //vars
    float height;
    string  job;

    //functions
    void work();
    string getIdentityString();
    void sayHelloTo(string pal);
};

class Child : public Person {
// inherit from person
    void work();// the same name method, overwites the parent inherited
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
		
    
        float halfTime;
        void drawShape(float x, float y);
};
