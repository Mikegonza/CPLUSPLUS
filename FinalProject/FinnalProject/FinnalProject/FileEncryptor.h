#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Encryption.h"
#include "CaesarCipher.h"
#include "XORCipher.h"
using namespace std;

class FileEncryptor {
private:
    string readFile(const string& filename) {
        ifstream inputFile(filename);
        if (!inputFile) {
            cerr << "Error: Unable to open file!" << endl;
            return "";
        }

        string content((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
        inputFile.close();
        return content;
    }

    bool writeFile(const string& filename, const string& content) {
        ofstream outputFile(filename);
        if (!outputFile) {
            cerr << "Error: Unable to create file!" << endl;
            return false;
        }

        outputFile << content;
        outputFile.close();
        return true;
    }

public:
    void encryptFile(const string& filename, Encryption& encryption) {
        string content = readFile(filename);
        if (content.empty()) {
            return;
        }

        string encryptedText = encryption.encrypt(content);
        string encodedScheme = encryption.getEncodedScheme();

        string encryptedFileName = "encrypted_" + filename;
        if (writeFile(encryptedFileName, encodedScheme + ":" + encryptedText)) {
            cout << "File encrypted successfully and saved as " << encryptedFileName << endl;
        }
    }

    //Describe what the below program is doing

    void decryptFile(const string& filename) {
        string content = readFile(filename);
        if (content.empty()) {
            return;
        }

        string encodedScheme;
        string encryptedText;

        Encryption *encryption = nullptr;
        if (encodedScheme == "CaesarCipher") {
            encryption = new CaesarCipher(3); // Assuming Caesar Cipher with shift 3 for demonstration
        }
        else if (encodedScheme == "XORCipher") {
            encryption = new XORCipher('K'); // Assuming XOR Cipher with key 'K' for demonstration
        }
        else {
            cerr << "Error: Unknown encryption scheme!" << endl;
            return;
        }

        string decryptedText = encryption->decrypt(encryptedText);

        delete encryption;

        string decryptedFileName = "decrypted_" + filename;
        if (writeFile(decryptedFileName, decryptedText)) {
            cout << "File decrypted successfully and saved as " << decryptedFileName << endl;
        }
    }
};