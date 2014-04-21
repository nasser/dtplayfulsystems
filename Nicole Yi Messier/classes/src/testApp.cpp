#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
    
    Person p;
    p.age = 8;
    p.alive = true;
    p.employed = false;
    p.name = "some kid";
    p.major = "mfadt";
    
    Person q;
    q.name = "other name";
    q.age = 9102;
    q.alive = false;
    
    cout << "There's this kid named" << p.name << "!" << endl;
    
    introduce (p, q);
    p.meet(q);
    
}

//--------------------------------------------------------------
void testApp::introduce(Person a, Person b){
    cout << "Hey, " << b.name  << ", here's a cool cat for you to meet." << endl;
    
    cout<< "His/her name is " << a.name << endl;
    
    if(a.alive ==false){
        cout << "Oh dear. " << a.name << "seems to hae died." << endl;
    }
}

//--------------------------------------------------------------
void testApp::update(){
    me.sneeze();
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
