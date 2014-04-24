//
//  Person.h
//  firstClassOnClasses
//
//  Created by Ramsey Nasser on 4/16/14.
//
//

#ifndef __firstClassOnClasses__Person__
#define __firstClassOnClasses__Person__

#include <iostream>

using namespace std; // giggle

class Person {
public:
    bool alive;
    long deathday;
    int age;
    bool employed;
    string name;
    string major;
    int birthday;
    
    Person(string name);
    Person(string name, int age);
    
    void sneeze();
    void giggleNervously();
    void giggleNervously(string thingToGiggle);
    void giggleNervously(string thingToGiggle, int timesToGiggle);
    void meet(Person other);
    void switchMajor(string newMajor);
    bool shouldBeEmployed();
};

#endif /* defined(__firstClassOnClasses__Person__) */
