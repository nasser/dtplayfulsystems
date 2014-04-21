//
//  Flocker.h
//  flocking_03_16
//
//  Created by Nicole Messier on 4/16/14.
//
//

#ifndef __flocking_03_16__Flocker__
#define __flocking_03_16__Flocker__

#include <iostream>

#include "ofMain.h"

class Flocker {
public:
    
    ofPoint point;
    float speed;
    float angle;
    
    Flocker();
    void move();
    void draw();
};

#endif /* defined(__flocking_03_16__Flocker__) */
