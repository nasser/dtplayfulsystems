#include "testApp.h"

// write our boolean remove function
bool shouldRemove(Particle &p){
    if(p.pos.y > ofGetHeight() )return true;
    else return false;
}

void ofApp::setup(){
    ofSetFrameRate(60);
}

void ofApp::update(){
    for(int i = 0; i < particles.size(); i++){
        particles[i].update();
    }
    
    ofRemove(particles,shouldRemove);
}

void ofApp::draw(){
    
    ofTranslate( ofGetWidth()/2, ofGetHeight()/2);
    for(int i = 0; i < particles.size(); i++){
        particles[i].draw();
    }
}

void ofApp::keyPressed(int key){
    particles.push_back( Particle() );
}
