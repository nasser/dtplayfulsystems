//
//  oF_Make_Shapes.cpp
//  wood_lands
//
//  Created by Joselyn McDonald  on 3/25/14.
//
//

#include "oF_Make_Shapes.h"



oF_Make_Shapes::oF_Make_Shapes(){
    
    x = ofRandom(0, ofGetWidth());
    y = ofRandom(0, ofGetHeight());
    
    speedX = ofRandom(-1, 1);
    speedY = ofRandom(-1, 1);
    
    dim = ofRandom(2, 5);
    
    dim_grow = ofGetElapsedTimef(); 
    
}

void oF_Make_Shapes::update(){
    
    if (x < 0){
        x = 0;
        speedX *= -1;
    } else if (x> ofGetWidth()){
        x = ofGetWidth();
        speedX *= -1;
    }
    
    if (y<0){
        y = 0;
        speedY *= -1;
    } else if (y > ofGetHeight()){
        y = ofGetHeight();
        speedY *= -1;
    }
    
    
    x += speedX;
    y += speedY;
    
    
    
    
    if (dim >= 200){
        dim = 200; 
        dim_grow *=-1;
    } else if (dim <= 10){
        dim = 10;
        dim_grow*=-1;
    }
    
    dim +=dim_grow;

}

void oF_Make_Shapes::draw(){
    
    // ofSetColor(255,0,255);
   // ofSetLineWidth(100);
	ofCircle(x, y, dim);
    ofRect(x, y, dim, dim);
    ofTriangle(x, y, x+30, y+30, dim, dim); 
 
}