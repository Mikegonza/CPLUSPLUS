//Miguel Angel Gonzalez Mauricio
//This is the main program where is testing the input from
//the user returning the rigth result according to the input 
#include <iostream>
#include "palindrome.h"
using namespace std;
int main() {
    const int maxSize = 50;
    char input[maxSize];

    while (true) {
        cout << "Enter a string to test, " << maxSize << " chars max, ctrl-c to end: ";
        if (!cin.getline(input, maxSize)) {
            // Handle input error (Ctrl-C).
            break;
        }

        if (isPalindrome(input, strlen(input))) {
            cout << "The string \"" << input << "\" is a palindrome!" << endl;
        }
        else {
            cout << "The string \"" << input << "\" is not a palindrome!" << endl;
        }
    }

    return 0;
}
