#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Encryption {
public:
    virtual string encrypt(const string& text) const = 0;
    virtual string decrypt(const string& text) const = 0;
    virtual string getEncodedScheme() const = 0;
};