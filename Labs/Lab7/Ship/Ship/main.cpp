#include "Ship.h"
#include "CruiseShip.h"
#include "CargoShip.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<Ship*> ships;
    string name, year;
    int maxPassengers, cargoCapacity;

    // Get Ship information from the user
    cout << "Enter the name and year of a ship: ";
    cin >> name >> year;
    ships.push_back(new Ship(name, year));

    // Get CruiseShip information from the user
    cout << "Enter the name, year, and maximum number of passengers for a cruise ship: ";
    cin >> name >> year >> maxPassengers;
    ships.push_back(new CruiseShip(name, year, maxPassengers));

    // Get CargoShip information from the user
    cout << "Enter the name, year, and cargo capacity in tonnage for a cargo ship: ";
    cin >> name >> year >> cargoCapacity;
    ships.push_back(new CargoShip(name, year, cargoCapacity));

    for (auto* ship : ships) {
        ship->print();
        cout << endl;
    }

    // Clean up the dynamically allocated memory
    for (auto* ship : ships) {
        delete ship;
    }

    return 0;
}