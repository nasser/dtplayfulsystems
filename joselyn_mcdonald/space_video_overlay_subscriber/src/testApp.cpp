#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetFrameRate(60);


    gem.loadMovie("geode.mov");
    gem.play();
    
    geode.loadMovie("square_geode.mov");
    geode.play();
    
    geode_white.loadMovie("geode_white.mov");
    geode_white.play();
    
    
    
    
    string host = Spacebrew::SPACEBREW_CLOUD; // "localhost";
    string name = "snaxx & macs capsense trial"; //name it something you'll recognize
    string description = "It's amazing"; 
    
    spacebrew.addSubscribe("amebia_1_urchin", "range");// just typing "boolean" also works
    spacebrew.addSubscribe("amebia_2", "range");// just typing "boolean" also works
    spacebrew.addSubscribe("balloons", "range");// just typing "boolean" also works
    spacebrew.connect( host, name, description );
    Spacebrew::addListener(this, spacebrew);
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    gem.update();
    geode.update();
    geode_white.update();

    
}

//--------------------------------------------------------------
void testApp::draw(){
    

    
    ///___options for video opacity shifts------
    
    
    if (A2Value > 100){
        
        ofSetColor(255, 255, 255, 255);
        geode.draw(-50, -200, ofGetWidth()+200, ofGetHeight()+300);
        
        ofSetColor(255, 255, 255, 100);
        geode_white.draw(-50, -200, ofGetWidth()+200, ofGetHeight()+300);


        
    }
    
    //cout<<A2Value<<endl;
    
    if (A1Value > 140){
        
        ofSetColor(255, 255, 255, 255);
        geode.draw(-50, -200, ofGetWidth()+200, ofGetHeight()+300);
        
        ofSetColor(255, 255, 255, 100);
        gem.draw(-50, -200, ofGetWidth()+200, ofGetHeight()+300);
        
   
    }
    
    //cout<<A1Value<<endl;
    
    if(balloonValue > 20){
        
        ofSetColor(255, 255, 255, 255);
        geode.draw(-50, -200, ofGetWidth()+200, ofGetHeight()+300);
        
        
        ofSetColor(255, 255, 255, 100);
        gem.draw(-50, -200, ofGetWidth()+200, ofGetHeight()+300);
        
        //cout<<balloonValue<<endl;

        
    } else {
        
        
        ofSetColor(255, 255, 255, 255);
        geode.draw(-50, -200, ofGetWidth()+200, ofGetHeight()+300);
        

        
    }
    

}


//--------------------------------------------------------------
void testApp::onMessage( Spacebrew::Message & m ){
    
    ///these were our incoming values coming in from the processing sketch. Name them what you want (the names must match) and then map their values to something like... attractors or ball sizes or colors (whatever!) Have fun!
    
    if ( m.name == "amebia_1_urchin" ){
        A1Value = ofToInt(m.value) / 1024.0 * 500;
        //cout << A1Value<< endl;
        
    }
    
    if ( m.name == "amebia_2" ){
        A2Value = ofToInt(m.value) / 1024.0 * 500;
        //cout << A2Value << endl;
        
    }
    
    if ( m.name == "balloons" ){
        balloonValue = ofToInt(m.value) / 1024.0 * 500;
        //cout << balloonValue << endl;
        
        
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
