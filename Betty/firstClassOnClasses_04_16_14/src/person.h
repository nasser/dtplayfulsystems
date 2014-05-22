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
    
    Person(string name);
    
    void seize();
    void giggleNervously();
    void meet(Person other);
    void switchMajor(string newMajor);
    bool shouldBeEmployed();

};

#endif /* defined(__firstClassOnClasses_04_16_14__person__) */

/* CLASS NOTES on memory (4/23/14)
 - new ____ means allocate it in the heap
 - Person, int (or variable type) tells how large the space it will take out
 - layout internally is dictated by the class
 - arrow means follow it to the memory address and find the thing 
    ex. (this->age = 8) means follow age and find 8(?)
 - constructor exits setup and function is destroyed
    - but the object at memory address still exists
 
 - ex. 
    Person* r = new Person("nameless");
    (write nameless into r's bit of memory)
    - dont treat r like a number, follow it in the heap, find "age" and give me back that value
    - r is a pointer to Person
 
 - pointers have a life cycle
 
 - tilda ~ is a destructor 
    - run when object is pulled out of memory
    - never takes arguments
 
 
 
 
//arrow says take the number and follow it




*/