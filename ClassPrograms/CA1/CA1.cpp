//Miguel Angel Gonzalez Mauricio
//compares a string by removing w/s and converting to lc
#include<iostream>
#include "HeaderCA1.h"
#include <cctype>

using namespace std;

int main() {
	int size = 100;
	char* input = new char[size];
	for (int i = 0; i < size; i++) {
		*input = '\0';
	}
	cout << "Input a string: ";
	cin.getline(input, size);
	convert(input, strlen(input));
	cout << input << endl;
	delete[] input;
}
void convert(char* str, int size) {
	// Convert to lc
	for (int i = 0; i < size; i++) {
		*(str + i) = tolower(*(str + i));
	}
	char* tmp = new char[size];
	char* j = tmp;
	for (int i = 0; i < size; i++) {
		if (!isspace(*(str + i))) {
			*j = *(str + i);
			j++;
		}
	}
	*j = '\0';
	j = tmp;
	while (*j != '\0') {
		*str = *j;
		j++;
		str++;
	}
	*str = '\0';
}
