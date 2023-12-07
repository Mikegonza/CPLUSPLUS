#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Encryption {

    //^^ "Encryption" is an abstract class, denoted by the presence of pure virtual functions.
    // It serves as an interface or blueprint for various encryption algorithms by defining three pure virtual functions:

public:
    virtual string encrypt(const string& text) const = 0;

    // This function is responsible for taking an input text and performing encryption. It has no implementation in the base class, hence it is a pure virtual function.

    virtual string decrypt(const string& text) const = 0;

    // This function is responsible for taking an encrypted text and performing decryption. Similar to encrypt, it's a pure virtual function and lacks an implementation in the base class.

    virtual string getEncodedScheme() const = 0;

    //This function is intended to retrieve the encoded scheme used for a particular encryption. 
    // Like the other two functions, it's a pure virtual function without an implementation in the base class.

};
