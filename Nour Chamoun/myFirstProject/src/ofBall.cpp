

#include "ofBall.h"

ofBall::ofBall(float _x, float _y, float _r){
    
    capture = false;
	bFill	= false;
    radius=_r;
    
    xPos=_x;
    yPos=_y;
    
    sx=ofRandom(-10,10);
    sy=ofRandom(-10,10);
    
    color.set((int)ofRandom(0,255),(int)ofRandom(0,255),(int)ofRandom(0,255));
    
//    for (int i = 0; i < 100; i++){
//		ofSetColor((int)ofRandom(0,255),(int)ofRandom(0,255),(int)ofRandom(0,255));
//	}
    
    
}

void ofBall::update(){
    //sy=sy+g;
    
    // change x direction
    if ((xPos>=ofGetWidth()-radius) || (xPos<=0+radius)) {
        sx=sx*-1;
        //sy=sy+g;
    }
    
    // change y direction
    if ((yPos>=ofGetHeight()-radius) || (yPos<=0+radius)) {
        sy=sy*-1;
        //sy=sy+g;
    }
    
    if((yPos>=ofGetHeight()-radius)&&(sy<=0)){
        yPos=ofGetHeight()-radius;
    }
    
    xPos+=sx;
    yPos+=sy;
}

void ofBall::draw(){
    ofSetColor(color);
    ofCircle(pos,radius);
    
//    int mouseX, mouseY;
//    
//    int numSteps = ( (float)mouseX / ofGetWidth() )* 10.0;
//    numSteps = MAX(3, numSteps);
//    
//    float step		= TWO_PI / (numSteps);
//    float angle		= 0.0;
//    float scale     = 1.0 + 0.2;
//    
//    
//    
//        for(int i = 0; i < numSteps; i++){
//            
//            
//			float rx = pos.x + cos(angle) * radius;
//			float ry = pos.y + sin(angle) * radius;
//            
//			if(i == 0){
//				output.polyVertex(rx, ry);
//			}
//            
//			float rx2 = pos.x + cos(angle+step) * radius;
//			float ry2 = pos.y + sin(angle+step) * radius;
//     
//			//lets make our control points in between each side and out a little way
//			float cx = pos.x + cos(angle + step*0.5) * radius * scale;
//			float cy = pos.y + sin(angle + step*0.5) * radius * scale;
//            
//			output.bezierVertex(cx, cy, cx, cy, rx2, ry2);
//            
//			angle += step;
//		}
//
//    
//        output.endShape(true);
    }
