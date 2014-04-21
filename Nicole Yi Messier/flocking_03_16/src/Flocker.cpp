//
//  Flocker.cpp
//  flocking_03_16
//
//  Created by Nicole Messier on 4/16/14.
//
//

#include "Flocker.h"

void Flocker::move(){
   // this->point.x += cos(this->angle)*this->speed;
   // this->point.y += sin(this->angle)*this->speed;
    
    point.x += cos(angle)*speed;
    point.y += sin(angle)*speed;
    
    //the above does the same thing
}

void Flocker::draw(){
    ofCircle(point, 2);
    ofLine(point, point + ofPoint(cos(angle)*10, sin(angle)*10));
}