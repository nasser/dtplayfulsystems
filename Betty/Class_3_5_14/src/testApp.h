#pragma once //only include this file once when compiling...message to compiler

#include "ofMain.h" //gives access to all of of oF

class Person {
public:
    float height;
    int age;
    
    void work();
    string identifySelf(); // p.identifySelf(); produces "My name is Betty"
    void seyHelloTp(string pal);
};

//in cpp file, Person p; p.height = 64cm; p.age = 29;

class Child : public Person { //make all of properties of person public inside Child
    
};


//
//Child someKid;
//someKid.height = 40;
//someKid.job = "whee";
//we didnt need to define variables because it inheranted it from Person

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

//1) Declare
    //scope: what part of the code can other code see
    //type and name
    //must manually declare type
//2) Define
//3) Use
//  
//
// class is a blueprint of what app/sketch will be; make many copies; has everything that will be in it
// example: person class ( will include age, height, gender)
// everything in a class is private by default
    // private means that the variable or function can only be accessed by the class
        // nothing in program is capable of changing variable or function when private
    // public makes it accessible to rest of program
    // protected means that only class and things inherented (subclasses) can access it
    // friend - another class declared as a friend can see it
// object oriented programming = oriented about objects in class?
// variable -- named storage that has a value
//
// function that returns nothing is a void
//          void (return type) KeyPressed (name) (int key) (variable dec);
        //  function is a block of code that you can associate with a name, with parameters for inputs, performs
        //  a behavior and produce a new value
        //  it also produces side effects
        //  functions store behavior -- cannot change a function while it's running in C++
        // side effects are not a new value (ex. ofCircle does not return a new value, but draws)
//
// consructor is a function that runs once when an object is created 
//
// method is a function inside a class; method is a function bound to a class
//
// this refers to the current object being called
    // use dot (.)for actual objects
    // use pointers -> for pointers?
// & gives you the address in memory
//
//
//
//
//
//
//