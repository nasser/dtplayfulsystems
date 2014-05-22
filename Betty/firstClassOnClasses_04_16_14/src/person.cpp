//
//  person.cpp
//  firstClassOnClasses_04_16_14
//
//  Created by Betty Quinn on 4/16/14.
//
//

#include "person.h"

void Person::seize(){
  //  ofSetBackgroundColor(255, 255, 255);
}

Person::Person(string name){
    age = 8;
    alive = true;
    employed = false;
    this ->name = name;
    major = "";
}

void Person::giggleNervously(){
    cout << "hehehehehe" << endl;
}

void Person::meet(Person other){
    cout << "Hey " << other.name << ", my name is " << this->name << endl;
    other.giggleNervously();
    other.seize();
}

void Person::switchMajor(string newMajor){
    this->major = newMajor;
}
