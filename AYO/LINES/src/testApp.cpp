#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    backr=240;
    backg=250;
    backb=200;
    backa=4;
    width=600;
    height=600;
    speed1=10;
    lineW=0;
    lineInt=0;
    lSx=0;
    lSy=0;
    lEx=0;
    lEy=0;
    l2Sx=0;
    l2Sy=0;
    l2Ex=0;
    l2Ey=0;
    l3Sx=0;
    l3Sy=0;
    l3Ex=0;
    l3Ey=0;
    alp=50;
    
    ofBackground(backr,backg,backb,backa);
    verdana14.loadFont("verdana.ttf", 12, true, true);
	verdana14.setLineHeight(18.0f);
	verdana14.setLetterSpacing(1.037);

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(backr,backg,backb,backa);
    
    if (q==true){
        
    
    for (int i=0; i<600; i++) {
        ofPushMatrix();
        ofRotate(ofRandom(10),0.0,0.0,1.0);
        
        if (s1){
            ofSetColor(100,150,200,alp );
            ofLine(lSx,i*lSy,i*lEx,lEy);
        }
        
        if (s2){
            ofSetColor(150,200,100,alp );
            ofLine(600-l2Sx,i*l2Sy,600-(i*l2Ex),l2Ey);
        }
        
        if (s3){
            ofSetColor(200,100,200,alp );
            ofLine(i*l3Sx,l3Sy,l3Ex,i*l3Ey);
            }
        
        if (s4){
            ofSetColor(60,100,20,alp );
            ofLine(i*l3Sx,600-l3Sy,l3Ex,600-(i*l3Ey));}
        
        lSy=20;
        lEx=20;
        l2Sy=20;
        l2Ex=20;
        l3Sx=20;
        l3Ey=20;
        
        ofPopMatrix();
    }
    }else{
    
    
    
    
    for (int i=0; i<600; i++) {
        
        if (s1){
            ofSetColor(100,150,200,alp );
          ofLine(lSx,i*lSy,i*lEx,lEy);
        }
        
        if (s2){
            ofSetColor(150,200,100,alp );
           ofLine(600-l2Sx,i*l2Sy,600-(i*l2Ex),l2Ey);
        }
       
        if (s3){
            ofSetColor(200,100,200,alp );
            ofLine(i*l3Sx,l3Sy,l3Ex,i*l3Ey);
        }
        
        if (s4){
            ofSetColor(60,100,20,alp );
            ofLine(i*l3Sx,600-l3Sy,l3Ex,600-(i*l3Ey));}
        
        lSy=20;
        lEx=20;
        l2Sy=20;
        l2Ex=20;
        l3Sx=20;
        l3Ey=20;
        
        
    }}
    
    ofSetColor(255,255,255,10 );
    ofRect(0,50,200,100);
    
    ofSetColor(0,0,0,150);
    verdana14.drawString("lines = a,s,d,f", 10, 70);
    verdana14.drawString("colors = gv,hb,jn,km", 10, 90);
    verdana14.drawString("actions = q,space", 10, 110);
    verdana14.drawString("mouse = drag", 10, 130);

if(lSx>600){
    lSx=0;}
    
    if(l2Sx<0){
        l2Sx=600;}
    
    if(l3Sy>600){
        l3Sy=0;}
    
    
   
    if (space==false){
    lSx++;
    l2Sx--;
        l3Sy++;}
    
    //lineInt++;
    
  cout << "keyPressed " << lineInt << endl;
    

    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    if (s1==true) {
        if (key == 'a'){
            s1=false;
        }
    }else{
        if (key == 'a'){
            s1=true;
        }
    }
    
    
    if (s2==true) {
        if (key == 's'){
            s2=false;
        }
    }else{
        if (key == 's'){
            s2=true;
        }
    }
    
    
    if (s3==true) {
        if (key == 'd'){
            s3=false;
        }
    }else{
        if (key == 'd'){
            s3=true;
        }
    }
    
    if (s4==true) {
        if (key == 'f'){
            s4=false;
        }
    }else{
        if (key == 'f'){
            s4=true;
        }
    }
    
    
    if(backr>255){
        backr=255;
    }
    if(backr<0){
        backr=0;
    }
    
   
        if (key == 'g'){
            backr++;
        }
    if (key == 'v'){
        backr--;
    }
    
    if (key == 'h'){
        backg++;
    }
    if (key == 'b'){
        backg--;
    }
    
    
    if (key == 'j'){
        backb++;
    }
    if (key == 'n'){
        backb--;
    }
    
    if (key == 'k'){
        alp++;
    }
    if (key == 'm'){
        alp--;
    }
    
    
    if(backr>255){
        backr=255;
    }
    if(backr<0){
        backr=0;
    }
    
    if(backg>255){
        backg=255;
    }
    if(backg<0){
        backg=0;
    }
    
    if(backb>255){
        backb=255;
    }
    if(backb<0){
        backb=0;
    }
  
    
    
    if (space==false) {
        if (key == ' '){
            space=true;
        }
    }else{
        if (key == ' '){
            space=false;
        }
    }
    
    
    if (q==false) {
        if (key == 'q'){
            q=true;
        }
    }else{
        if (key == 'q'){
            q=false;
        }
    }

}
   
   
    


//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    lSx=x;
    lEy=y;
    l2Sx=x;
    l2Ey=y;
    l3Sy=x;
    l3Ex=y;
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