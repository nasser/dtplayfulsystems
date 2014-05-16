//
//  ball.cpp
//  particle_system
//
//  Created by Joselyn McDonald  on 2/20/14.
//
//

#include "ball.h"


Ball::Ball(){
    
    color.set(ofRandom(255), ofRandom(255), ofRandom(255));
    
    x = ofRandom(ofGetWindowWidth());
    
    y = ofRandom( ofGetWindowHeight() );
    
}

void Ball:: moveTo(){
    
    
}

void Ball::draw() {
    
    ofSetColor(color);
    ofFill();
    ofCircle( x, y, 30);
}
