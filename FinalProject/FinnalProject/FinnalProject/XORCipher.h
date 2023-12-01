#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Encryption.h"
using namespace std;

class XORCipher : public Encryption {
private:
    char key;

public:
    XORCipher(char _key) : key(_key) {}

    string encrypt(const string& text) const override {
        string result = text;
        for (char& c : result) {
            c ^= key;
        }
        return result;
    }

    string decrypt(const string& text) const override {
        return encrypt(text);
    }

    string getEncodedScheme() const override {
        return "XORCipher";
    }
};
