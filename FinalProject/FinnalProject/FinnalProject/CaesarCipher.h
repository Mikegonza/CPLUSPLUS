
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Encryption.h"
using namespace std;

class CaesarCipher : public Encryption {
private:
    int shift;

public:
    CaesarCipher(int _shift) : shift(_shift) {}

    string encrypt(const string& text) const override {
        string result = text;
        for (char& c : result) {
            if (isalpha(c)) {
                char base = isupper(c) ? 'A' : 'a';
                c = ((c - base + shift) % 26) + base;
            }
        }
        return result;
    }

    string decrypt(const string& text) const override {
        return encrypt(text);
    }

    string getEncodedScheme() const override {
        return "CaesarCipher";
    }
};
