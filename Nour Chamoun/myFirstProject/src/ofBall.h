

#ifndef myFirstProject_ofBall_h
#define myFirstProject_ofBall_h

#include "ofMain.h"
#include "ofxVectorGraphics.h"

class ofBall {
    
public: // place public functions or variables declarations here
    
    // methods, equivalent to specific functions of your class objects
    void update();  // update method, used to refresh your objects properties
    void draw();    // draw method, this where you'll do the object's drawing
    
    // variables
    float xPos; //xPosition
    float yPos; //yPosition
    
    ofPoint pos;
    ofPoint vel;
    ofPoint acc;

  
//    vector <ofPoint> pts;
//    vector<ofPoint> myPoints;
    
    ofxVectorGraphics output;
    bool capture;
    bool bFill;
    
    float radius; //radius
    float sx; //speed of x
    float sy; //speed of y
    
    ofColor color;
    
    ofBall(float x, float y, float r); // constructor - used to initialize an object, if no properties are passed
    //               the program sets them to the default value
    
private: // place private functions or variables declarations here
    
}; // dont't forget the semicolon!!


#endif
