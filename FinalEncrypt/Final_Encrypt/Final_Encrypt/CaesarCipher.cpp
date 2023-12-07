#include <iostream>
#include <fstream>
#include <string>
#include "CaesarCipher.h"
#include <cstdlib>
using namespace std;

string CaesarCipher::encrypt(const string& text) const {
    string result = text;
    for (char& c : result) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = ((c - base + shift) % 26) + base;
        }
    }
    return result;
}

string CaesarCipher::decrypt(const string& text) const {
    string result = text;
    for (char& c : result) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = ((c - base + (26 - shift)) % 26) + base;
        }
    }
    return result;
}

string CaesarCipher::getEncodedScheme() const {
    return "CaesarCipher";
}