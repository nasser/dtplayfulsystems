#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
	counter = 0;
	ofSetCircleResolution(50);
	ofBackground(255,255,255);
	bSmooth = false;
	ofSetWindowTitle("graphics example");

	ofSetFrameRate(60); // if vertical sync is off, we can go a bit fast... this caps the framerate at 60fps.
    myfont.loadFont("frabk.ttf", 32);
}

//--------------------------------------------------------------
void testApp::update(){
	counter = counter + 0.033f;
}

//--------------------------------------------------------------
void testApp::draw(){
    
    myfont.drawString("hi!!", 800,200);

//	//--------------------------- circles
//	//let's draw a circle:
//    int posX = 800;
//    int posY = 400;
//	ofSetColor(0,130,255);
//	float radius = 50 + 10 * sin(counter);
//	ofFill();		// draw "filled shapes"
//	ofCircle(posX,posY,radius);
//
//	// now just an outline
//	ofNoFill();
//	ofSetHexColor(0xCCCCCC);
//	ofCircle(posX,posY,80);
//
//	// use the bitMap type
//	// note, this can be slow on some graphics cards
//	// because it is using glDrawPixels which varies in
//	// speed from system to system.  try using ofTrueTypeFont
//	// if this bitMap type slows you down.
//	ofSetHexColor(0x000000);
//	ofDrawBitmapString("circle", 75,500);


	//--------------------------- rectangles
	ofFill();
	for (int i = 0; i < 200; i++){
		ofSetColor((int)ofRandom(0,255),(int)ofRandom(0,255),(int)ofRandom(0,255));
		ofRect(ofRandom(0,500),ofRandom(0,500),ofRandom(30,60),ofRandom(30,60));
	}
	ofSetHexColor(0x000000);
	ofDrawBitmapString("rectangles", 200,600);

//	//---------------------------  transparency
//	ofSetHexColor(0x00FF33);
//	ofRect(400,350,100,100);
//	// alpha is usually turned off - for speed puposes.  let's turn it on!
//	ofEnableAlphaBlending();
//	ofSetColor(255,0,0,127);   // red, 50% transparent
//	ofRect(450,430,100,33);
//	ofSetColor(255,0,0,(int)(counter * 10.0f) % 255);   // red, variable transparent
//	ofRect(450,370,100,33);
//	ofDisableAlphaBlending();
//
//	ofSetHexColor(0x000000);
//	ofDrawBitmapString("transparency", 410,500);

	//---------------------------  lines
	// a bunch of red lines, make them smooth if the flag is set
//
//	ofSetHexColor(0xFF0000);
//	for (int i = 0; i < 360; i++){
//		ofLine(800,300, 100, 250 + (i*10));
//	}
//
//	ofSetHexColor(0x000000);
//	ofDrawBitmapString("lines\npress 's' to toggle smoothness", 600,500);

}


//--------------------------------------------------------------
void testApp::keyPressed  (int key){
//	if (key == 's'){
//		bSmooth = !bSmooth;
//        if (bSmooth){
//            ofEnableAntiAliasing(); 
//        }else{
//            ofDisableAntiAliasing(); 
//        }
//	}
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){

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