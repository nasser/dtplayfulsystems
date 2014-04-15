//
//  oF_Make_Shapes.h
//  wood_lands
//
//  Created by Joselyn McDonald  on 3/25/14.
//
//

#ifndef  wood_lands_oF_Make_Shapes_h
#define  wood_lands_oF_Make_Shapes_h

#include "ofMain.h"


class oF_Make_Shapes {
    
    
public:
    
    void update();
    void draw();
    
    //variables
    float x;
    float y;
    float speedX;
    float speedY;
    float dim; //dimension/size
    float dim_grow; 
    
   // oF_Make_Shapes(float x, float y, int dim); //this is the constructor - if no properties are passed - the program sets them to the default values
    
    oF_Make_Shapes(); 
    
    
    
private:
    
    
    
};


#endif
