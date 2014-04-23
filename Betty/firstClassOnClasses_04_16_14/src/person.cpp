//
//  person.cpp
//  firstClassOnClasses_04_16_14
//
//  Created by Betty Quinn on 4/16/14.
//
//

#include "person.h"

void Person::seize(){
    ofBackground(ofRandom(255), ofRandom(255), ofRandom(255));
}

void Person::giggleNervously(){
    cout << "hehe" << endl;
}

void Person::meet(Person other){
    cout << "Hey " << other.name << ", my name is " << this->name << endl;
    other.giggleNervously();
    other.seize();
}

void Person::switchMajor(string newMajor){
    this->major = newMajor;
}
