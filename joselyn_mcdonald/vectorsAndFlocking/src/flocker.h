//
//  flocker.h
//  vectorsAndFlocking
//
//  Created by Joselyn McDonald  on 4/16/14.
//
//

#ifndef __vectorsAndFlocking__flocker__
#define __vectorsAndFlocking__flocker__

#include <iostream>
#include "ofMain.h"

class Flocker {
    
public:
    
    ofPoint point;
    float speed;
    float angle;
    
    void move();
    void draw();

    
}; 









#endif /* defined(__vectorsAndFlocking__flocker__) */
