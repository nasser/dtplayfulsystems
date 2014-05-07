//
//  Person.h
//  11_clases01_rv
//
//  Created by @ricardov_cl on 4/16/14.
//
//

#ifndef ___1_clases01_rv__Person__
#define ___1_clases01_rv__Person__

#include <iostream>

//std to prevent collision name, for example on libraries namespaces.
// define spacename for own classes
using namespace std;


class Person {

//private: // accesible just for inside the class
// protected: this class and inherited
//  friend class
public: // accesible just for any class

    int age;
    bool alive;
    bool employed;
    string name;
    string major;
    
    void sneeze();
    void giggleNervously();
    void meet(Person);
    void switchMajor(string);
    bool shouldBeEmployed();
    
};





#endif /* defined(___1_clases01_rv__Person__) */
