//
//  Person.h
//  flocking_03_16
//
//  Created by Nicole Messier on 4/16/14.
//
//

#ifndef __flocking_03_16__Person__
#define __flocking_03_16__Person__

#include <iostream>

using namespace std; //c++ has namespaces to group things by topics

class Person {
    //private: //these variables can't change unless you are inside this code
    //protected:
    //friend:
    public:
    
        int age;
        bool alive;
        bool employed;
        string name;
        string major;
        //std::string name; //string is in the standard namespace
    
    //-------methods------------
    void sneeze();
    void giggleNervously();
    void meet(Person other);
    void switchMajor(string newMajor);
    bool shouldBeEmployed();
};

#endif /* defined(__flocking_03_16__Person__) */
