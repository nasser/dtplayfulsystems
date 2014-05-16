//
//  person.h
//  firstClassOnClasses
//
//  Created by Joselyn McDonald  on 4/16/14.
//
//

#ifndef __firstClassOnClasses__person__
#define __firstClassOnClasses__person__

#include <iostream>

using namespace std; // giggle


class Person {
    
    
public:
    
    int age;
    bool alive;
    bool employed; 

    string name;
    string major;

    Person(string name);
    
    void sneeze();
    void giggleNervously();
    void meet(Person);
    void switchMajor(string);
    bool shouldBeEmployed();
    

}; 



#endif /* defined(__firstClassOnClasses__person__) */
