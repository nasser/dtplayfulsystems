#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    image.loadImage("philly2.png");
    
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
    
    //-----------------sound-----------------------
    //lets scale the vol up to a 0-1 range
    scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 200.0, true);
    
    //lets record the volume into an array
    volHistory.push_back( scaledVol );
    
    //if we are bigger the the size we want to record - lets drop the oldest value
    if( volHistory.size() >= 400 ){
        volHistory.erase(volHistory.begin(), volHistory.begin()+1);
    }
    //-----------------sound-----------------------
    
    float radius = 200 + scaledVol;
    cout << scaledVol << endl;
    int w = image.getWidth();
    int h = image.getHeight();
    
    for (int x=0; x<w; x++){
        for(int y=0; y<w; y++){
            //create the color object at that pixel
            ofColor c = image.getColor(x, y);
            colors.push_back(c);
        }
    }
    
    int n = 100;
    
    //meshTop.setMode(OF_PRIMITIVE_POINTS);
    //meshBottom.setMode(OF_PRIMITIVE_POINTS);
    meshTop.setMode(OF_PRIMITIVE_LINE_LOOP);
    meshBottom.setMode(OF_PRIMITIVE_LINE_LOOP);
    //meshTop.setMode(OF_PRIMITIVE_LINES);
    //meshBottom.setMode(OF_PRIMITIVE_LINES);
    
    
    meshTop.clear();
    meshBottom.clear();
    
    for(float i=0; i <2*PI; i+=PI/n){
        float a = cos(i);
        float b = sin(i);
        //float c = sqrt(radius*radius - (a*a + b*b));
        //cout << c << endl;
        
        ofPoint pos;
        ofPoint negPos;
        float increment = 1;
        
        for(float j=0; j<radius+increment; j+=increment){
            float x = a*j+ofGetWidth()/2;
            float y = b*j+ofGetHeight()/2;
            float z = abs(sqrt(radius*radius-(a*a*j*j + b*b*j*j)));
            float negZ = -z;
            
            //cout << negZ << endl;
            pos.set(x, y, z);
            negPos.set(x, y, negZ);
            meshTop.addVertex(pos);
            meshBottom.addVertex(negPos);
            meshTop.addColor(colors[j]);
            meshBottom.addColor(colors[j]);
        }
    }
    
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofColor centerColor = ofColor(85, 78, 68);
    ofColor edgeColor(0, 0, 0);
    ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);
    
    
    //3D view
    //left click to drag to rotate
    //right click to drag to zoom
    easyCam.begin();
    ofPushMatrix();
    ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
    
    meshTop.draw();
    meshBottom.draw();
    
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
