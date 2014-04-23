#include "testApp.h"
#include "person.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    Person p;
    p.age = 9;
    p.alive = true;
    p.employed = false;
    p.name = "Herp";
    p.major;
    

    Person q;
    q.name = "Derp";
    
    cout << "There;s these kids named " << p.name << " and " << q.name << "!" << endl;

    introduce(q, p);
    p.meet(q);
    p.switchMajor("Biology");
}

//--------------------------------------------------------------
void testApp::introduce(Person a, Person b){
    cout << "Hey! "<< a.name << " is cool" << endl;
    cout << "Hey!"<< b.name << " is cool too" << endl;

    
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
