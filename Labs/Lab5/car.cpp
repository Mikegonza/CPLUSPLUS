/* COSC 1437 - Lab 5
   Miguel Angel Gonzalez Mauricio
   Programming Fundamentals II
   COSC-1437
   Instructor: Brian Koontz
*/
#include "car.h"
using namespace std;

//Constructor that assign an initial value of 0 to the speed attribute.
Car::Car(int yearModel,string make) {
    this->yearModel = yearModel;
    this->make = make;
    this->speed = 0;
}

int Car::getYearModel() {
    return yearModel;
}

void Car::setYearModel(int yearModel) {
    this->yearModel = yearModel;
}

string Car::getMake() {        
    return make;
}

void Car::setMake(string make) {
    this->make = make;
}

int Car::getSpeed() {
    return speed;
}

void Car::setSpeed(int speed) {
    this->speed = speed;
}

void Car::accelerate() {
    speed += 5;
}

void Car::brake() {
    speed -= 5;
}

