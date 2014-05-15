#include "testApp.h"
#include "Person.h"

//--------------------------------------------------------------
void testApp::setup(){
    Person p;
    p.age = 8;
    p.alive = true;
    p.employed = false;
    p.name = "some kid";
    p.major = "mfadt";


    cout << "There's this kid named " << p.name << "!" <<  endl;

    Person q;

    q.name = "other name";
    q.age = 90210;

    introduce(&p, &q);


    p.meet(q);
    p.switchMajor("liberal arts");
}

//--------------------------------------------------------------

void testApp::introduce(Person* a, Person* b){
    cout << "Hey, " << b->name << ", here's a cool cat for you to meet." << endl;
    cout << "Their name is " << a->name << endl;

    if (a->alive == false){
        cout << a->alive << " be dead..." << endl;
    }


}


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
