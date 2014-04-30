//
//  meebs.cpp
//  class_amoeba
//
//  Created by Joselyn McDonald  on 4/20/14.
//
//

#include "meebs.h"

ofMesh Meeb::meshSphereTop(ofImage imageA, ofMesh meshTop, vector<ofColor>colors, float radius, ofPoint sound){
    
    int w = imageA.getWidth();
    int h = imageA.getHeight();
    
    for (int x=0; x<w; x++){
        for(int y=0; y<w; y++){
            //create the color object at that pixel
            ofColor c = imageA.getColor(x, y);
            colors.push_back(c);
        }
    }
    
    
    int n = 100;
    
    meshTop.setMode(OF_PRIMITIVE_POINTS);
    
    //meshTop.setMode(OF_PRIMITIVE_LINE_LOOP);
    //meshTop.setMode(OF_PRIMITIVE_LINES);
    //meshTop.setMode(OF_PRIMITIVE_LINE_STRIP);
    //meshTop.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
    
    for(float i=0; i <2*PI; i+=PI/n){
        float a = cos(i);
        float b = sin(i);
        //float c = sqrt(radius*radius - (a*a + b*b));
        //cout << c << endl;
        
        ofPoint pos;
        ofPoint negPos;
        float increment = 1; // change this to make the amoeba change shape
        //float radiusSound = radius+sound.x ;
        float radiusSound = radius+sound.x + ofNoise(ofGetElapsedTimef(), i) *  50;
        
        for(float j=0; j<radiusSound+increment; j+=increment){
            float x = a*j+ofGetWidth()/2;
            float y = b*j+ofGetHeight()/2;
            float z = abs(sqrt(radiusSound*radiusSound-(a*a*j*j + b*b*j*j)));
            
            
            //cout << negZ << endl;
            pos.set(x, y, z);
            negPos.set(x, y, -z*10);
            meshTop.addVertex(pos);
            // meshTop.addColor(colors[j]);
            meshTop.addColor(255);
            
            meshTop.addVertex(negPos);
            meshTop.addColor(colors[j]);
        }
    }
    
    return meshTop;
}


    

