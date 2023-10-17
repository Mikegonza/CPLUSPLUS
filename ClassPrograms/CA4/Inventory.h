#pragma once
#include <string>
using namespace std;

class Inventory{
	//atributes
private:
	int qty;
	int sku;
	string desc;
	double price;
	//Methods
public:
	void setItem(int qty, int sku, string desc, double price);
	int getQty() { return qty; };
	int getSku() { return sku; };
	string getDesc() { return desc; };
	double getPrice() {return price; };
};

