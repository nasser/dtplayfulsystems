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
    int age;
    bool alive;
    bool employed;
    string name;
    string major;
    
    void sneeze();
    void giggleNervously();
    void meet(Person other);
    void switchMajor(string newMajor);
    bool shouldBeEmployed();
};

#endif /* defined(__firstClassOnClasses__Person__) */
