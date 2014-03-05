#include "testApp.h"

void testApp ::drawTwoLines( float spacing, float x1, float y1, float x2, float y2){
    ofLine(x1, y1, x2, y2);
    ofLine(x1, y1 + spacing, x2, y2 + spacing);
}


ofPoint testApp :: drawAngledLine(ofPoint center, float angle, float length){
    
    
//    float outerX = x + cos(ofDegToRad(angle)) *length;
//    float outerY = y + sin(ofDegToRad(angle)) * length;
//    ofLine(x, y, outerX, outerY);
    
    
    //or CLASS OF ofPoint
    
//   center.x = center.x + cos(ofDegToRad(angle)) *length;
//    center.y = center.y + sin(ofDegToRad(angle)) * length;
//
//    ofLine(x, y, outer.x, outer.y);
    
    
    ofPoint outer;
    outer.set(cos(ofDegToRad(angle)), sin(ofDegToRad(angle))); 
    ofLine(center, center + outer * length);
    

    
    //outer.x = cos(ofDegToRad(angle)) *length;
    //outer.y = sin(ofDegToRad(angle)) * length; 
    //ofLine(center.x, center.y, outer.x, outer.y);
    
    return center + outer * length;   
    
    
}



//--------------------------------------------------------------
void testApp::setup(){
    
    //cout<< ofGetWidth() <<endl;
    //ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
    
    clickBox.set(0, 0, 100, 100); 
    

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    //drawTwoLines(20, 0,0,100, 200);
    //drawTwoLines(20 + sin(ofGetElapsedTimef()*20) *50, 0, 0, 100, 200);
    //drawAngledLine(ofGetWidth()/2, ofGetHeight()/2, 45, 100);
    
    //    center.x = ofGetWidth()/2;
    //    center.y = ofGetHeight()/2;
    
    // drawAngledLine(center, 45 + ofGetElapsedTimef() * 50, 100);
    //clickBox.setPosition(center);
    
    ofPoint center;
    
    ofRect(clickBox);
    
    ofPoint outerPosition = drawAngledLine(center, 45 + ofGetElapsedTimef() * 50, 100);
 
    clickBox.setPosition(outerPosition); 
    
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
    
    if(clickBox.inside(x, y)){
        cout << "clicked me" << endl; 
        
        
    }

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
