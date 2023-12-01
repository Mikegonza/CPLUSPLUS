#include <iostream>
#include <fstream>
#include <string>
#include "Encryption.h"
#include "CaesarCipher.h"
#include "XORCipher.h"
#include "FileEncryptor.h"
using namespace std;

int main() {
    FileEncryptor encryptor;

    string filename;
    cout << "Enter the file name: ";
    cin >> filename;

    int choice;
    cout << "Choose encryption scheme:\n1. Caesar Cipher\n2. XOR Cipher\nEnter choice: ";
    cin >> choice;

    if (choice == 1) {
        CaesarCipher caesar(3);
        encryptor.encryptFile(filename, caesar);
    }
    else if (choice == 2) {
        XORCipher xorcypher('K');
        encryptor.encryptFile(filename, xorcypher);
    }
    else {
        cout << "Invalid choice!" << endl;
        return 1;
    }

    encryptor.decryptFile("encrypted_" + filename);

    return 0;
}