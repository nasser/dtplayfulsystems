#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
    
    geode.loadMovie("geode.mov");
    geode.play();
    
    ofSetFrameRate(60);
    string host = Spacebrew::SPACEBREW_CLOUD; // "localhost";
    string name = "snaxx & macs capsense trial";
    string description = "It's amazing";
    
    spacebrew.addSubscribe("amebia_1_urchin", "range");// just typing "boolean" also works
    spacebrew.addSubscribe("amebia_2", "range");// just typing "boolean" also works
    spacebrew.addSubscribe("balloons", "range");// just typing "boolean" also works
    spacebrew.connect( host, name, description );
    Spacebrew::addListener(this, spacebrew);
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    geode.update(); 
    
}

//--------------------------------------------------------------
void testApp::draw(){
    geode.draw(-100, -100, ofGetWidth() +100, ofGetHeight()+100);
    
     
    
}


//--------------------------------------------------------------
void testApp::onMessage( Spacebrew::Message & m ){
    
    ///these were our incoming values coming in from the processing sketch. Name them what you want (the names must match) and then map their values to something like... attractors or ball sizes or colors (whatever!) Have fun!
    
    if ( m.name == "amebia_1_urchin" ){
        //int sliderXValue = m.valueRange();
        A1Value = ofToInt(m.value) / 1024.0 * 500;
        //cout << A1Value<< endl;
        
    }
    
    if ( m.name == "amebia_2" ){
        //int sliderXValue = m.valueRange();
        A2Value = ofToInt(m.value) / 1024.0 * 500;
        //cout << A2Value << endl;
        
    }
    
    if ( m.name == "balloons" ){
        //int sliderXValue = m.valueRange();
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
