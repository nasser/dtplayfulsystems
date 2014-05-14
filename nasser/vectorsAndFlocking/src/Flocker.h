//
//  Flocker.h
//  vectorsAndFlocking
//
//  Created by Ramsey Nasser on 4/16/14.
//
//

#ifndef __vectorsAndFlocking__Flocker__
#define __vectorsAndFlocking__Flocker__

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

#endif /* defined(__vectorsAndFlocking__Flocker__) */
