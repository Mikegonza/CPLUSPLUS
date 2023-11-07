#include "CruiseShip.h"
#include <iostream>
using namespace std;
CruiseShip::CruiseShip(const string& name, const string& year, int passengers) : Ship(name, year), maxPassengers(passengers) {}

int CruiseShip::getMaxPassengers() const { return maxPassengers; }
void CruiseShip::setMaxPassengers(int passengers) { maxPassengers = passengers; }

void CruiseShip::print() const {
    Ship::print();
    cout << "Maximum Passengers: " << maxPassengers << endl;
}

