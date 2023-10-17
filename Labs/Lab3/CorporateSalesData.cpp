/*
* Miguel Angel Gonzalez Mauricio
  Programming Fundamentals II
  COSC-1437
  Instructor: Brian Koontz
* 
Write a menu-driven program that uses a structure to store the following data on a company division:
a) Division name (East, West, North, or South)
b) Quarter (1, 2, 3, or 4)
c) Quarterly sales
The user should be asked for the four quarters' sales figures for the East, West, North, and South divisions. 
The data for each quarter for each division will then be written to a binary file.  Other operations will retrieve the data from the file, and display the quarterly sales per quarter per division.
Input validation: Advise the user if the binary file specified cannot be read.
*/
#include <iostream>
#include <fstream>
#include "Division.h"

using namespace std;
char fileName[100];


void inputData(Division divisions[], int size) {

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < 4; ++j) {            
            cout << "Enter sales for " << divisions[i].name << "division " " (Quarter " << j + 1 << ") : ";
            cin >> divisions[i].sales[j];
        }
    }
}

void writeToFile(Division divisions[], int size) {    
    cout << "Enter the name of the file: ";
    cin >> fileName;
    ofstream outFile(fileName, ios::binary);
    if (!outFile) {
        cerr << "Error: Cannot open file " << fileName << " for writing." << endl;
        return;
    }
    outFile.write(reinterpret_cast<char*>(divisions), size * sizeof(Division));
    outFile.close();
}

void readFromFile(Division divisions[], int size) {    
    cout << "Enter the name of the file to read: ";
    cin >> fileName;
    ifstream inFile(fileName, ios::binary);
    if (!inFile) {
        cerr << "Error: Cannot open file " << fileName << " for reading." << endl;
        return;
    }
    inFile.read(reinterpret_cast<char*>(divisions), size * sizeof(Division));    
    inFile.close();
}

void displaySales(Division divisions[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "Division: " << divisions[i].name << endl;
        for (int j = 0; j < 4; ++j) {
            cout << "Quarter " << j + 1 << " Sales: $" << divisions[i].sales[j] << endl;
        }
        cout << endl;
    }
}


int main() {
    const int size = 4;   
    Division divisions[size] = { {"East", 1, 0.0}, {"West", 1, 0.0}, {"North", 1, 0.0}, {"South", 1, 0.0} };   
       
    int option;

    do {
        cout << "   Menu-Driven  "<< endl;
        cout << "1. Input" << endl;
        cout << "2. Write data to file" <<endl;
        cout << "3. Read data from file" << endl;
        cout << "4. Display sales" << endl;
        cout << "99. End program" << endl;
        cout << "Select an option: ";
        cin >> option;      
        
        switch (option) {
        case 1:
            inputData(divisions, size);
            break;
        case 2:
            writeToFile(divisions, size);
            break;
        case 3:
            readFromFile(divisions, size);
            break;
        case 4:
            displaySales(divisions, size);
            break;
        case 99:
            cout << "Ending program." << endl;
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
        }
    } while (option != 99);

    return 0;
}
