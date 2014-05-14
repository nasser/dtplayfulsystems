//
//  Person.h
//  april16
//
//  Created by Evander Batson on 4/16/14.
//
//

#ifndef __april16__Person__
#define __april16__Person__

#include <iostream>

using namespace std;

class Person {
public:
    int age;
    bool alive;
    bool employed;
    string name;
    string major;
    
    void draw();
    void seize();
    void giggleNervously();
    void meet(Person other);
    void switchMajor(string newMajor);
    bool shouldBeEmployed();
};

#endif /* defined(__april16__Person__) */
