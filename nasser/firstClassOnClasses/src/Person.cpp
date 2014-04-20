//
//  Person.cpp
//  firstClassOnClasses
//
//  Created by Ramsey Nasser on 4/16/14.
//
//

#include "Person.h"
#include "ofMain.h"

void Person::sneeze() { // sorry :(
    ofBackground(ofRandom(255), ofRandom(255), ofRandom(255));
}

void Person::giggleNervously() {
    cout << "hehehehehehehehehehehe????" << endl;
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
