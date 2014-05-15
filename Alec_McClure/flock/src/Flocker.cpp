
#pragma once
#include "ofMain.h"
#include <iostream>
#include "Flocker.h"



void Flocker::move(){

        //this->.point.x += cos(this->.angle)*this->.speed; //this is implied
        //this->.point.y += sin(this->.angle)*this->.speed;


        point.x += cos(angle)*speed;
        point.y += sin(angle)*speed;

}

void Flocker::draw(){

        ofCircle(points[i], 2);
        ofLine(points[i], points[i] + ofPoint(cos(angles[i])*10, sin(angles[i])*10));

        }
