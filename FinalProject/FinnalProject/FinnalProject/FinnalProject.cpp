// FinnalProject.cpp 
#include <iostream>
using namespace std;
//These lines include necessary header files for input/output operations and standard library functions.
#include <iostream>
#include <fstream>
#include <cstdlib>

/**
   This program encrypts a file using the Caesar cipher.
*/
//This line declares the function encrypt which will be defined later in the code. 
//It's a forward declaration, informing the compiler about the function's signature.
char encrypt(char ch, int key);

//This line begins the main function, the entry point of the program. 
//argc is the number of command-line arguments, and argv is an array containing those arguments.
int main(int argc, char* argv[])
{
    //These lines initialize variables for the encryption key, input file name, output file name, and the count of file arguments.
    const int DEFAULT_KEY = 3;
    int key = DEFAULT_KEY;
    string inFile = "";
    string outFile = "";
    int files = 0; // Number of command line arguments that are files

    //This loop iterates over the command-line arguments starting from index 1 
    //(index 0 is the program name) and assigns each argument to the variable arg.
    for (int i = 1; i < argc; i++)
    {
        string arg = argv[i];
        //This block checks if the argument is a command-line option (starts with '-'). If it is,
        //it checks the option and adjusts the encryption key accordingly.
        //If an invalid option is provided, it prints an error message to cerr and exits with an error code.
        if (arg.at(0) == '-')
        {
            // It is a command line option
            char option = arg.at(1);
            if (option == 'd') { key = -key; }
            else { cerr << "Invalid option\n"; return 1; }
        }
        //If the argument is not a command-line option, it is considered a file name. 
        //The program keeps track of the input and output file names based on the order of appearance.
        else
        {
            // It is a file name
            files++;
            if (files == 1) { inFile = arg; }
            else if (files == 2) { outFile = arg; }
        }
    }
    //Checks if exactly two file arguments are provided. If not, it prints a usage message to cerr and exits with an error code.
    if (files != 2) { cerr << "Usage: " << argv[0] << " [-d] infile outfile\n"; return 1; }

    //Opens the input file using ifstream and checks if the file is successfully opened. If not, it prints an error message and exits with an error code.
    ifstream in(inFile);
    if (!in)
    {
        cerr << "Cannot open input file: " << inFile << "\n";
        return 1;
    }

    //Opens the output file using ofstream and checks if the file is successfully opened. If not, it prints an error message and exits with an error code.
    ofstream out(outFile);
    if (!out)
    {
        cerr << "Cannot open output file: " << outFile << "\n";
        return 1;
    }

    //Reads characters from the input file one by one using in.get(ch).
    //For each character, it encrypts using the encrypt function and writes the result to the output file using out.put(to).
    char ch;
    while (in.get(ch))
    {
        char to = encrypt(ch, key);
        out.put(to);
    }

    //Closes the input and output files and returns 0 to indicate successful program execution.
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
    const int LETTERS = 26; // Number of letters in the alphabet
    if (offset >= LETTERS) { offset = offset - LETTERS; }
    else if (offset < 0) { offset = offset + LETTERS; }
    return static_cast<char>(base + offset);
}
