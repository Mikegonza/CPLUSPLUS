/*Miguel Angel Gonzalez Mauricio
  Programming Fundamentals II
  Cosc-1437
  Instructor: Brian Koontz
*/
/*Program that  this program initializes an array of Country objects, writes the data from this array to a binary file,
  and then reads and displays the data from that binary file. 
  the program is used to store and retrieve this data using binary file I/O operations.
*/
#include <iostream>
#include <fstream>
#include "Header.h"

using namespace std;

int main(){
    Country countries[] = { {"japan",1.34,125,4.941},
                          {"south Korea",0.84,52,1.8} };
    fstream countryFile;
    countryFile.open("countries.bin", ios::out | ios::binary);
    countryFile.write(reinterpret_cast<char*>(countries), sizeof(Country));
    countryFile.write(reinterpret_cast<char*>(countries+1), sizeof(Country));
    countryFile.close();
    
    countryFile.open("countries.bin",ios::in |ios::binary);
    Country myCountry;
    countryFile.read(reinterpret_cast<char*>(&myCountry), sizeof(Country));
    while (!countryFile.eof()) {
        cout << "country: " << myCountry.country << endl;
        cout << "Birth rate: " << myCountry.birthRate << endl;
        cout << "GDP: " << myCountry.gdp << endl;
        countryFile.read(reinterpret_cast<char*>(&myCountry), sizeof(Country));
    }
    countryFile.close();
}


