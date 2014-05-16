//
//  ball.h
//  particle_system
//
//  Created by Joselyn McDonald  on 2/20/14.
//
//

#ifndef particle_system_ball_h
#define particle_system_ball_h

class Ball{
    
public:
    
    //constructor
    Ball();
    
    //Methods
    void moveTo();
    void draw();
    
    //Properties
    int x;
    int y;
    ofColor color; 
    
    
};

#endif
