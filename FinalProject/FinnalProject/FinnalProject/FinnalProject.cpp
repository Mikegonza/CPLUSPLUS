// FinnalProject.cpp 
#include <iostream>
using namespace std;

#include <iostream>
#include <fstream>
#include <cstdlib>

/**
   This program encrypts a file using the Caesar cipher.
*/
char encrypt(char ch, int key);

int main(int argc, char* argv[])
{
    const int DEFAULT_KEY = 3;
    int key = DEFAULT_KEY;
    string inFile = "";
    string outFile = "";
    int files = 0; // Number of command line arguments that are files

    for (int i = 1; i < argc; i++)
    {
        string arg = argv[i];
        if (arg.at(0) == '-')
        {
            // It is a command line option

            char option = arg.at(1);
            if (option == 'd') { key = -key; }
            else { cerr << "Invalid option\n"; return 1; }
        }
        else
        {
            // It is a file name

            files++;
            if (files == 1) { inFile = arg; }
            else if (files == 2) { outFile = arg; }
        }
    }
    if (files != 2) { cerr << "Usage: " << argv[0] << " [-d] infile outfile\n"; return 1; }

    ifstream in(inFile);
    if (!in)
    {
        cerr << "Cannot open input file: " << inFile << "\n";
        return 1;
    }

    ofstream out(outFile);
    if (!out)
    {
        cerr << "Cannot open output file: " << outFile << "\n";
        return 1;
    }

    char ch;
    while (in.get(ch))
    {
        char to = encrypt(ch, key);
        out.put(to);
    }

    in.close();
    out.close();

    return 0;
}

/**
   Encrypts upper- and lowercase characters by shifting them
   according to a key.
   @param ch the letter to be encrypted
   @param key the encryption key
   @return the encrypted letter
*/
char encrypt(char ch, int key)
{
    int base = 0;
    if ('A' <= ch && ch <= 'Z') { base = 'A'; }
    else if ('a' <= ch && ch <= 'z') { base = 'a'; }
    else { return ch; } // Not a letter
    int offset = ch - base + key;
    const int LETTERS = 26; // Number of letters in the Roman alphabet
    if (offset >= LETTERS) { offset = offset - LETTERS; }
    else if (offset < 0) { offset = offset + LETTERS; }
    return static_cast<char>(base + offset);
}
