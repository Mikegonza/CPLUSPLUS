#pragma once
#include "Inventory.h"
#include <iostream>
using namespace std;
class Produce : public Inventory {
private:
	double wt;
public:
	Produce() { cout << "Entering Produce ctor" << endl; }
	~Produce() { cout << "Entering Produce dtor" << endl; }
	void setPrice(double p) { price = p * 10.0; }
	double getPrice() { return price; }
	void setWt(double w) { wt = w; }
	double getWt() { return wt; }
};
