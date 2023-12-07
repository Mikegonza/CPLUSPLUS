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

    string readFile(const string& filename);

    //^^ Opens the specified file for reading and reads its content into a string. If the file cannot be opened, it outputs an error message and returns an empty string.

    bool writeFile(const string& filename, const string& content); 

    //^^ Opens the specified file for writing and writes the provided content into the file. If the file cannot be created, it outputs an error message and returns false.

public:

    void encryptFile(const string& filename, Encryption& encryption);

    //^^ Reads the content of the specified file.
    // If the file is empty or cannot be read, it returns.
    // Uses the provided Encryption object to encrypt the file content.
    // Prepends the encoded scheme and a colon (:) to the encrypted text and saves it in a new file named "encrypted_" + filename.
    // Prints a success message if the encryption and file writing were successful.

    void decryptFile(const string& filename);

    //^^ Reads the content of the specified file.
    // If the file is empty or cannot be read, it returns.
    // Searches for a colon (:) in the content to separate the encoded encryption scheme from the encrypted text.
    // Based on the identified encryption scheme:
    // Creates a new instance of CaesarCipher or XORCipher (assuming specific parameters for demonstration).
    // Decrypts the encrypted text using the identified encryption method.
    // Deletes the dynamically allocated encryption object to prevent memory leaks.
    // Saves the decrypted text into a new file named "decrypted_" + filename.
    // Prints a success message if the decryption and file writing were successful.
};
