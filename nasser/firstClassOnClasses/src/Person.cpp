//
//  Person.cpp
//  firstClassOnClasses
//
//  Created by Ramsey Nasser on 4/16/14.
//
//

#include "Person.h"
#include "ofMain.h"

Person::Person(string name) {
    this->age = 18;
    this->alive = true;
    this->employed = false;
    this->name = name;
    this->major = "";
}

Person::Person(string name, int age) {
    this->age = age;
    alive = true;
    employed = false;
    this->name = name;
    major = "";
}

void Person::sneeze() { // sorry :(
    ofBackground(ofRandom(255), ofRandom(255), ofRandom(255));
}

void Person::giggleNervously() {
    giggleNervously("hehehehehehehehehehehe????", 1);
}

void Person::giggleNervously(string thingToGiggle) {
    giggleNervously(thingToGiggle, 10);
}

void Person::giggleNervously(string thingToGiggle, int timesToGiggle) {
    for (int i=0; i<timesToGiggle; i++) {
        cout << thingToGiggle;
    }
    
    cout << endl;
}

void Person::meet(Person other) {
    cout << "Hi " << other.name << ", my name is" << this->name << endl;
    other.giggleNervously();
    other.sneeze();
}

void Person::switchMajor(string newMajor) {
    this->major = newMajor;
}

bool Person::shouldBeEmployed() {
    return this->age > 18 && this->age < 65 && this->alive;
}
