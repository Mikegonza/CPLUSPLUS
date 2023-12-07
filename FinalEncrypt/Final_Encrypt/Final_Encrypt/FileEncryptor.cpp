#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "FileEncryptor.h"
using namespace std;

string FileEncryptor::readFile(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error: Unable to open file!" << endl;
        return "";
    }

    string content((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
    inputFile.close();
    return content;
}

bool FileEncryptor::writeFile(const string& filename, const string& content) {
    ofstream outputFile(filename);
    if (!outputFile) {
        cerr << "Error: Unable to create file!" << endl;
        return false;
    }

    outputFile << content;
    outputFile.close();
    return true;
}

void FileEncryptor::encryptFile(const string& filename, Encryption& encryption) {
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

    ifstream file(encryptedFileName); {

        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                cout << line << endl;
            }
            file.close();
        }
        else {
            std::cout << "Unable to open the file." << endl;
        }
    }
}

void FileEncryptor::decryptFile(const string& filename) {
    string content = readFile(filename);
    if (content.empty()) {
        return;
    }

    size_t colonPos = content.find(':');
    if (colonPos == string::npos) {
        cerr << "Error: Invalid encrypted file format!" << endl;
        return;
    }

    string encodedScheme = content.substr(0, colonPos);
    string encryptedText = content.substr(colonPos + 1);

    Encryption* encryption = nullptr;
    if (encodedScheme == "CaesarCipher") {
        encryption = new CaesarCipher(3);
    }
    else if (encodedScheme == "XORCipher") {
        encryption = new XORCipher('K');
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
        ifstream file(decryptedFileName); {

            if (file.is_open()) {
                string line;
                while (getline(file, line)) {
                    cout << line << endl;
                }
                file.close();
            }
            else {
                cout << "Unable to open the file." << endl;
            }
        }
    }
}