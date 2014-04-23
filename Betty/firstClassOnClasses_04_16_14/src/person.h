//
//  person.h
//  firstClassOnClasses_04_16_14
//
//  Created by Betty Quinn on 4/16/14.
//
//

#ifndef __firstClassOnClasses_04_16_14__person__
#define __firstClassOnClasses_04_16_14__person__

#include <iostream>

using namespace std; //hehe

class Person {
public:
    string name;
    int age;
    int height;
    string job;
    string major;
    bool employed;
    bool alive;
    void getMoney(int hours, int pay);
    
    void seize();
    void giggleNervously();
    void meet(Person other);
    void switchMajor(string newMajor);
    bool shouldBeEmployed();

};

#endif /* defined(__firstClassOnClasses_04_16_14__person__) */
