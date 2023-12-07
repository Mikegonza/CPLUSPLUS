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

    //^^ Creates an instance of the FileEncryptor class named encryptor.

    string filename;
    cout << "Enter the file name: ";
    cin >> filename;

    //^^ Prompts the user to input a filename via the console.

    int choice;
    cout << "Choose encryption scheme:\n1. Caesar Cipher\n2. XOR Cipher\nEnter choice: ";
    cin >> choice;

    //^^ Asks the user to choose an encryption scheme (1 for Caesar Cipher, 2 for XOR Cipher).

    if (choice == 1) {
        CaesarCipher caesar(3);
        encryptor.encryptFile(filename, caesar);
    }

    //^^ If the choice is '1': Creates an instance of CaesarCipher with a shift value of 3.
    // Calls the encryptFile method of encryptor object, passing the filenameand the CaesarCipher instance to encrypt the file.

    else if (choice == 2) {
        XORCipher xorcypher('K');
        encryptor.encryptFile(filename, xorcypher);
    }

    //^^ If the choice is '2': Creates an instance of XORCipher with a key 'K'.
    // Calls the encryptFile method of encryptor object, passing the filenameand the XORCipher instance to encrypt the file.

    else {
        cout << "Invalid choice!" << endl;
        return 1;
    }

    //^^ If the user inputs any other choice, it displays "Invalid choice!" and exits the program with a return value of 1.

    encryptor.decryptFile("encrypted_" + filename);

    //^^ Regardless of the encryption choice made earlier, it attempts to decrypt the file by calling the decryptFile method 
    // of the encryptor object, passing the name of the file prefixed with "encrypted_".

    return 0;
}
