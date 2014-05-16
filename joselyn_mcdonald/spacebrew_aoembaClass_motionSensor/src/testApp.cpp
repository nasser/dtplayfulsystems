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
    string name = "snaxx & macs aoembaClass trial";
    string description = "It's amazing";
    
    spacebrew.addSubscribe("meebVal1", "range");// just typing "boolean" also works
    spacebrew.addSubscribe("meebVal2", "range");
    spacebrew.addSubscribe("meebVal3", "range");
    spacebrew.addSubscribe("meebVal4", "range");
    spacebrew.addSubscribe("meebVal5", "range");
    spacebrew.addSubscribe("meebVal6", "range");
    spacebrew.addSubscribe("meebVal7", "range");
    spacebrew.addSubscribe("motionSensor", "boolean");
    spacebrew.connect( host, name, description );
    Spacebrew::addListener(this, spacebrew);
    
    for(int i=0; i<10; i++){
        Meeba meebOne;
        meebOne.radius = 50;
        meebOne.density = 100;
        meebOne.color.set(255, 255, 255);
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
    
    geode_white.update();
    geode.update();
    gem.update();
    
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
    
    ofBackground(255, 255, 255);
    
    ofSetColor(255, 255, 255, 255);
    geode.draw(-50, -200, ofGetWidth()+200, ofGetHeight()+300);
    
    
    ofSetColor(255, 255, 255, 100);
    gem.draw(-50, -200, ofGetWidth()+200, ofGetHeight()+300);
    
    easyCam.begin();
    ofPushMatrix();
    ofTranslate(-ofGetWidth(), -ofGetHeight());
    
    
    for(int i=0; i<rainbow.size(); i++){
        if(motionSensor == true || (motionSensor == false && timer < timeAmount) ) {
        
            rainbow[i].drawMeebs();
        
            if (meebVal1 > threshold ){
                rainbow[i].color.set(255, 0, 255); //pink
            }
            
            else if ( meebVal2 > threshold) {
                rainbow[i].color.set(0,0,255); //blue
               
            }
            
             else if ( meebVal3 > threshold) {
                rainbow[i].color.set(138,43,226); //blue voilet
              
            }
            
            //else if ( meebVal4 > threshold) {
                //rainbow[i].color.set(138,43,226);
            //}
            
            else {
                rainbow[i].color.set(111, 0, 255, 25); //turq
            }
            
            if(meebVal5 > threshold){
                rainbow[i].radius = 75;
            }
            if (meebVal6 > threshold){
                rainbow[i].radius = 25;
            }
            if (meebVal7 > threshold){
                rainbow[i].radius = 100;
            }
            
        }
        
        else if (motionSensor == false && timer > timeAmount) {
            rainbow[i].color.set(255, 255, 255);
        }
        
        //rainbow[i].color.set(138,43,226);

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
        
        //meebVal3, meebVal2, meebVal4 = 0;
        
    }
    
    if ( m.name == "meebVal2" ){
        meebVal2 = ofToInt(m.value);
        cout << "meebVal2: " << meebVal2 << endl;
        
        //meebVal1, meebVal3, meebVal4 = 0;
        
    }
    
    if ( m.name == "meebVal3" ){
        //int sliderXValue = m.valueRange();
        meebVal3 = ofToInt(m.value) ;
        cout << "meebVal3: " << meebVal3 << endl;
        
        //meebVal1, meebVal2, meebVal4 = 0;
        
    }
    
    if( m.name == "meebVal4"){
         meebVal4 = ofToInt(m.value);
        cout << "meebVal4: " << meebVal4 << endl;
        
        //meebVal1, meebVal2, meebVal3 = 0;
    }
    
    if( m.name == "meebVal5"){
        meebVal5 = ofToInt(m.value);
        cout << "meebVal5: " << meebVal5 << endl;
    }
    
    if( m.name == "meebVal6"){
        meebVal6 = ofToInt(m.value);
        cout << "meebVal6: " << meebVal6 << endl;
    }
    
    if( m.name == "meebVal7"){
        meebVal7 = ofToInt(m.value);
    }
    
    
    
    if( m.name == "motionSensor"){
        
        //cout << "motionSensor: " << m.value << endl;
        
        if(m.value == "true"){
            motionSensor = true;
            cout << "moving" << endl;
            timerTrue = (int)ofGetElapsedTimef();
        } else if (m.value == "false") {
            cout << "notMoving" << endl;
            motionSensor = false;
            timer = (int)ofGetElapsedTimef()-timerTrue;
            cout << timer << endl;
        }
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
