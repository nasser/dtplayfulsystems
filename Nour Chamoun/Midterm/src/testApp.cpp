#include "testApp.h"
//create a vector for the object

//Created By Nour Chamoun


//--------------------------------------------------------------
void testApp::setup(){
    
    
    
	capture = false;
	bFill	= false;


    ofPoint myPoint;

    
    
            for(int i = 0; i < 2; i++){
            myPoint.x = ofGetWidth()/3;
            myPoint.y = ofGetHeight()/3;
            myPoints.push_back(myPoint);
            }

}

//--------------------------------------------------------------
void testApp::update(){
    
	ofBackground(30);

    


}

//--------------------------------------------------------------
void testApp::draw(){
    

	if(capture){
		output.beginEPS("test.ps");
	}


	if(bFill)output.fill();
	else output.noFill();

    
    
	output.setColor(0xd4d4d4);
	output.beginShape();
    

		
    
    int numSteps = ( (float)mouseX / ofGetWidth() )* 10.0;
		numSteps = MAX(3, numSteps);
   

    for (int i = 0; i < 100; i++){
		ofSetColor((int)ofRandom(0,255),(int)ofRandom(0,255),(int)ofRandom(0,255));
	}
    
		float step		= TWO_PI / (numSteps);
		float angle		= 0.0;
		float cenX		= ofGetWidth()/2;
		float cenY		= ofGetHeight()/2;
        float cen2X		= 100;
        float cen2Y		= 20;
        float radius	= 230.0;
		float scale     = 1.0 + 0.6 * sin(ofGetElapsedTimef());
    

    
    for(int j = 0; j < myPoints.size(); j++){
        
         for(int i = 0; i < numSteps; i++){
             
             
             float rx = cenX + sin(angle) * radius;
             float ry = cenY + cos(angle) * radius;

             
             if(i == 0){
                 output.polyVertex(rx, ry);
             }
             
             float rx2 = cenX + sin(angle+step) * radius;
             float ry2 = cenY + cos(angle+step) * radius;

             
  
             float cx = cenX + sin(angle + step*2) * radius * scale;
             float cy = cenY + cos(angle + step*2) * radius * scale;

             
             output.bezierVertex(cx, cy, cx, cy, rx2, ry2);

             
             angle += step;
         }
         
         

	output.endShape(true);
     }
    


}


//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if(key == ' '){
		capture = true;
	}else if(key =='f'){
		bFill = !bFill;
	}
    
    if(key == 'g') ofToggleFullscreen();

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

	//we add a new point to our line
	pts.push_back(ofPoint());
	int last = pts.size()-1;

	pts[last].x = x;
	pts[last].y = y;

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	pts.clear();

	//lets store the first point of the line
	pts.push_back(ofPoint());
	pts[0].x = x;
	pts[0].y = y;

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
