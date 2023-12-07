#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Encryption.h"
using namespace std;

class XORCipher : public Encryption {

    //^^ "XORCipher" is a class that inherits from the Encryption class, indicating that it provides implementations for the pure virtual functions declared in the "Encryption" class.

private:
    char key;

    //^^ char key;: This is a private member variable specific to the "XORCipher" class. It represents the key used for XOR encryption and decryption.

public:
    XORCipher(char _key) : key(_key) {}

    //^^ This is the constructor for the ""XORCipher"" class.

    string encrypt(const string& text) const;

    //^^ This method overrides the encrypt function inherited from the Encryption class.
    // It takes an input string text and performs XOR encryption using the key.
    // It iterates through each character (char& c) in the result string using a range-based for loop.
    // For each character in the result string, it performs the XOR (exclusive OR) operation with a key.
    // The XOR operation (c ^= key) modifies each character in result by combining it with the key, effectively encrypting the text.
        //^= is the bitwise XOR compound assignment operator in C++. It performs a bitwise XOR operation between the value of c and key and assigns the result back to c.
        // c is a variable holding a character or an integer value
        // key is another variable, typically holding a character or an integer value, used as the XOR key.
        // The XOR operation works on individual bits of the values represented by c and key:
        // If a bit in c and the corresponding bit in key are different, the resulting bit in c will be set (1).
        // If the bits are the same, the resulting bit will be cleared (0).
    // The result of the XOR operation is stored in result, which is then returned as the encrypted text.

    string decrypt(const string& text) const;

    //^^ This method overrides the decrypt function inherited from the Encryption class.
    // It uses the encrypt method itself to perform decryption.
    // It simply calls the encrypt method with the encrypted text, as XOR decryption and encryption operations are the same.

    string getEncodedScheme() const;

    // This method overrides the getEncodedScheme function inherited from the Encryption class.
    // It returns a string indicating the encoded scheme used by this specific encryption class, which is "XORCipher" in this case.
};
