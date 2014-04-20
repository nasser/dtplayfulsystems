//
//  Flocker.cpp
//  vectorsAndFlocking
//
//  Created by Ramsey Nasser on 4/16/14.
//
//

#include "Flocker.h"

void Flocker::move() {
    point.x += cos(angle)*speed;
    point.y += sin(angle)*speed;
}

void Flocker::draw() {
    ofCircle(point, 2);
    ofLine(point, point + ofPoint(cos(angle)*10, sin(angle)*10));
}