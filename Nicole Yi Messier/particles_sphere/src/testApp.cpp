#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    int n = 100;
    
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
            cout << negZ << endl;
            pos.set(x, y, z);
            negPos.set(x, y, negZ);
            edge.push_back(pos);
            edge.push_back(negPos);
        }
    }

}

//--------------------------------------------------------------
void testApp::update(){
    

    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofColor centerColor = ofColor(85, 78, 68);
    ofColor edgeColor(0, 0, 0);
    ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);
    ofSetColor(0, 0, 255);
    
    
    //3D view
    //left click to drag to rotate
    //right click to drag to zoom
    easyCam.begin();
    ofPushMatrix();
    ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
    
    for(int i=0; i<edge.size(); i++){
        ofCircle(edge[i], 2);
    }
    
    ofPopMatrix();
    easyCam.end();

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
