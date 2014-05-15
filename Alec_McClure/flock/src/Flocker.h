#pragma once

#include "ofMain.h"
using namespace std;


//========================================================================
class Flocker{
    public:

        vector<ofPoint> point;
        vector<float> angle;
        vector<float> speed;

        void move();
        void draw();


};
