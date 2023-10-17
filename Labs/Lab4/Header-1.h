/* COSC 1437 - Lab 4 (Miguel Angel Gonzalez Mauricio)
   Miguel Angel Gonzalez Mauricio
   Programming Fundamentals II
   COSC-1437
   Instructor: Brian Koontz
*/

#pragma once
#include <string>
#include <fstream>
#include <streambuf>
using namespace std;

int indexWordFile(streamoff index[], string filename, ifstream& input);
bool linearSearch(streamoff index[], int size, string word, ifstream& input);
bool binarySearch(streamoff index[], int size, string word, ifstream& input);
