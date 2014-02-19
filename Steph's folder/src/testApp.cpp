#include "testApp.h"

float xpos;
float ypos;
int myCircleX;
int myCircleY;
int myCircleRadius=100;
double radius;

//--------------------------------------------------------------
void testApp::setup(){
	
    ofBackground(0,0,0);
    ofSetFrameRate(60);
    myCircleX = 300;
	myCircleY = 200;
    radius = 20;
	
	camWidth 		= 640;	// try to grab at this size. 
	camHeight 		= 480;
	
	vidGrabber.setVerbose(true);
	vidGrabber.initGrabber(camWidth,camHeight);

    font.loadFont("Courier New Bold.ttf", 9);
    
    // this set of characters comes from processing: 
    //http://processing.org/learning/library/asciivideo.html
    
	// changed order slightly to work better for mapping
    asciiCharacters =  string("  ..,,,'''``--_:;^^**""=+<>iv%&xclrs)/){}I?!][1taeo7zjLunT#@JCwfy325Fp6mqSghVd4EgXPGZbYkOA8U$KHDBWNMR0Q");
	
    ofEnableAlphaBlending();
}


//--------------------------------------------------------------
void testApp::update(){
	
    myCircleX+4;
    if(myCircleX > 1024)
    {
        myCircleX = 300;
    }
    
    ofSetColor(255, 0, 255);
	ofCircle(myCircleX, myCircleY, 60);
    vidGrabber.update();
}

//--------------------------------------------------------------
void testApp::draw(){
	
    
    ofSetColor(255, 0, 255);
    ofCircle(myCircleX, myCircleY, myCircleRadius);
    
    myCircleX = myCircleX;
	
	ofSetColor(255, 0, 255);
	ofCircle(myCircleX, myCircleY, 60);
    
    // change background video alpha value based on the mouse position
    float videoAlphaValue = ofMap(mouseX, 0,ofGetWidth(),0,255);
    
    // set a white fill color with the alpha generated above
    ofSetColor(203,100,235,videoAlphaValue);

    // draw the raw video frame with the alpha value generated above
    vidGrabber.draw(0,0);

    ofPixelsRef pixelsRef = vidGrabber.getPixelsRef();
    
    ofSetHexColor(0xffffff);

    for (int i = 0; i < camWidth; i+= 7){
        for (int j = 0; j < camHeight; j+= 9){
            // get the pixel and its lightness (lightness is the average of its RGB values)
            float lightness = pixelsRef.getColor(i,j).getLightness();
            // calculate the index of the character from our asciiCharacters array
            int character = powf( ofMap(lightness, 0, 255, 0, 1), 2.5) * asciiCharacters.size();
            // draw the character at the correct location
            font.drawString(ofToString(asciiCharacters[character]), i, j);
        }
    }
    
}


//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
	// in fullscreen mode, on a pc at least, the 
	// first time video settings the come up
	// they come up *under* the fullscreen window
	// use alt-tab to navigate to the settings
	// window. we are working on a fix for this...
	
	if(key==119) // 'w' key
    {
        myCircleY--;
    }
    if(key==97) // 'a' key
    {
        myCircleX--;
    }
 
   
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
    cout << "keyReleased: " << key << endl;
    
    // == is the boolean operator
    if(key==356)
    {
        myCircleX -= 10;
    }
    if(key==359)
    {
        myCircleY += 10;
    }
    
    if(key == 358)
    {
        myCircleX +=5;
    }
    
    if(key == 357)
    {
     myCircleY-=5;
    }
    
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    float distance = ofDist(myCircleX, myCircleY, x, y);
 	if(distance < myCircleRadius)
 	{
 		myCircleRadius++;
 	}
    if(distance > myCircleRadius)
 	{
 		myCircleRadius--;
 	}
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    float dist = ofDist(x, y, xpos, ypos);
    if(dist < radius)
    {
        radius += 5;
    }
    else if (dist > radius)
    {
        radius -= 5;
    }

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
