#include <iostream>
#include <string>
#include "CaesarCipher.h"
#include "XOREncryption.h"
#include "FileHandler.h"
using namespace std;

int main() {
    // Main program logic with switch statement for user choice
    // Call the appropriate encryption/decryption functions
    // File handling
    // Auto-detection of encryption scheme
    int choice;
    string filename, content, encrypted, decrypted;
    CaesarCipher caesar;
    XOREncryption xorEncrypt;
    int caesarShift;
    char xorKey;

    cout << "Select encryption method:\n";
    cout << "1. Caesar Cipher\n";
    cout << "2. XOR Encryption\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    cout << "Enter the name of the file: ";
    cin >> filename;

    content = FileHandler::readFile(filename);

    switch (choice) {
    case 1: // Caesar Cipher
        cout << "Enter the shift value for Caesar Cipher: ";
        cin >> caesarShift;

        encrypted = caesar.encrypt(content, caesarShift);
        decrypted = caesar.decrypt(encrypted, caesarShift);

        FileHandler::writeFile(filename + "_encrypted_caesar.txt", encrypted);
        FileHandler::writeFile(filename + "_decrypted_caesar.txt", decrypted);

        cout << "Caesar Cipher encryption and decryption complete. Files created.\n";
        break;

    case 2: // XOR Encryption
        cout << "Enter a single character key for XOR Encryption: ";
        cin >> xorKey;

        encrypted = xorEncrypt.encrypt(content, xorKey);
        decrypted = xorEncrypt.decrypt(encrypted, xorKey);

        FileHandler::writeFile(filename + "_encrypted_xor.txt", encrypted);
        FileHandler::writeFile(filename + "_decrypted_xor.txt", decrypted);

        cout << "XOR encryption and decryption complete. Files created.\n";
        break;

    default:
        cout << "Invalid choice!\n";
    }

    return 0;
}
