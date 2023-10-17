#include "Inventory.h"
#include<iostream>
using namespace std;
int main() {
	//Instantiate an object
	Inventory item(12, 12345, "Cannoballls", 125.00);
	Inventory item2(30, 23456, "Ping pong balls", 1.25);
	Inventory* item3 = new Inventory(1, 345, "Tennis balls", 3.40);
	cout << item.getQty() << " " << item.getSku() << " " << item.getDesc() << " " << item.getPrice()<<endl;
	cout << item2.getQty() << " " << item2.getSku() << " " << item2.getDesc() << " " << item2.getPrice()<<endl;
	cout << item3->getQty() << " " << item3->getSku() << " " << item3->getDesc() << " " << item3->getPrice() << endl;
	cout << "total inventory items :" << Inventory::totalInventoryItems;
	
}