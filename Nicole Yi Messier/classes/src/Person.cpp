//
//  Person.cpp
//  flocking_03_16
//
//  Created by Nicole Messier on 4/16/14.
//
//

#include "Person.h"
#include "ofMain.h" //includes OF functions

void Person::sneeze() {
    ofBackground(ofRandom(255), ofRandom(255), ofRandom(255));
}

void Person::giggleNervously() {
    cout << "heheheh???" << endl;
}

void Person::meet(Person other){
    cout << "HI" << other.name << ", my name is"  << this->name << endl;
    
    other.giggleNervously();
    other.sneeze();
}

void Person::switchMajor(string newMajor){
    this->major = newMajor;
}
