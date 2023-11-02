#include <iostream>
#include "RoomCarpet.h"

using namespace std;
int main() {
    int lengthFeet, lengthInches, widthFeet, widthInches;
    double costPerSquareFoot;
        
    cout << "Enter the length of the room (feet_inches): ";
    cin >> lengthFeet >> lengthInches;
    
    cout << "Enter the width of the room (feet_inches): ";
    cin >> widthFeet >> widthInches;

    cout << "Enter the cost per square foot of the carpet: ";
    cin >> costPerSquareFoot;

    RoomCarpet carpet(widthFeet, widthInches, lengthFeet, lengthInches, costPerSquareFoot);

    cout << "The total cost to carpet this room is $" << carpet.totalCost() << endl;

    return 0;
}

