#pragma once

#include "ofMain.h"

//object oriented programming

class Person { //class
public:
    float height; //function
    string job; //variable
    
    void work();
    string identifySelf(); //method
    void sayHelloTo(string pal);
};

//class Child : public Person{
//    void work();
//};
//
//Child someKid;
//someKid.height = 30;
//someKid.job = "eating babyfood";
//someKid.work();

//anything that's out of a class is a method

// in a cpp file

//Person nour; //object 1
//nour.height = 170;
//nour.job = "hacker";
//
//Person dan; //object 2
//dan.height = 160;
//dan.job = "baker";

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
