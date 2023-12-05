#pragma once
#ifndef XORENCRYPTION_H
#define XORENCRYPTION_H

#include <string>
using namespace std;

class XOREncryption {
public:
    string encrypt(const string& text, char key);
    string decrypt(const string& text, char key);
};

#endif // XORENCRYPTION_H
