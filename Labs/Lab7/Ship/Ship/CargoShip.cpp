#include "CargoShip.h"
#include <iostream>
using namespace std;
CargoShip::CargoShip(const string& name, const string& year, int capacity)
    : Ship(name, year), cargoCapacity(capacity) {}

int CargoShip::getCargoCapacity() const { return cargoCapacity; }
void CargoShip::setCargoCapacity(int capacity) { cargoCapacity = capacity; }

void CargoShip::print() const {
    Ship::print();
    cout << "Cargo Capacity: " << cargoCapacity << " tonnage" << endl;
}

