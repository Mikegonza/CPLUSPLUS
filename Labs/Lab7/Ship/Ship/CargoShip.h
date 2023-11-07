#ifndef CARGOSHIP_H
#define CARGOSHIP_H

#include "Ship.h"
using namespace std;
class CargoShip : public Ship {
private:
    int cargoCapacity;

public:
    CargoShip(const string& name, const string& year, int capacity);
    virtual ~CargoShip() {}

    int getCargoCapacity() const;
    void setCargoCapacity(int capacity);

    virtual void print() const override;
};

#endif // CARGOSHIP_H
