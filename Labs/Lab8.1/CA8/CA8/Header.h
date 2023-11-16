#pragma once
#include <iostream>
#include <string>
using namespace std;

class Shape {
protected:
	string name;
public:
	// These are declared as virtual, so you will
	// get run-time binding (polymorphism) with any 
	// derived classes that also implement these methods!
	virtual double area() { return 0.0; };
	virtual void getInfo() { cout << "Name: " << name << endl; }
};


class Square : public Shape {
private:
	int length;
public:
	Square() {}
	Square(int l) { length = l; name = "square"; }
	/*virtual*/ double area() { return length * length; };
	/*virtual*/ void getInfo() { cout << "Name: " << name << " Area: " << area() << endl; }
};


class Triangle : public Shape {
private:
	int base;
	int height;
public:
	Triangle() {}
	Triangle(int b, int h) { name = "triange"; base = b; height = h; }
	/*virtual*/ double area() { return 0.5 * base * height; }
	/*virtual*/ void getInfo() { cout << "Name: " << name << " Area: " << area() << endl; }
};

class Circle : public Shape {
private:
	int radius;
public:
	Circle() {}
	Circle(int r) { name = "circle";  radius = r; }
	/*virtual*/ double area() { return 3.14159 * radius * radius; }
	/*virtual*/ void getInfo() { cout << "Name: " << name << " Area: " << area() << endl; }
};

/*
class Shape {
protected:
	string name;
public:
	virtual double area() = 0;
	virtual void getInfo() { cout << "Name: " << name << endl; }
};

class Square : public Shape {
private:
	int length;
public:
	Square() {}
	Square(int l) : length(l) { name = "square"; }
	double area() override { return length * length; }
	void getInfo() override { cout << "Name: " << name << " Area: " << area() << endl; }
};

class Triangle : public Shape {
private:
	int base;
	int height;
public:
	Triangle() {}
	Triangle(int b, int h) : base(b), height(h) { name = "triangle"; }
	double area() override { return 0.5 * base * height; }
	void getInfo() override { cout << "Name: " << name << " Area: " << area() << endl; }
};

class Circle : public Shape {
private:
	int radius;
public:
	Circle() {}
	Circle(int r) : radius(r) { name = "circle"; }
	double area() override { return 3.14159 * radius * radius; }
	void getInfo() override { cout << "Name: " << name << " Area: " << area() << endl; }
};
*/