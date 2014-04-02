#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "ofAddons.h"
#include "bezierCurve.h"

class testApp : public ofSimpleApp{
    
public:
    
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased();
    
    // Lines in 3D spaces - same code from ofLine + z dimension
    void        line3D(float x1,float y1,float z1,float x2,float y2,float z2);
    
    // time based animation function
    void        animateValue(float duration);
    
    // bezier curve function
    void        setBezierPoints();
    
    // Bezier test curve variables
    ofPoint      startPoint;
    ofPoint      cP1;
    ofPoint      cP2;
    ofPoint      endPoint;
    ofPoint      pt;
    
    // time based animation variables
    float       thisTime;
    float       duration;
    float       actualValue;
    bool        startAnim;
    
    
};

#endif

