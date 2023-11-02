#pragma once
#ifndef FEETINCHES_H
#define FEETINCHES_H

class FeetInches;

class FeetInches {
private:
    int feet;
    int inches;
    void simplify();

public:
    // Constructor
    FeetInches(int f = 0, int i = 0);

    // Copy Constructor
    FeetInches(const FeetInches& obj);

    // Static method to multiply two FeetInches objects
    static double multiply(const FeetInches& a, const FeetInches& b);

    // Mutator functions
    void setFeet(int f);
    void setInches(int i);

    // Accessor functions
    int getFeet() const;
    int getInches() const;
};

#endif 
