#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    aX=300;
    aY=100;
    bX=aX+50;
    bY=100;
    genes[0]="A";
    genes[1]="T";
    genes[2]="G";
    genes[3]="C";
    
    

}

//--------------------------------------------------------------
void testApp::update(){

}


//--------------------------------------------------------------
void testApp::bar(float aY, float bY, float alp){
    gA=genes[int(ofRandom(0,3))];
    if (gA=="A"){gB="T";}
    if (gA=="T"){gB="A";}
    if (gA=="C"){gB="G";}
    if (gA=="G"){gB="C";}
    ofSetColor(255,0,0,alp);
    ofEllipse(aX ,aY,25,25);
    ofSetColor(0);
    ofDrawBitmapString(gA, aX-4 , aY+4);
    ofSetColor(255,0,0,alp);
    ofEllipse(bX,bY,25,25);
    ofSetColor(255,0,0,alp);
    ofSetColor(0);
    ofDrawBitmapString(gB, bX-4 , bY+4);
    ofLine(aX+4,aY,bX-4,bY);
}

//--------------------------------------------------------------
void testApp::draw(){

    
    ofBackground(250, 245, 255,14);
    for (int i=0;i<10;i++){
    bar(i*50,i*50,100);
    }
    if (Xdir==true){
        aX++;
        bX--;
    }else{
        aX--;
        bX++;
    }
    
    
    
    
    if (aX<290){
        Xdir=true;
    }
    if (aX>310){
        Xdir=false;
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

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