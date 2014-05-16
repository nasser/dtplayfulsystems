//
//  person.cpp
//  firstClassOnClasses
//
//  Created by Joselyn McDonald  on 4/16/14.
//
//

#include "person.h"

#include "ofMain.h" // this will allow you to pull in open frameworks stuff; 


//if different variables have the same name - the parameter "name" (in the brackets) dominate the instance "name"

Person:Person(string name){

    age=8;
    alive = true;
    employed = false;
    this->name = "nameless";
    major = ""; 
}

void Person::seize(){
    
    ofBackground(ofRandom(255), ofRandom(255), ofRandom(255));
    
}

void Person::giggleNervously(){
    
    cout << "hehehehehhehehe???" <<endl; 
    
}

void Person::meet(Person other) {
    
    cout<<"hi"<<other.name<< ", my name is" << this-> name << endl;
    other.giggleNervously();
    other.seize(); 
    
}
