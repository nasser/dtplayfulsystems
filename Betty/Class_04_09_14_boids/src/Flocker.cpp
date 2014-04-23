//
//  Flocker.cpp
//  Class_04_09_14_boids
//
//  Created by Betty Quinn on 4/16/14.
//
//

#include "Flocker.h"

void Flocker::move(){
    //this->point.x += cos(this->angle);
}

void Flocker::draw(){
    ofCircle(point, 2);
    ofLine(point, point+ofPoint(cos(angle)*10, sin(angle)*10));
    
}