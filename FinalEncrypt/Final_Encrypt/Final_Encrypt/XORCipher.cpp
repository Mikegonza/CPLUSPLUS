#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "XORCipher.h"
using namespace std;

string XORCipher::encrypt(const string& text) const {
    string result = text;
    for (char& c : result) {
        c ^= key;
    }
    return result;
}

string XORCipher::decrypt(const string& text) const {
    return encrypt(text);
}

string XORCipher::getEncodedScheme() const {
    return "XORCipher";
}