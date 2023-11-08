#pragma once
#ifndef SHIP_H
#define SHIP_H

#include <string>
using namespace std;

class Ship {
private:
    string name;
    string yearBuilt;

public:
    Ship(const string& name, const string& year);
    virtual ~Ship() {}

    string getName() const;
    void setName(const string& name);

    string getYearBuilt() const;
    void setYearBuilt(const string& year);

    virtual void print() const;
};

#endif 
