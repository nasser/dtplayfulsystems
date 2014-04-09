#include "testApp.h"

//--------------------------------------------------------------
ofMesh testApp::pixelManipulate(ofImage imageA, ofMesh meshA, float intensityThreshold, ofPoint sketchDepth){
    
    imageA.resize(200, 200);
    
    //create mesh with points as the primitive
    //meshA.setMode(OF_PRIMITIVE_POINTS);
    
    //create a mesh with lines
    meshA.setMode(OF_PRIMITIVE_LINE_LOOP);
    
    int w = imageA.getWidth();
    int h = imageA.getHeight();
    
    //loop through each pixel in the image using image width & height
    for (int x=0; x<w; x++){
        for(int y=0; y<h; y++){
            
            //create the color object at that pixel
            ofColor c = imageA.getColor(x, y);
            
            //check the intensity of the pixel's color
            float intensity = c.getLightness();
            
            //if the intensity exceeds the threshold, create a vertex at the location of the pixel
            //& color it with the pixel's color
            if (intensity >= intensityThreshold){
                
                //pushes brighter colors in the positive z direction
                //pushes whiter colors in the negative z direction
                float saturation = c.getSaturation();
                float z = ofMap(saturation, 0, 255, -sketchDepth.x, sketchDepth.y);
                
                //the image is now 1/4 the size of the OF window, so multiply
                //the pixel location by 4 so that the mesh covers the OF window
                ofVec3f pos(4*x, 4*y, z);
                meshA.addVertex(pos);
                meshA.addColor(c);
            }
        }
    }
    
    
    return meshA;
}

//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofPushMatrix(); // set a matrix to hold all transform
    
    ofSetColor(255, 0, 0); //red box
    ofRect(0, 0, 20, 20);
    ofTranslate(50, 50);
    ofSetColor(255, 255, 0); //yellow
    ofRect(0, 0, 20, 20);
    
    ofPushMatrix(); // add a matrix to the previous matrix
    ofTranslate(50, 50);
    ofSetColor(0, 255, 255);
    ofRect(0, 0, 20, 20);
    ofPopMatrix(); // now back to the first matrix
    
    ofTranslate(0, 50);
    ofSetColor(0, 0, 255);
    ofRect(0, 0, 20, 20);
    
    ofPopMatrix();

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
