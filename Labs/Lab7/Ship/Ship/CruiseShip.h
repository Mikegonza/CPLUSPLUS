#pragma once
#ifndef CRUISESHIP_H
#define CRUISESHIP_H

#include "Ship.h"
using namespace std;

class CruiseShip : public Ship {
private:
    int maxPassengers;

public:
    CruiseShip(const string& name, const string& year, int passengers);
    virtual ~CruiseShip() {}

    int getMaxPassengers() const;
    void setMaxPassengers(int passengers);

    virtual void print() const override;
};

#endif // CRUISESHIP_H
