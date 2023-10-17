#include "Inventory.h"
#include<iostream>
using namespace std;
int main() {
	//Instantiate an object
	Inventory item;
	item.setItem(12, 12345, "Cannoballls", 125.00);
	Inventory item2;
	item2.setItem(30,23456, "Ping pong balls", 1.25);
	cout << item.getQty() << " " << item.getSku() << " " << item.getDesc() << " " << item.getPrice()<<endl;
	cout << item2.getQty() << " " << item2.getSku() << " " << item2.getDesc() << " " << item2.getPrice()<<endl;
}