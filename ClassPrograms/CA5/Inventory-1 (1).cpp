#include "Inventory.h"
using namespace std;
//static attributes
int Inventory::totalInventoryItems = 0;
//Methods
Inventory::Inventory(int qty, int sku, string desc, double price) {
	this->qty=qty;
	this->sku=sku;
	this->desc=desc;
	this->price=price;
	totalInventoryItems++;
}
Inventory::Inventory(Inventory& inv) {
	qty = inv.getQty();
	sku = inv.getSku();
	desc = inv.getDesc();
	price = inv.getPrice();
}
/*
:: scope resolution operator
*/
