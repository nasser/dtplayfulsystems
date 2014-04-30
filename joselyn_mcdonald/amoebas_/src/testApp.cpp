#include "testApp.h"

//--------------------------------------------------------------
ofMesh testApp::meshSphereTop (ofImage imageA, ofMesh meshTop, vector<ofColor> colors, float radius, ofPoint sound){
    
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
    
   // meshTop.setMode(OF_PRIMITIVE_POINTS);
   // meshTop.setMode(OF_PRIMITIVE_LINE_LOOP);
    meshTop.setMode(OF_PRIMITIVE_LINES);
    
    
    for(float i=0; i <2*PI; i+=PI/n){
        float a = cos(i);
        float b = sin(i);
        //float c = sqrt(radius*radius - (a*a + b*b));
        //cout << c << endl;
        
        ofPoint pos;
        ofPoint negPos;
        float increment = 1;
        //float radiusSound = radius+sound.x ;
        float radiusSound = radius+sound.x + ofNoise(ofGetElapsedTimef(), i) *  50;
        
        for(float j=0; j<radiusSound+increment; j+=increment){
            float x = a*j+ofGetWidth()/2;
            float y = b*j+ofGetHeight()/2;
            float z = abs(sqrt(radiusSound*radiusSound-(a*a*j*j + b*b*j*j)));
            
            
            //cout << negZ << endl;
            pos.set(x, y, z);
            negPos.set(x, y, -z);
            meshTop.addVertex(pos);
            meshTop.addColor(colors[j]);
            meshTop.addVertex(negPos);
            meshTop.addColor(colors[j]);
        }
    }
    
    return meshTop;
}

//--------------------------------------------------------------
ofPoint testApp::interp (ofPoint p1, ofPoint p2, float t){
    ofClamp(t, 0, 1);
    return((p2-p1)*t+p1);
}

//--------------------------------------------------------------
void testApp::setup(){
    image.loadImage("flower.png");
    
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
    
    //-----------movie------------
    myPlayer.loadMovie("geode_white.mov");
    myPlayer.play();
}

//--------------------------------------------------------------
void testApp::update(){
    //-----------------sound-----------------------
    //lets scale the vol up to a 0-1 range
    scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 700.0, true);
    
    //lets record the volume into an array
    volHistory.push_back( scaledVol );
    
    //if we are bigger the the size we want to record - lets drop the oldest value
    if( volHistory.size() >= 400 ){
        volHistory.erase(volHistory.begin(), volHistory.begin()+1);
    }
    //-----------------sound-----------------------
    
    //-----------movie------------
    myPlayer.update(); // get all the new frames
}

//--------------------------------------------------------------
void testApp::draw(){
    //-----------movie------------
    myPlayer.draw(-600,-200, 2500,1250);
    //ofBackground(0, 0, 0);
    
    float radius = 100;
    float range = 100;
    //cout<< scaledVol <<endl;
    
    p1.set(radius*scaledVol, radius*scaledVol);
    p2.set(range*scaledVol, range*scaledVol);
    p3 = interp(p1, p2, cos(ofGetElapsedTimef()));
    p4 = p1;
    //sound = interp(p3, p4, 1);
    sound.set(scaledVol, scaledVol);
    cout << sound.x <<endl;
    
    //3D view
    //left click to drag to rotate
    //right click to drag to zoom
    easyCam.begin();
    ofPushMatrix();
    ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
    
    meshTop = meshSphereTop(image, meshT, colors, radius, sound);
    meshTop.draw();
    
    
    ofPopMatrix();
    easyCam.end();
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