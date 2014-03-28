#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    cam.initGrabber(640, 480);
    
    thisFrame.allocate(640, 480, OF_IMAGE_COLOR);
    lastFrame.allocate(640, 480, OF_IMAGE_COLOR);
    diffImage.allocate(640, 480, OF_IMAGE_COLOR);
}

//--------------------------------------------------------------
void testApp::update(){
    
    cam.update();
    bIsFrameNew = cam.isFrameNew();
    
    if(bIsFrameNew){
    
    thisFrame.setFromPixels(cam.getPixels(), 640, 480, OF_IMAGE_COLOR);
    
    movementSum = 0;//amount of movement in the frame
    
    
    for (int i = 0; i<480; i++){
        for(int j =0; j<640; j++){
            
            ofColor currColor = thisFrame.getColor(j, i);
            ofColor prevColor = lastFrame.getColor(j, i);
            
            //extract the RGB components for each pixels
            int currR = currColor.r;
            int currG = currColor.g;
            int currB = currColor.b;
            
            int prevR = prevColor.r;
            int prevG = prevColor.g;
            int prevB = prevColor.b;
            
            //compute the difference
            int diffR = abs( currR - prevR );
            int diffG = abs( currG - prevG );
            int diffB = abs( currB - prevB );
            
            //add difference to our sum
            movementSum += diffR + diffG +diffB;
            
            //render the difference image
            ofColor diff = ofColor(diffR, diffG, diffB);
            diffImage.setColor(j, i, diff);
            
            //save the current color in the previous buffer
            lastFrame.setColor(j, i, currColor);
            
            }
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    if(movementSum > 5000000){
        ofBackground(255, 0, 0);
    }else{
        ofBackground(0);
    }
    
    cam.draw(0 ,0, 320, 240);
    
    ofImage myImage;
    
    myImage.setFromPixels(diffImage.getPixels(), 640, 480, OF_IMAGE_COLOR);
    myImage.draw(320, 0, 320, 240);
    
    ofDrawBitmapString(ofToString(movementSum), 700, 70);
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
