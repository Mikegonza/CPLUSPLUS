#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Encryption.h"
using namespace std;

class CaesarCipher : public Encryption {

    //^^ "CaesarCipher" is a class that inherits from the "Encryption" class, implying that it provides implementations for the pure virtual functions declared in the Encryption class.

private:
    int shift;

    //^^ int shift;: This member variable represents the shift value used in the Caesar Cipher algorithm.

public:
    CaesarCipher(int _shift) : shift(_shift) {}

    //^^ The above colon introduces the initialization list. Initialization lists are used to initialize the member variables of a class before the constructor body is executed.
    // shift(_shift): This initializes the member variable shift with the value passed to the constructor. In this case, shift(_shift) initializes the shift member variable with the value 
    // provided as _shift when an object of the CaesarCipher class is created.

    string encrypt(const string& text) const;

    //^^ This method overrides the encrypt function inherited from the Encryption class.
    // It takes an input string text and performs Caesar Cipher encryption with the specified shift value.
        // Initiates a loop that iterates through each character c in the result string.
        // For each character c in the text:
            // Checks if the character c is an alphabet character using the isalpha function.
            // This line determines the base character for the alphabet (either 'A' for uppercase or 'a' for lowercase) based on whether the character c is uppercase or lowercase.
            // performs the Caesar Cipher encryption operation on each alphabet character.
                // Converts the character's position within its case ('A' or 'a') to a number between 0 and 25.
                // Adds the encryption shift value (provided during object creation) to shift the character's position within the alphabet.
                // Ensures that the resulting position wraps around within the range of 0 to 25 (the number of letters in the English alphabet).
                //  Converts the resulting position back to the corresponding character within its case ('A' or 'a').
            // Updates the character c with the shifted value.
        // The resulting result string contains the encrypted text.


   /* string decrypt(const string& text) const override {
        return encrypt(text);
    }*/

    string decrypt(const string& text) const;

    //^^  This method simply calls the encrypt method itself to perform decryption.
    // In the Caesar Cipher, decryption is the same as encryption but in reverse; therefore, calling encrypt on the encrypted text effectively decrypts it.

    string getEncodedScheme() const;

};