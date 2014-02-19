#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    theColor.set(0,0,0);
}

//--------------------------------------------------------------
void testApp::update(){
 //   theColor.r +=1;
 //   x+=1;
    // 1 pixel/frame =several pixels/second
    
    if(theColor.r<255)
        theColor.r += 1;
    
  /* the same as
    if(theColor.r<255) {
        theColor.r += 1; 
    }
   if only one statement in the brackets
    */
    
    x +=0.1;
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0,0,0);
    ofSetColor(230,230,100);
    ofLine(10,10,100,100);
    ofSetColor(theColor);
    ofLine(500,500,100,100);
    
    float redValue= 10.5;
    int redValueAsInt = 12; // -2^32...2^32
    //unsigned int   //0...2^32
    //long int  // 0...2^64;
    //long long int
    
    
    string name = "hello";
    
    ofRect(200+x, 200,600,400);
    
    
    ofSetColor(255,255,0);
    for (int i=0; i<x; i+=20){  //i<x can be changed by callsomefunctions() e.g. true
        ofLine(200+i, 0, 200+i, 500);
        //if(i>50) {break;}
    }
 
    // ofRect(100+ofGetElapsedTimef()*10,100,600,400); //1 pixel/second
    
  /*  switch (x) {
        case 20:
            //do some stuff
            break;
        case 30;
            //do some stuff
            break;
            
        default:
            //basically an else
            break;
    }
   */

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
 /*   if (key == ' ') {
       theColor.g = 255;
    }
*/
    switch (key) {
        case ' ':
            theColor.r=255;
            break;
        case 'a':
            theColor.g=88;
            break;
        case 's':
            theColor.b=128;
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    if (key == ' ') {
     theColor.g = 0;
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
