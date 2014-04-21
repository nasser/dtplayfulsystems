//
//  meebs.h
//  amoeba_class
//
//  Created by Nicole Messier on 4/21/14.
//
//

#ifndef __amoeba_class__meebs__
#define __amoeba_class__meebs__

#include "ofMain.h"

#include <iostream>

using namespace std; //c++ has namespaces to group things by topics

class Meeba{
    public:
    
        float radius; //radius of sphere
        ofMesh meshTop;
        ofColor color;
        int density;
        ofPoint shift;
        int speed; 
    
        //-------methods------------
    void drawMeebs();
    void moveMeebs();
    
    
};


#endif /* defined(__amoeba_class__meebs__) */

