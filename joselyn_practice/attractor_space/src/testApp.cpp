#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    movie.loadMovie("geode.mov");
    
    movie.play();
    
    //-----------------sound-----------------------
    soundStream.listDevices();
    int bufferSize = 256;
    
    
    left.assign(bufferSize, 0.0);
    right.assign(bufferSize, 0.0);
    volHistory.assign(400, 0.0);
    
    bufferCounter= 0;
    drawCounter= 0;
    smoothedVol     = 0.0;
    scaledVol= 0.0;
    soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
    //-----------------sound-----------------------
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    movie.update();
    
    
    //-----------------sound-----------------------
    //lets scale the vol up to a 0-1 range
    scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 0.5, true);
    
    //lets record the volume into an array
    volHistory.push_back( scaledVol );
    
    //if we are bigger the the size we want to record - lets drop the oldest value
    if( volHistory.size() >= 400 ){
        volHistory.erase(volHistory.begin(), volHistory.begin()+1);
    }
    

}

//--------------------------------------------------------------
void testApp::draw(){
   
    //for geode
     movie.draw(-500, -1000, 2000, 2000);
    
    
    int n = 100000;
    
    //a = 1.40, b = 1.56, c = 1.40, d = -6.56
    float a = 100.01;
    float b = -2.53;  
    float c = 1.61  + sin(scaledVol);//+ sin(ofGetElapsedTimef()/2);
    float d = -0.33 ;
    
    
    //
    //    float a = 1.4;
    //    //sin(ofGetElapsedTimef()*scaledVol);
    //    float b = 1.56;
    //    float c = 1.40 + +sin(ofGetElapsedTimef()*scaledVol);
    //
    //    float d = -6.56;
    
    float x0, y0, x1, y1;
    x0 = y0 = x1 = y1 = 0;
    

    
    //for ----geodes--------------
    
    ofTranslate(ofGetWidth()/2*2, ofGetHeight()/4*4);
    ofScale(500, 200, 200);
    
    //ofMatrix
    
    for (int i=0; i<n; i++) {
        x1 = y0 - sin(x0)*(b*x0-c)*0.5;
        y1 = sin(c * x0) - cos(d * y0);
        
        ofFill();
        ofLine(x1, y1, x1+0.01, y1);
        
        x0 = x1;
        y0 = y1;
    }
    
    if (scaledVol>=0.40){
            
        for (int i = 0; i<255; i++){
            for (int j = 0; j<255; j++){
                ofEnableAlphaBlending();
                ofSetColor(0, 150, 255, 255);
                ofLine(x1, y1, x1+0.01, y1);
                
            }
        }
        
    } else {
        
        ofSetColor(255);
        
    }
    
    cout << scaledVol<< endl;
    
    
}



//--------------------------------------------------------------
void testApp::audioIn(float * input, int bufferSize, int nChannels){
    
    float curVol = 0.0;
    
    // samples are "interleaved"
    int numCounted = 0;
    
    //lets go through each sample and calculate the root mean square which is a rough way to calculate volume
    for (int i = 0; i < bufferSize; i++){
        left[i]= input[i*2]*0.5;
        right[i]= input[i*2+1]*0.5;
        
        curVol += left[i] * left[i];
        curVol += right[i] * right[i];
        numCounted+=2;
    }
    
    //this is how we get the mean of rms :)
    curVol /= (float)numCounted;
    
    // this is how we get the root of rms :)
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
