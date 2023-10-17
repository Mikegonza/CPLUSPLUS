/* COSC 1437 - Lab 5
   Miguel Angel Gonzalez Mauricio
   Programming Fundamentals II
   COSC-1437
   Instructor: Brian Koontz
*/
#include <string>
using namespace std;
class Car {
public:
    //Constructor Car
    Car(int yearModel, string make);
    string getMake();
    int getYearModel() ;
    int getSpeed();
    void setYearModel(int yearModel);    
    void setMake(string make);   
    void setSpeed(int speed);
    void accelerate();
    void brake();

private:
    int yearModel;    
    int speed;
    string make;
};

