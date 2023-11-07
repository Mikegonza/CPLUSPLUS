#include "Ship.h"
#include <iostream>
using namespace std;
Ship::Ship(const string& name, const string& year) : name(name), yearBuilt(year) {}

string Ship::getName() const { return name; }
void Ship::setName(const string& name) { this->name = name; }

string Ship::getYearBuilt() const { return yearBuilt; }
void Ship::setYearBuilt(const string& year) { this->yearBuilt = year; }

void Ship::print() const {
    cout << "Name: " << name << "\nYear Built: " << yearBuilt << endl;
}
