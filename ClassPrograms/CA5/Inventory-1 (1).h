#pragma once
#include <string>
#include<fstream>
using namespace std;

class Inventory{
	//atributes
public:
	static int totalInventoryItems;
private:
	
	int qty;
	int sku;
	string desc;
	double price;
	fstream outputFile;

	//Methods
public:
	//Default constructor
	Inventory() { outputFile.open("output.txt", ios::binary); };
	//Other contructors
	Inventory(int qty, int sku, string desc, double price);
	//copy constructor
	Inventory(Inventory& inv);
	//Destructor
	~Inventory() { outputFile.close(); totalInventoryItems--; }

	//void setItem(int qty, int sku, string desc, double price);
	int getQty() { return qty; };
	int getSku() { return sku; };
	string getDesc() { return desc; };
	double getPrice() {return price; };
};

