#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetBackgroundAuto(false);
    ofBackground(0,0,0);
    ofEnableAlphaBlending();
    
    myAngle = 0; // each update loop, increase our angle by the angleAdder
    myAngleAdder = 0.1;
    
//	myfont.loadFont("cooperBlack.ttf", 20); // 3- loadFont method load the Font the font in the
    ofSetColor(200);

}

//--------------------------------------------------------------
void testApp::update(){
    //  Background
    ofFill();
    ofSetColor(10,10,0, 2);
    ofRect(0,0,ofGetWidth(),ofGetHeight());
    
    angle+= 0.5; // Rotation Speed
    myX+= 0.1; // Rotation Speed

 	myAngle+= myAngleAdder; // each update loop, increase our angle by the angleAdder

}


//--------------------------------------------------------------
void testApp::draw(){
	
    ofSetColor(255); // White
    ofDrawBitmapString("Walking Solar system 01", 20,20);
    

    // posX, posY, separation, velocity.
    drawPlanets(myX, 2, 20, angle+1, 100);
    drawPlanets(myX, 4, 40, angle+4, 140);
    drawPlanets(myX, 6, 80, angle+8, 180);
 
    drawPlanets(myX, 8, 120, angle+10, 250);

    drawPlanets(myX, 10, 80, angle+8, 180);
    drawPlanets(myX, 12, 60, angle+4, 140);
    drawPlanets(myX, 14, 20, angle+1, 100);
    
    
    if(myX > ofGetWidth() ){
        myX = 0.0; // Rotation PosX.
    }


    
    
 // ZACH COde Exampe Start
    // and then draw a sin wave with rectangles in that color
//	drawSinWaveWithRects(0, /*no offset*/
//						 50, /*amplitude of 50*/
//						 64, /*width of 64*/
//						 140); /*height of 140*/
    // ZACH Code Example Ends
    
}

//--------------------------------------------------------------
// My Code for different planets
void testApp::drawPlanets(float posX, float posY, float separation, float velocity, float myColor){
    
    ofPushMatrix();
    ofTranslate(0, (ofGetHeight()/16)*posY); // divisin factor to translate in Y
    
	// 01 SUN
        ofPushMatrix();
        ofTranslate(posX, 0);
        ofSetColor(255,myColor, 50); // Yellow
        ofEllipse(-2, -2, 4, 4);
    
    // EARTH
            ofPushMatrix();
            ofRotateZ(velocity);
            ofTranslate(separation, 0);//Exentricity from sun.
            ofSetColor(100,myColor,255); // Blue
            ofRect(0, 0, 1, 1);
            ofPopMatrix();
    
        ofPopMatrix();
    
    ofPopMatrix();
    
}


//--------------------------------------------------------------
// ZACH code Example
void testApp::drawSinWaveWithRects(float angleBase, int amplitude, int rectWidth, int rectHeight){
	
	for(int i=0;i<ofGetWidth()/32;i++){ // increment across the screen by 32pixels at a time.
		//angleBase sets our offset. e.g. if one sin wave starts at 0, and one starts at 0.5, they wont be aligned with eachother
		//amplitude sets the height that the waves will go
		//rectWidth and rectHeight set the size and width of the rectangle. setting a width under 32 creates a space in the wave, over 32 creates overlap
		
		//we add angleBase to the sin is to offset the wave
		//we add angleAdder*i to the sin is so that each consecutive rectangle is using the sin of the next angle. (this is what creates the wave shape)
		ofRect(i*32, ofGetHeight()/2-amplitude + sin(angleBase + angle + myAngleAdder*i) * amplitude, rectWidth, rectHeight);
	}
}
// ZACH code Example Ends



//--------------------------------------------------------------
void testApp::keyPressed(int key){
    angle+= 1.9; // Rotation Speed
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 
    
}