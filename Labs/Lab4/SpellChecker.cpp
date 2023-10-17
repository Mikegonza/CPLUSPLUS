/* COSC 1437 - Lab 4 
   Miguel Angel Gonzalez Mauricio
   Programming Fundamentals II
   COSC-1437
   Instructor: Brian Koontz
/*

* Linear Search:
  Linear search is a basic searching algorithm that iterates through all the elements in the array until it finds the target element or reaches the end of the array.
  In the given code, the linear search function iterates through the index array, reads the corresponding words from the file, and compares them with the target word.
* 
* Binary Search:
  Binary search is an efficient searching algorithm for sorted arrays. It works by repeatedly dividing the search interval in half until the target element is found or the interval becomes empty.
  In the given code, the binary search function performs a binary search on the index array, reads the corresponding words from the file, and compares them with the target word.
*/

/*
  If the word file is large and sorted, binary search will offer much better performance compared to linear search. However,
  if the file is small or unsorted, the performance difference between the two methods might not be as noticeable, and both methods would work reasonably well.
*/

#include "Header.h"
#include <iostream>
using namespace std;

// This array will hold > 64KB and needs to be declared globally
// (alternatively, we could create it on the heap using dynamic allocation).
// The size of streamoff is implementation-dependent.
streamoff index[400000];
int main() {
	int indexSize = -1;
	string filename;
	int option;
	ifstream input;
	do {
		cout << "1. Index the word file" << endl;
		cout << "2. Linear search" << endl;
		cout << "3. Binary search" << endl;
		cout << "4. Quit" << endl;
		cin >> option;
		if (option == 1) {
			cout << "Enter filename: ";
			cin >> filename;
			indexSize = indexWordFile(index, filename, input);
			cout << "Number of words indexed: " << indexSize << endl;
		}
		else if (option == 2) {
			string word;
			cout << "Enter word: ";
			cin >> word;
			bool result = linearSearch(index, indexSize, word, input);
			if (result) {
				cout << "Word found!" << endl;
			}
			else {
				cout << "Word not found..." << endl;
			}
		}
		else if (option == 3) {
			string word;
			cout << "Enter word: ";
			cin >> word;
			bool result = binarySearch(index, indexSize, word, input);
			if (result) {
				cout << "Word found!" << endl;
			}
			else {
				cout << "Word not found..." << endl;
			}
		}
		else {
			input.close();
			exit(0);
		}
	} while (true);
}

int indexWordFile(streamoff index[], string filename, ifstream& input) {
	// Reading files created in Unix on a Windows platform causes 
	// strange errors due to line endings (Unix: \n, Windows: \r\n).
	// Opening files as binary eliminates any type of line ending
	// translation.
	input.open(filename, ios::in | ios::binary);
	// Always check for errors when opening files
	if (input.fail() || input.bad()) {
		cout << "***Error opening file!***" << endl;
		return -1;
	}

	int i = 0;
	index[i] = 0L;
	i++;
	string dummy;
	getline(input, dummy);
	while (!input.eof()) {
		index[i] = input.tellg();
		if (i % 100000 == 0) {
			cout << i << "\r";
		}
		i++;
		getline(input, dummy);
	}
	// Clear the EOF flag on the input fstream object
	input.clear();
	return i + 1;
}

bool linearSearch(streamoff index[], int size, string word, ifstream& input) {
	// Your code here!
	for (int i = 0; i < size - 1; i++) {
		input.seekg(index[i]);
		string dictionaryWord;
		getline(input, dictionaryWord);
		if (dictionaryWord == word) {
			return true;  // Word found
		}
	}
	return false;
}

bool binarySearch(streamoff index[], int size, string word, ifstream& input) {
	// Your code here!
	int left = 0;
	int right = size - 1;	

	while (left <= right) {
		int mid = left + (right-left) / 2;
		input.seekg(index[mid]);
		string dictionaryWord;
		getline(input, dictionaryWord);

		if (dictionaryWord == word) {
			return true;  // Word found
		}
		else if (dictionaryWord < word) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	return false;
}