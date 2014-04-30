//
//  meebs.h
//  class_amoeba
//
//  Created by Joselyn McDonald  on 4/20/14.
//
//

#ifndef __class_amoeba__meebs__
#define __class_amoeba__meebs__

#include "ofMain.h"
#include <iostream>

class Meeb {
    
public:
    
    //-----------------sphere parameters----------------------
    float radius; //radius of sphere
    ofMesh meshTop; //top half of sphere
    ofMesh meshT; //pass this mesh
    ofMesh meshSphereTop (ofImage imageA, ofMesh meshTop, vector<ofColor> colors, float radius, ofPoint sound);
    //
    //    //-----------------interpolate----------------------
    ofPoint interp (ofPoint p1, ofPoint p2, float t);
    ofPoint p1, p2, p3, p4;
    ofPoint sound;
    float range;
    //
    //-----------------image parameters----------------------
    ofImage image;
    vector<ofColor>colors;

}; 

#endif /* defined(__class_amoeba__meebs__) */
