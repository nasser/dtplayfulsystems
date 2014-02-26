#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    theColor.set(0,0,0);

}

//--------------------------------------------------------------
void testApp::update(){
    theColor.r +=1;

}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0, 0, 0);
    ofSetColor(230, 230, 100);
    ofDrawBox(200, 200, 200);
    ofLine(800, 800, 100, 100);
    ofSetColor(230, 100, 100);
    ofLine(500, 500, 100, 100);
    
    float redValue = 10.5;
    int redValueAsInt = 12; // -2^32...2^32
//    unsigned int redValueAsInt = 12; //0...2^32 
//    long int redValueAsInt = 12; //0...2^64
    string name = "hello world";
    
    ofSetColor(theColor);
 //   ofLine(400,400,400,400);
    
    for (int i=0 ; i<x ;i++){
        ofLine(200+i,0,200+i,500);
        if(i>50){ break;
        
    }
    
//        switch(x){
//            case 20:
//                //do some stuff
//                break;
//        case 30:
//                //do some other stuff
//                break;
//                
//            default:
//                //basically an else
//                break;
//        }
        
        
//    ofColor someColor;
//    someColor.r = 255;
//    someColor.g = 0;
//    someColor.b = 180;
//    ofSetColor(someColor);


//second
  //float speed=10;
  //ofRect(100 + ofGetElapsedTimef()*speed,100,600,400);
    
//frame
    ofRect(100 + x ,100,600,400);
    x +=5; // put the intial value x=12 in testApp.h //global variable
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    printf("press a key");
    if (key==' '){
       theColor.g =255;
    }
    
    switch (key) {
        case 'a':
            <#statements#>
            theColor.r= 255;
            break;
        case 'b':
            <#statements#>
            theColor.r= 150;
            break;
            
        default:
            break;
    }

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
  if (key==' '){
        theColor.g =0;
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
