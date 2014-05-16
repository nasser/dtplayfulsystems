#include "testApp.h"
//made by Yinan Zhang for the class "FLy on the wall" between Parsons and Tongji University

// this is an example of using computer microphone to input live sound and using volumn to control the noise motion speed

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255, 255, 255);
     
    ofSetFrameRate(60); 
    
    for (int i = 0; i < NUM; i++){
        time[i]= ofRandom(20);   
    }
    
    
    
    //--------------------------- Sound Input
	soundStream.listDevices();
	int bufferSize = 256;
	left.assign(bufferSize, 0.0);
	volHistory.assign(400, 0.0);
	bufferCounter	= 0;
	drawCounter		= 0;
	smoothedVol     = 0.0;
	scaledVol		= 0.0;
	soundStream.setup(this, 0, 2, 44100, bufferSize, 4);

    
}

//--------------------------------------------------------------
void testApp::update(){

	scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 0.1, true);
	volHistory.push_back( scaledVol );
	if( volHistory.size() >= 400 ){
		volHistory.erase(volHistory.begin(), volHistory.begin()+1);
	}

}

//--------------------------------------------------------------
void testApp::draw(){
    
    

    ofEnableAlphaBlending();
    ofSetColor(0,0,0,50+smoothedVol*1000);
    for(int i=0; i<NUM; i++){
        time[i]+=scaledVol;           
        // mapping the input volumn to the increase of time line (the volumn controls speed of noise timeline)
        float posx =ofNoise(time[i])*1024;
        float posy =ofNoise(time[i]+1000)*768;
        ofCircle(posx, posy, 10);
        }
    ofDisableAlphaBlending();
    
    
    
}



//--------------------------------------------------------------
void testApp::audioIn(float * input, int bufferSize, int nChannels){	
    
    
	float curVol = 0.0;
	int numCounted = 0;	
	for (int i = 0; i < bufferSize; i++){
		left[i]		= input[i*2]*0.5;
		curVol += left[i] * left[i];
		numCounted+=2;
	}
	
	curVol /= (float)numCounted;
	curVol = sqrt( curVol );
	smoothedVol *= 0.93;
	smoothedVol += 0.07 * curVol;
	bufferCounter++;
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

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