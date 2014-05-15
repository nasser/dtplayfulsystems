#pragma once

#include <iostream>

using namespace std;

class Person {
public:

    int age;
    bool alive;
    bool employed;
    string name;
    string major;

    void seize();
    void giggleNervously();
    void meet(Person);
    void switchMajor(string);
    bool shouldBeEmployed();


    /*
    givenName
    familyName
    gender
    age
    nationality
    heightInches
    weightLbs
    hairColor
    */


};
