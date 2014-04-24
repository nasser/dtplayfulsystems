#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    Person p("some kid", 8);
    p.alive = false;
    p.employed = false;
    p.major = "mfadt";
        
    Person q("other name");
    q.alive = false;
    q.employed = false;
    q.major = "...";
    
    r = new Person("nameless");
    cout << r->name << endl;
    r->age = 100;
    
    r->giggleNervously();
    r->giggleNervously("ohno");
    r->giggleNervously("ohno", 100);
    
    int a;
    a = 0;
    
    cout << &r << endl;
    cout << &r << endl;
    
//    cout << "There's this kid named " << p.name << "!" << endl;
    
// cout << p.name << endl;
    
//    introduce(&p, &q);
    
//    cout << p.name << endl;
    
//    p.meet(q);
    
//    me.switchMajor("foo");
}

void testApp::introduce(Person* a, Person* b) {
    a->name = "MUTATED";
    
    cout << "Hey, " << b->name << ", here's a cool cat for you to meet." << endl;
    cout << "His/her name is " << a->name << endl;

    if(a->alive == false) {
        cout << "Oh dear. " << a->name << " seems to have died." << endl;
    }
}

//--------------------------------------------------------------
void testApp::update(){
    r->giggleNervously();
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
