//
//  Flocker.h
//  Class_04_09_14_boids
//
//  Created by Betty Quinn on 4/16/14.
//
//

#ifndef __Class_04_09_14_boids__Flocker__
#define __Class_04_09_14_boids__Flocker__

#include <iostream>
#include "ofMain.h"

class Flocker {
public:
    ofPoint point;
    float speed;
    float angles;
    
    void move();

};

#endif /* defined(__Class_04_09_14_boids__Flocker__) */
