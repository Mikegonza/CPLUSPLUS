#include "FeetInches.h"
#include <cstdlib> // Needed for abs()

// Simplify function definition
void FeetInches::simplify() {
    if (inches >= 12)
    {
        feet += (inches / 12);
        inches = inches % 12;
    }
    else if (inches < 0)
    {
        feet -= ((abs(inches) / 12) + 1);
        inches = 12 - (abs(inches) % 12);
    }
}

// Constructor
FeetInches::FeetInches(int f, int i) : feet(f), inches(i) {
    simplify();
}

// Copy Constructor
FeetInches::FeetInches(const FeetInches& obj) : feet(obj.feet), inches(obj.inches) {    
}

// Static method multiply
double FeetInches::multiply(const FeetInches& a, const FeetInches& b) {
    double totalFeetA = a.feet + (a.inches / 12.0);
    double totalFeetB = b.feet + (b.inches / 12.0);
    return totalFeetA * totalFeetB;
}

// Mutator functions
void FeetInches::setFeet(int f) {
    feet = f;
}

void FeetInches::setInches(int i) {
    inches = i;
    simplify();
}

// Accessor functions
int FeetInches::getFeet() const {
    return feet;
}

int FeetInches::getInches() const {
    return inches;
}
