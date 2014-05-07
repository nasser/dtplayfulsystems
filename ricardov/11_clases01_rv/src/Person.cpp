//
//  Person.cpp
//  11_clases01_rv
//
//  Created by @ricardov_cl on 4/16/14.
//
//

#include "Person.h"
#include "ofMain.h"

//type, Class, ::, methodName
//Class name toassociate w the class where to found the method. 
void Person::sneeze() {
    ofBackground(ofRandom(255));
    
}

void Person::giggleNervously(){
    cout << "ja ja" << endl;
}

void Person::meet(Person other){
    cout << "mi nale is" << other.name <<  endl;
    
}

void Person::switchMajor(string newMajor) {
    this->major = newMajor;
}

bool Person::shouldBeEmployed() {
    return  (this->age > 18)  &&  (this->age < 50);
    
}