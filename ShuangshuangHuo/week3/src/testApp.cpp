#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofBackground(255, 255, 255);
 

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
 //   ofLine(0,384,1024,384);
    for(int i=0; i<75; i++){
        pX[i]=ctrX+r*cos(TWO_PI/59*i);
        pY[i]=ctrY+r*sin(TWO_PI/59*i);
        
        if(i<60){
        ofLine(pX[i], pY[i], pX[i+1], pY[i+1]);
        }
    
      //   cout<<pX[i]<<endl;
      //  cout<<pY[i]<<endl;
      //  cout<<i<<endl;
       //   cout<<cos(10*i)<<endl;
    ofSetColor(255, 0, 0);
    ofFill();
 //   ofEllipse(pX[i],pY[i],10,10);
 //   ofSetColor(0,0,255);
 //   ofEllipse(pX[0],pY[0],10,10);
 //   ofEllipse(pX[1],pY[1],10,10);
      
        
      // basic right part
        if(i>=0 && i<=15){
            ofSetColor(0, 0, 0);
            ofLine(pX[i], pY[i], pX[i+44], pY[i+44]);
        }

      //basic left part
        if(i>=15 && i<=29){
            ofLine(pX[i], pY[i], pX[i+15], pY[i+15]);
        }
        
      //left heart curve
        if(i>=30 && i<=44){
            ofLine(pX[i], pY[i], pX[i+(i-14)], pY[i+(i-14)]);
        }
        
      //right heart curve
        if(i>=45 && i<=59){
            ofSetColor(0, 0, 0);
            ofLine(pX[i], pY[i], pX[i-(75-i)], pY[i-(75-i)]);
        }
      
    }

    
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
