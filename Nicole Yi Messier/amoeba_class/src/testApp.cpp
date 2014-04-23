#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    for(int i=0; i<10; i++){
        Meeba meebOne;
        meebOne.radius = 50;
        meebOne.density = 100;
        meebOne.color.set(ofRandom(255), ofRandom(255), ofRandom(255));
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
            cout << "speed before [" << i << "]: " << rainbow[i].speed << endl;
            rainbow[i].speed = -rainbow[i].speed;
            cout << "speed after: " << i << "]: " << rainbow[i].speed << endl;
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
    }
    
    ofPopMatrix();
    easyCam.end();
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
