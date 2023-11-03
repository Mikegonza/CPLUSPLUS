#pragma once
#include <iostream>
using namespace std;
class Inventory {
protected:
	double price;
public:
	Inventory() { cout << "Entering Inventory ctor" << endl; }
	~Inventory() { cout << "Entering Inventory dtor" << endl; }
	void setPrice(double p) { price = p; }
	double getPrice() { return price * 1000; }
};