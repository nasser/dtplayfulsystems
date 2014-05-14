#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	manualTarget = ofPoint(ofGetWidth()/2, ofGetHeight()/2);
	for (int i = 0; i < 200; ++i){
		points.push_back(ofPoint(ofRandomWidth(), ofRandomHeight()));
		angles.push_back(0);
		speed.push_back(0);
	}
}

//--------------------------------------------------------------
void testApp::update(){
	manualTarget.x = mouseX;
	manualTarget.y = mouseY;

	//cohesion - move towards average position
	/*for (int i = 0; i < points.size(); ++i){
		ofPoint neighborAverage = ofPoint(0, 0);
		int neighborCount = 0;

		//find neighbors
		for (int j = 0; j < points.size(); ++j){
			if(points[i].distance(points[j]) <= 300){
				//we know points[j] is a neighbor
				//cout<<"bam"<<endl;
				neighborAverage += points[j];
				neighborCount++;

			}
		}
		//calculate neighbor average point
		neighborAverage /= neighborCount;

		//move towards neighbor average point
		points[i].interpolate(neighborAverage, 0.01);
	}*/

		//steer
		for (int i = 0; i < angles.size(); ++i){
			angles[i] += ofSignedNoise(ofGetElapsedTimef(), i) * 0.1;
		}
		//speed
		for (int i = 0; i < speed.size(); ++i){
			speed[i] += ofRandomf();
		}
		//move
		for (int i = 0; i < points.size(); ++i){
			points[i].x += cos(angles[i]) * speed[i];
			points[i].y += sin(angles[i]) * speed[i];
		}
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(0);
	ofSetColor(255);
	for (int i = 0; i < points.size(); ++i){ //points.size() allows the dynamism
		ofCircle(points[i], 2);
		ofLine(points[i], points[i] + ofPoint(cos(angles[i])*10, sin(angles[i])*10));
	}
	//ofSetColor(50, 240, 250);
	//ofCircle(manualTarget, 10);
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
	points.push_back(ofPoint(ofRandomWidth(), ofRandomHeight()));

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
