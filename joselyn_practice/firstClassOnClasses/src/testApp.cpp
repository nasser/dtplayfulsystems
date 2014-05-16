#include "testApp.h"
#include "person.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    
    Person p("some kid");
    p.age = 8;
    p.alive = true;
    p.employed = false;
    
    
    p.name = "some kid";
    
    Person q("other name");
    
    Person(); 
    
    q.name = "other name";
    q.age = 9102;
    
    Person r;
    cout<<r.name<<endl; 

    
//    cout<< "There's this kid name" << p.name<< "!"<< endl ;
//    
//    introduce(p, q);
//
//    p.meet(q);
//    p.switchMajor(string newMajor);
//    p.major;
    
    

}

//void testApp::introduce(Person a, Person b) {
//    cout <<"Hey, "<<b.name<<endl;
//    cout<<"His/Her name is"<< a.name << endl;
//    
//    
//    if (a.alive == false){
//        cout << "oh dear. " << a.name << "seems to have died" <<endl; 
//    }
//}

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
