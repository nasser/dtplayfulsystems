#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
   
   // Mode 1 - MENU
    
    mode==1;

    rectanglex  =ofGetWidth()/2;
    rectangley  =ofGetHeight()/2;
    rectanglewidth   =50;
    rectangleheight  =50;
   
    
    // Mode 2 - GAME
    mode==2;
    
    ofBackground(0, 0, 0);
    ofSetBackgroundAuto(true);
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    player1x=145;
    player1y=ofGetHeight()/2;
    player1height=35;
    
    player2x=ofGetWidth()-145;
    player2y=ofGetHeight()/2;
    player2height=35;
    
    ballx=260;
    bally=ofGetHeight()/2;
    radius=2.5;
    
    xspeed = 2;
    yspeed = 2;
    
   // Mode 3 - WIN
    mode==3;
    
   //Mode 4 - GAME OVER
    
    mode==4;
    
    mode=1;

    
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    halfTime = ofGetElapsedTimef();
    
// mode1 - menu
    
    
    if (mode==1) {

        float toprectangle=ofGetHeight()/2-25;
        float bottomrectangle=ofGetHeight()/2+25;
        float leftrectangle=ofGetWidth()/2-25;
        float rightrectangle=ofGetWidth()/2+25;
    
        float targety001;
        
        
        if (mouseY>toprectangle && mouseY<bottomrectangle && mouseX>leftrectangle && mouseX<rightrectangle){
            
            mode=2;
            
        }
        
        else{
            mode=1;
        }
   
   
    }
    
    
 //mode2 - game
    
    
    if (mode==2){
        
    
    // Player 1
    
    float topborder=ofGetHeight()/2 - 220;
    float bottomborder=ofGetHeight()/2 +220;
    
    float targety1;
    
    if(mouseY<topborder) {
        targety1=topborder+player1height/2;
    
    }
    else if(mouseY>bottomborder){
        targety1=bottomborder-player1height/2;
    
    }
 
    else{
        targety1=mouseY;
        
    }
    
    
    player1y=player1y+((targety1-player1y)*0.1);
    
    
    

    
    //Ball
    
  
    float targetball;
    
    if (bally<topborder) {
        yspeed=yspeed*(-1);
    }
    
    else if (bally>bottomborder){
        yspeed=yspeed*(-1);
    }
    
   /*
    bally=bally+ yspeed;
    ballx=ballx+xspeed;
    */
      
   
    
    if (ballx<player1x && bally>(player1y-player1height/2) && bally<(player1y+player1height/2)){
        
        cout << "Player 1 logic" << endl;
        xspeed=xspeed*(-1);
    }
    
    else if (ballx>player2x && bally>(player2y-player2height/2) && bally<(player2y+player2height/2)){
        
        xspeed=xspeed*(-1);
        
        
    }
    
    bally=bally+ yspeed;
    ballx=ballx+xspeed;
    

    
  

    
    //Player 2
    
    float targety2;
    
    if(bally<topborder) {
        targety2=topborder+player2height/2;
        
    }
    
    else if(bally>bottomborder){
        targety2=bottomborder-player2height/2;
        
    }
    
    else {
        targety2=bally;
        
    }
    
    
    player2y=player2y+((targety2-player2y)*0.6);
    
    
    }


 //mode3 - end
    
        
    if (ballx<player1x-60) {
        mode=3;
    }
    
    else if(ballx>player2x+60){
        mode=4;
    }
        
    
}
    

//--------------------------------------------------------------

void testApp::draw(){
            
   
    // MODE1 - MENU
    
    
    if (mode==1){
        
        string title0 = "WELCOME TO MAIN MENU";
        
        ofDrawBitmapString(title0, ofGetWidth()/2 - (title0.length()*8)/2, 100);
        
        
        string title00 = "SLIDE OVER BOX TO START PONG";
        
        ofDrawBitmapString(title00, ofGetWidth()/2 - (title00.length()*8)/2, ofGetHeight()/2-60);
        
        ofRect(rectanglex, rectangley, rectanglewidth, rectangleheight);
        
    }
    
    
    
    
    // MODE2 - GAME
    
    else if (mode==2){
        
    //Type
        
    ofSetColor(255, 255, 255);
        
    
    string title = "Creative Coding";
    
    ofDrawBitmapString(title, ofGetWidth()/2 - (title.length()*8)/2, 30);
    
    string title1 = "Final Project";
    
    ofDrawBitmapString(title1 ,ofGetWidth()/2 - (title1.length()*8)/2, 45);
    
    string title2 = "PONG";
    
    ofDrawBitmapString(title2, ofGetWidth()/2- (title2.length()*8)/2, 60);
    
    string title3 = "Sandrofredericoz";
    
    ofDrawBitmapString(title3,ofGetWidth()/2-(title3.length()*8)/2, 75);
        
    
    
    //Court - Aussenlinien
    ofSetColor(255,255,255);
    
    ofPoint p1, p2;
    
    p1.set(100, ofGetHeight()/2 - 220);
    ofCircle(p1, 2);
   
    p2.set(100, ofGetHeight()/2 + 220);
    ofCircle(p2, 2);
    
    
    ofLine(p1, p2);
    
    
    ofPoint p3, p4;
    
    p3.set(100, ofGetHeight()/2 + 220);
    ofCircle(p2, 2);
    
    p4.set(ofGetWidth()-100, ofGetHeight()/2 + 220);
    ofCircle(p4, 2);
    
    
    ofLine(p3, p4);
   
    
    ofPoint p5, p6;
    
    p5.set(ofGetWidth()-100, ofGetHeight()/2 + 220);
    ofCircle(p4, 2);
    
    p6.set(ofGetWidth()-100, ofGetHeight()/2 - 220);
    ofCircle(p6, 2);
    
    ofLine(p5, p6);
    
    
    ofPoint p7, p8;
    
    p7.set(ofGetWidth()-100, ofGetHeight()/2 - 220);
    ofCircle(p6, 2);
    
    p8.set(100, ofGetHeight()/2 - 220);
    ofCircle(p1, 2);

     ofLine(p7, p8);
    
    // net
    
    ofSetColor(0, 255, 255);
    ofPoint p9, p10;
    
    p9.set(ofGetWidth()/2+1, ofGetHeight()/2 - 220);
    ofCircle(p9, 4);
    
    p10.set(ofGetWidth()/2+1, ofGetHeight()/2 + 220);
    ofCircle(p10, 4);
     
    
    ofLine(p9, p10);
     
     ofPoint p9x, p10y;
     
     p9x.set(ofGetWidth()/2-1, ofGetHeight()/2 - 220);
     ofCircle(p9x, 4);
     
     p10y.set(ofGetWidth()/2-1, ofGetHeight()/2 + 220);
     ofCircle(p10y, 4);
     
     
     ofLine(p9x, p10y);
    
    
    // court - Innere linien -horizontal
   
     ofSetColor(255, 255, 255);
     
    ofPoint p11, p12;
    
    p11.set(100, ofGetHeight()/2 - 150);
    
    p12.set(ofGetWidth()-100, ofGetHeight()/2 - 150);
    
    ofLine(p11, p12);
    
    
    ofPoint p13, p14;
    
    p13.set(100, ofGetHeight()/2 + 150);
    
    p14.set(ofGetWidth()-100, ofGetHeight()/2 + 150);
    
    ofLine(p13, p14);
     
    
     ofPoint p21, p22;
     
     p21.set(250, ofGetHeight()/2);
     
     p22.set(ofGetWidth()-250, ofGetHeight()/2);
     
     ofLine(p21, p22);
    
   
    // court - Innere Linien - Vertical
    
    ofPoint p15, p16;
    
    p15.set(250, ofGetHeight()/2 + 150);
    
    p16.set(250, ofGetHeight()/2 - 150);
    
    ofLine(p15, p16);
    
    
    
    ofPoint p17, p18;
    
    p17.set(ofGetWidth()-250, ofGetHeight()/2 + 150);
    
    p18.set(ofGetWidth()-250, ofGetHeight()/2 - 150);
    
    ofLine(p17, p18);
     
// Player1 Paddle
     ofRect(player1x, player1y, 3, player1height);
     
//Player2 Paddle
     ofRect(player2x, player2y, 3, player2height);
     
//Ball
     ofSetColor(255, 237, 0);
     ofCircle(ballx, bally, radius);
    
    }
    

    
    
    
// Mode 3 - END

    
else if (mode==3){
    
    string title001 = "GAME OVER!";
    
    ofDrawBitmapString(title001, ofGetWidth()/2 - (title001.length()*8)/2, ofGetHeight()/2-60);

}
    
else if (mode==4){
    
    string title002 = "YOU WIN!";
    
    ofDrawBitmapString(title002, ofGetWidth()/2 - (title002.length()*8)/2, ofGetHeight()/2-60);
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
