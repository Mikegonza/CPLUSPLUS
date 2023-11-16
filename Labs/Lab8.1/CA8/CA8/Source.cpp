#include "Header.h"
#include <iostream>
using namespace std;

int main() {
	// Some derived class instantiations
	Square s(5);
	Triangle t(12, 5);
	Circle c(10);

	// Through inheritance, you get access to the 
	// name attribute in Shape:
	s.getInfo(); t.getInfo(); c.getInfo();

	// With inheritance,you have to group your classes
	// together by type, and process them by type:
	Square sArr[100];
	Triangle tArr[100];
	Circle cArr[100];

	// An example of polymorphism:
	Shape* shape = &s;
	shape->getInfo();
	cout << "Shape: " << shape->area() << endl; // Does not work!
	
	// One array to hold them all!
	// This is polymorphism.  You must use
	// pointers for run-time binding (virtual table)
	// to work!
	Shape* shapePtr[3] = { &s, &t, &c };
	for (int i = 0; i < 3; i++) {
		shapePtr[i]->getInfo();
	}


}

