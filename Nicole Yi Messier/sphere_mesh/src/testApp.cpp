#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    image.loadImage("philly2.png");
    
    float radius = 200;
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
    
    meshTop.setMode(OF_PRIMITIVE_POINTS);
    meshBottom.setMode(OF_PRIMITIVE_POINTS);
    //meshTop.setMode(OF_PRIMITIVE_LINE_LOOP);
    //meshBottom.setMode(OF_PRIMITIVE_LINE_LOOP);
    //meshTop.setMode(OF_PRIMITIVE_LINES);
    //meshBottom.setMode(OF_PRIMITIVE_LINES);
    
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
void testApp::update(){
    

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
