#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
    
    myPlayer.loadMovie("movies/groundswell.mp4");
    myPlayer.play();
    

    ofSetFrameRate(30);
    ofEnableSmoothing();
    ofNoFill();
    
    //flower.loadImage("images/flowers.png");
    flower.resize(flower.width / 4, flower.height / 4);
    


}

//--------------------------------------------------------------
void testApp::update(){
    
    myPlayer.update(); // get all the new frames
    
   // makeShape.update();
    
    int x = 20; 
   
   for(int i=0; i<NBALLS; i++)
	{
        
	makeShape[i].update();
	
    }
    
    
//makeShape[1].update();
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    

    myPlayer.draw(0, 0);
    
   // flower.draw(ofGetWidth()/2, ofGetHeight()/2);
    
    
//    
   // if (flip == true) {
        
        
        
   for(int i=0; i<NBALLS; i++)
	{
        makeShape[i].draw();

    }
    
   //makeShape.draw();
    
    
    
    
    ofCircle(mouseX +10,  mouseY+10, 10);
    ofCircle(mouseX,  mouseY, 20);
    ofCircle(mouseX,  mouseY, 30);
    ofCircle(mouseX-10,  mouseY-10, 40);



 
}


//--------------------------------------------------------------
void testApp::keyPressed(int key){
//    
////    if(key === "a"||"A"){
////        
////        drawCircles()
////        
////    }
//
//    
  //flip = true;
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
  // flip = false;

}
//
////--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
//
}
//
////--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
//
}
//
////--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
//
}
//
////--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
//
}
//
////--------------------------------------------------------------
void testApp::windowResized(int w, int h){
//
}
//
////--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
//
}
//
////--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
//
}
