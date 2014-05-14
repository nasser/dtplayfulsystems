#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetWindowTitle("Randeo");
    ofSetFrameRate(24);
    
    //setting variables
    
    menuDisplay = true;
    fullscreen = false;
    mode = 0;
    wiggle = 0.01;
    act = 0;
    
    //modes
    
    currentMode = 1;
    playbackModeLength = 7;
    
    playbackMode[0] = "NORMAL";
    playbackMode[1] = "JITTER I";
    playbackMode[2] = "JITTER II";
    playbackMode[3] = "JITTER III";
    playbackMode[4] = "FRACTION I";
    playbackMode[5] = "FRACTION II";
    playbackMode[6] = "FRACTION III";
    
    //loading typefaces
    
    CousineRegular.loadFont("Cousine-Regular.ttf", 8);
    
    //loading images
    
    menuImg.loadImage("menuImg.jpg");
    
    //loading videos
    
    video.loadMovie("video.mp4");
    sound.loadSound("audio.mp3");
    video.setLoopState(OF_LOOP_NORMAL);
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    if (!menuDisplay){
    video.update();
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    if (menuDisplay) {
        drawMenu();
    } else {
        drawVideo();
    }

}

//--

void testApp::drawMenu() {
    
    // pause the video
    
    video.setPaused(true);
    
    // draw the menu
    
    menuImg.draw(0,0,ofGetWidth(), ofGetHeight());
    
    ofSetColor(98,90,229);
    string menuTitle;
    menuTitle += "A PLAYBACK RANDOMIZER FOR DYNAMIC VIDEO INSTALLATIONS";
    string menuByLine;
    menuByLine += "Evander Batson / Parsons MFADT \n";
    string menuControls;
    menuControls += "CONTROLS: \n\n";
    menuControls += "(D) toggle Display video / Display menu \n\n";
    menuControls += "(F) toggle Fullscreen \n\n";
    menuControls += "(M) toggle Mode \n\n";
    menuControls += "(A) Advance playback head \n\n";
    menuControls += "(R) Reset \n\n";
    menuControls += "(Q) Quit \n\n";
    string project;
    project += "PROJECT:  \n";
    project += "ARTIST:   \n\n";
    project += "VIDEO:  ..bin/data/video.mp4 \n";
    project += "SOUND:  ..bin/data/audio.mp3 \n";
    project += "MODE:    "+ playbackMode[currentMode] +"\n";
    
    int menuPosX = ofGetWidth()*.2;
    int menuPosY = ofGetHeight()*.22;
    
    CousineRegular.drawString(menuTitle, menuPosX, menuPosY);
    CousineRegular.drawString(menuByLine, menuPosX, menuPosY+40);
    CousineRegular.drawString(menuControls, menuPosX, menuPosY+60);
    CousineRegular.drawString(project, menuPosX, menuPosY+220);
    ofSetColor(255);
    
}

// modes:
// 0 = NORMAL
// 1 = JITTER I
// 2 = JITTER II
// 3 = JITTER III
// 4 = FRACTION I


void testApp::drawVideo() {
    
    if (currentMode == 1) {
        jitter(75);
    }
    
    if (currentMode == 2) {
        jitter(30);
    }
    
    if (currentMode == 3) {
        jitter(30);
    }
    
    if (currentMode == 4) {
        fraction(.25,50);
    }
    
    if (currentMode == 5) {
        fraction(.33,40);
    }
    
    if (currentMode == 6) {
        fraction(.15,20);
    }
    
    video.play();
    video.draw(0,0,ofGetWidth(), ofGetHeight());
    
    
}

//--

void testApp::jitter(int cutChance) {
    
    int r = (ofRandom(0,100));
    
    if (r > cutChance) {
        float randomPlace = ((ofRandom(0,100))*0.01);
        
        cout << "Video position set to: "<< randomPlace * 100 << "%"<< endl;
        
        video.setPosition(randomPlace);
    }
    
}

//--

void testApp::fraction(float fraction, int cutChance) {
    
    if ((video.getPosition() > fraction) && (act==0)) {
        
        int r = (ofRandom(0,100));
            cout << "r is: " << r << endl;
        
        if (r > cutChance) {
            cout << "CUT! " << endl;
            video.setPosition(fraction*2);
        }
        
        act=1;
            cout << "Act set to: " << act << endl;
    }
    
    if ((video.getPosition() == 1)) {
        video.setPosition(0);
        act = 0;
            cout << "Act set to: " << act << endl;
    }
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    if (key == 'd') {
        if (menuDisplay) {
            sound.play();
        } else {
            sound.stop();
        }
        
        menuDisplay = !menuDisplay;
        cout << "Installation display toggled" << endl;
    }
    
    if (key == 'r') {
        video.stop();
        video.setPosition(0);
        menuDisplay = true;
        act = 0;
        }
    
    if (key == 'f') {
        ofToggleFullscreen();
        fullscreen=!fullscreen;
        
        if (fullscreen) {
            ofHideCursor();
        } else {
            ofShowCursor();
        }
        
        cout << "fullscreen toggled" << endl;
    }
    
    if (key == 'a') {
        video.setPosition(video.getPosition() + 0.1);
    }
    
    if (key == 'm') {
        
        if (currentMode < playbackModeLength-1) {
            currentMode++;
        } else {
            currentMode = 0;
        }
        
        cout << playbackMode[currentMode] << endl;
        
    }
    
    if (key == 'q') {
        
        video.stop();
        ofExit();
        
    }

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
