#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    
    string host = Spacebrew::SPACEBREW_CLOUD; // "localhost";
    string name = "snaxx & macs capsense trial";
    string description = "It's amazing";
    
    spacebrew.addSubscribe("meebVal1", "range");// just typing "boolean" also works
    spacebrew.addSubscribe("meebVal2", "range");// just typing "boolean" also works
    spacebrew.addSubscribe("meebVal3", "range");// just typing "boolean" also works
    spacebrew.connect( host, name, description );
    Spacebrew::addListener(this, spacebrew);
    
    for(int i=0; i<10; i++){
        Meeba meebOne;
        meebOne.radius = 50;
        meebOne.density = 100;
        meebOne.color.set(0, 255, 255);
        meebOne.shift.set(ofRandomWidth(), ofRandomHeight());
        
        meebOne.speed = ofRandom(-2, 2);
        
        if(meebOne.speed == 0){
            meebOne.speed = 2;
        }
        
        rainbow.push_back(meebOne);
    }
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    for(int i=0; i <rainbow.size(); i++){
        rainbow[i].moveMeebs();
        
        if(rainbow[i].shift.y > ofGetHeight() || rainbow[i].shift.y < 0 ){
            //cout << "speed before [" << i << "]: " << rainbow[i].speed << endl;
            rainbow[i].speed = -rainbow[i].speed;
            //cout << "speed after: " << i << "]: " << rainbow[i].speed << endl;
        }
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    //cout << ((int)ofGetElapsedTimef()) % 5 << endl;
    //cout << ((int)ofGetElapsedTimef() % 5 == 0) << endl;
    
    ofBackground(0, 0, 0);
    
    easyCam.begin();
    ofPushMatrix();
    ofTranslate(-ofGetWidth(), -ofGetHeight());
    
    
    for(int i=0; i<rainbow.size(); i++){
        rainbow[i].drawMeebs();
        
        if (meebVal1 > 100 || meebVal2 > 100 || meebVal3 >100){
            rainbow[i].color.set(255, 0, 255);
        } else {
            rainbow[i].color.set(0, 255, 255);
        }

    }
    

    
    ofPopMatrix();
    easyCam.end();
}

//--------------------------------------------------------------
void testApp::onMessage( Spacebrew::Message & m ){
    
    ///these were our incoming values coming in from the processing sketch. Name them what you want (the names must match) and then map their values to something like... attractors or ball sizes or colors (whatever!) Have fun!
    
    if ( m.name == "meebVal1" ){
        //int sliderXValue = m.valueRange();
        meebVal1 = ofToInt(m.value);
        cout << "meebVal1: " << meebVal1<< endl;
        
    }
    
    if ( m.name == "meebVal2" ){
        //int sliderXValue = m.valueRange();
        meebVal2 = ofToInt(m.value);
        //cout << "meebVal2: " << meebVal2 << endl;
        
    }
    
    if ( m.name == "meebVal3" ){
        //int sliderXValue = m.valueRange();
        meebVal3 = ofToInt(m.value) ;
        //cout << "meebValr: " << meebVal3 << endl;
        
        
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
