#include "Person.h"
#include "ofMain.h"



void Person::seize() {
    ofBackground(ofRandom(255), ofRandom(255), ofRandom(255));

}


void Person::giggleNervously() {
    cout << "hehehehehehehe????" << endl;
}

void Person::meet(Person other) {
    cout << "Hi " << other.name << ", my name is " << this->name <<endl;
    other.giggleNervously();
    other.seize();

}

void Person::switchMajor(string newMajor) {
    this->major = newMajor;

}

bool Person::shouldBeEmployed() {
    return this-> age > 18 && this->age < 65 && this->alive;

}
