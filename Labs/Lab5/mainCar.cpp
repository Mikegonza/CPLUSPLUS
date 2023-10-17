/* COSC 1437 - Lab 5
   Miguel Angel Gonzalez Mauricio
   Programming Fundamentals II
   COSC-1437
   Instructor: Brian Koontz
*/
#include <iostream>
#include "car.h"
using namespace std;
int main() {
    Car myCar( 2023, "Mercedez");

    // Call Accelerate method 5 times
    cout << "Increase the speed by 5 for the " << myCar.getMake()<< " " <<myCar.getYearModel() << endl;
    for (int i = 0; i < 5; i++) {
        myCar.accelerate();        
        cout << "Current Speed: " << myCar.getSpeed() << " mph" <<endl;
    }
    cout << "----------------------------------------------"<<endl;
    // call Brake method 5 times
    cout << "Decrease the speed by 5 for the " << myCar.getMake() << " " << myCar.getYearModel() << endl;
    for (int i = 0; i < 5; i++) {
        myCar.brake();       
        cout << "Current Speed: " << myCar.getSpeed() << " mph" <<endl;
    }

    return 0;
}
