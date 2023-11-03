#include "Produce.h"
#include <iostream>
using namespace std;
int main() {
	/*
	Produce carrot;
	carrot.setWt(10.0);
	carrot.setPrice(2.49);
	cout << "Weight of carrots: " << carrot.getWt() << endl;
	cout << "Price of carrots: " << carrot.getPrice() << endl;
	*/
	Produce *pcarrot = new Produce;
	pcarrot->setWt(10.0);
	pcarrot->setPrice(2.49);
	cout << "Weight of carrots: " << pcarrot->getWt() << endl;
	cout << "Price of carrots: " << pcarrot->getPrice() << endl;

	Inventory* pinventory = pcarrot;
	//cout << "Weight of inventory: " << pinventory->getWt() << endl;
	cout << "Price of inventory: " << pinventory->getPrice() << endl;
	delete pcarrot;
} 