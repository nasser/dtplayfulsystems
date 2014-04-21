//
//  meebs.cpp
//  amoeba_class
//
//  Created by Nicole Messier on 4/21/14.
//
//

#include "meebs.h"

void Meeba::drawMeebs() {
    
   meshTop.setMode(OF_PRIMITIVE_POINTS);

    for(float i=0; i <2*PI; i+=PI/density){
        float a = cos(i);
        float b = sin(i);

        ofPoint pos;
        ofPoint negPos;
        float increment = 1;
        //float radiusSound = radius+sound.x ;
        float radius2 = radius + ofNoise(ofGetElapsedTimef(), i) *  50;
        
        for(float j=0; j<radius2+increment; j+=increment){
            float x = a*j+ofGetWidth()/2 + shift.x;
            float y = b*j+ofGetHeight()/2 + shift.y;
            float z = abs(sqrt(radius2*radius2-(a*a*j*j + b*b*j*j)));
            
            
            //cout << negZ << endl;
            pos.set(x, y, z);
            negPos.set(x, y, -z);
            meshTop.addVertex(pos);
            meshTop.addColor(color);
            meshTop.addVertex(negPos);
            meshTop.addColor(color);
        }
    }

      meshTop.draw();
    meshTop.clear();
    
}

void Meeba::moveMeebs(){
    shift.y += ofGetElapsedTimef()*speed;
}