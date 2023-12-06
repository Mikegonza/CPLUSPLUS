#pragma once
#ifndef CAESARCIPHER_H
#define CAESARCIPHER_H

#include <string>
using namespace std;

class CaesarCipher {
public:
    string encrypt(const string& text, int shift);
    string decrypt(const string& text, int shift);
};

#endif // CAESARCIPHER_H
