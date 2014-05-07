#include "testApp.h"
//Adding at cpp s safe not to include in different parts.
//#include "Person.h"


//--------------------------------------------------------------
void testApp::setup(){
// 1
    Person p;
    p.age = 8;
    p.alive = true;
    p.employed = false;
    p.name = "Some Kid";

// 2
    Person q;
    p.age = 20;
    p.alive = true;
    p.employed = false;
    p.name = "Quico";
    
    
    cout <<  "Name: " << p.name << endl;
    
    
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
     
}


//--------------------------------------------------------------
//R
void introduce(Person a, Person b) {
    if(a.alive == false) {
        cout << a.name << "Looks dead" << endl;
    
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
