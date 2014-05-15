

#include "testApp.h"

ofPoint testApp::pointOnLine(float t, ofPoint p1, ofPoint p2) {
    t = ofClamp(t, 0, 1);
    
    return (p2 - p1) * t + p1;
}
void testApp::burst(float size, int key){
    ofPoint from, to, circleCenter, circleCenterb;
    
    from.set(key*100+150, 600);
    to.set  (key*100+ofRandom(130,180), ofRandom(400,1000-size));
    
    float t = ofGetElapsedTimef() - ((int)ofGetElapsedTimef());
    float t1 = 0.8;
    
    t = sqrt(1 - powf(1 - t, 2));
    t1 = 1.0 - (pow(ofRandom(5.0)*(1.0-0.8), 1-0.6))/2.0;
    
    circleCenter = pointOnLine( t, from, to);
    circleCenterb = pointOnLine(t1, from, to);
    
    ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255), 150);
    ofCircle(circleCenter, ofRandom(10));
    ofCircle(circleCenter+ofRandom(20), ofRandom(20));
    ofCircle(circleCenter-ofRandom(20), ofRandom(10));
    ofCircle(circleCenterb+ofRandom(20), ofRandom(10));
    ofCircle(circleCenterb-ofRandom(25), ofRandom(15));
}




//--------------------------------------------------------------
void testApp::setup(){
    
 
	ofSetFrameRate(30);
    ofEnableAlphaBlending();


 //I tried to make a struct for the keys but there was an issue with attaching sound objects to each key. It worked for one but wouldn't for the others.
    
//    Key a0;
//    a0.sound.loadSound("sounds/68437__pinkyfinger__piano-a.wav");
//    a0.sound.setVolume(0.75f);
//    a0.sound.setMultiPlay(true);
//    keys.push_back(a0);
    
//    Key a1;
//    a1.sound.loadSound("sounds/68437__pinkyfinger__piano-b.wav");
//    a1.sound.setVolume(0.75f);
//    a1.sound.setMultiPlay(true);
//    keys.push_back(a1);
//
//    Key a2;
//    a2.sound.loadSound("sounds/68437__pinkyfinger__piano-bb.wav");
//    a2.sound.setVolume(0.75f);
//    a2.sound.setMultiPlay(true);
//    keys.push_back(a2);

    keyA.loadSound("sounds/68437__pinkyfinger__piano-a.wav");
    keyA.setVolume(0.75f);
    keyA.setMultiPlay(true);
    
    keyB.loadSound("sounds/68438__pinkyfinger__piano-b.wav");
    keyB.setVolume(0.75f);
    keyB.setMultiPlay(true);
    
    keyC.loadSound("sounds/68440__pinkyfinger__piano-c.wav");
    keyC.setVolume(0.75f);
    keyC.setMultiPlay(true);
    
    keyD.loadSound("sounds/68442__pinkyfinger__piano-d.wav");
    keyD.setVolume(0.75f);
    keyD.setMultiPlay(true);
  
    keyE.loadSound("sounds/68443__pinkyfinger__piano-e.wav");
    keyE.setVolume(0.75f);
    keyE.setMultiPlay(true);
  
    keyF.loadSound("sounds/68445__pinkyfinger__piano-f.wav");
    keyF.setVolume(0.75f);
    keyF.setMultiPlay(true);
    
    // for OSX, in your terminal type "ls /dev/tty.*" to get a list of serial devices
	ard.connect("/dev/tty.usbmodemfd121", 57600);

	ofAddListener(ard.EInitialized, this, &testApp::setupArduino);
	bSetupArduino	= false;	// flag so we setup arduino when its ready, you don't need to touch this :)
}

//--------------------------------------------------------------
void testApp::update(){
    
	updateArduino();
    //hand flip
    
    cout << ard.getAnalog(0) << endl;
    cout << ard.getAnalog(1) << endl;
//    cout << ard.getAnalog(2) << endl;
    
    
    ofSoundUpdate();


//    for (int i=0; i < 5; i++){
//        ard.getAnalog(i);
//        
//        if(ard.getAnalog(i) > 600){
//            keys[i].sound.play();
//        } else {
//        }
//    }
    for (int i=0; i<6; i++){
    ard.getAnalog(i);
    }
    
    

}
//--------------------------------------------------------------
void testApp::setupArduino(const int & version) {
	
	// remove listener because we don't need it anymore
	ofRemoveListener(ard.EInitialized, this, &testApp::setupArduino);
    
    // it is now safe to send commands to the Arduino
    bSetupArduino = true;
    
    // print firmware name and version to the console
    ofLogNotice() << ard.getFirmwareName();
    ofLogNotice() << "firmata v" << ard.getMajorFirmwareVersion() << "." << ard.getMinorFirmwareVersion();
    
}

//--------------------------------------------------------------
void testApp::updateArduino(){
    
	ard.update();
	
    
    
}





//--------------------------------------------------------------
void testApp::draw(){

	 ofBackground(0,0,0,50);
    if(ard.getAnalog(0) > 200){
        burst(ard.getAnalog(0), 0);
        keyA.play();
        
    } else{
        keyA.stop();
        
    }
    if(ard.getAnalog(1) > 200){
        keyB.play();
        burst(ard.getAnalog(1), 1);
    } else {
        keyB.stop();
    }
    if(ard.getAnalog(2) > 200){
        keyC.play();
        burst(ard.getAnalog(2), 2);
    } else {
        keyC.stop();
    }
    
    if(ard.getAnalog(3) > 200){
        keyD.play();
        burst(ard.getAnalog(3), 3);
    } else {
        keyD.stop();
    }
    if(ard.getAnalog(4) > 200){
        keyE.play();
        burst(ard.getAnalog(4), 4);
    } else {
        keyE.stop();
    }
    if(ard.getAnalog(5) > 200){
        keyF.play();
        burst(ard.getAnalog(5), 5);
    } else {
        keyF.stop();
    }
    

    
    
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
    
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