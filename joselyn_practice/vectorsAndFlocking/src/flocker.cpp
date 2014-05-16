//
//  flocker.cpp
//  vectorsAndFlocking
//
//  Created by Joselyn McDonald  on 4/16/14.
//
//

#include "flocker.h"


void Flocker::move(){
    
    point.x += cos(angle)*speed;
    point.y += cos(angle)*speed;
    
    
}

void Flocker::draw(){
    
    ofCircle(point, 2);
    ofLine(point, point + ofPoint(cos(angle)*10, sin(angle)*10));
    
    
}