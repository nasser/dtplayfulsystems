#include "testApp.h"
#include "Person.h"

//--------------------------------------------------------------
void testApp::setup(){
    Person p;
    p.age = 9;
    p.alive = true;
    p.employed = false;
    p.name = "Sharon";
    p.major = "mfadt";
    
    cout << "There's this kid named " << p.name << "!" << endl;
    
    Person q;
    q.age = 10;
    q.alive = true;
    q.employed = true;
    p.name = "Chuck";
    q.major = "Study Studies";
    
    introduce(p, q);
    p.meet(q);
    
    p.switchMajor("foo");
}

void testApp::introduce(Person a, Person b) {
    cout << "Hey," << b.name << "here's a cool cat for you to meet." << endl;
    
    cout << "Her name is " << a.name << endl;
    
    if (a.alive == false) {
        cout << "Oh dear, " << a.name << " seems to have died." << endl;
    }
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

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
