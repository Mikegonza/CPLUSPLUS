/*
#include <iostream>
using namespace std;

// Function to calculate the product of two numbers using recursion
int product(int x, int y) {
    if (y == 1)
        return x; // Base case
    else
        return x + product(x, y - 1); // Recursive call
}

// Function to calculate the product of three numbers using the two-argument version
int product(int x, int y, int z) {
    return product(product(x, y), z);
}

int main() {
    int x,y,z;

    cout << "Enter first number: ";
    cin >> x;

    cout << "Enter second number: ";
    cin >> y;

    cout << "Enter third number: ";
    cin >> z;

    // Testing the Function to calculate the product of two numbers using recursion
    cout << "The product of " << x << " and " << y << " is: " << product(x, y) << endl;

    // Testing the Function to calculate the product of three numbers using the two-argument version
    cout << "The product of " << x << ", " << y << " and " << z << " is: " << product(x, y, z) << endl;

    return 0;
}
*/