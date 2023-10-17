//Miguel Angel Gonzalez Mauricio


#include "palindrome.h"

bool isPalindrome(const char* input, int size) {
    // Function to check if a string is a palindrome.

    // Initialize pointers to the beginning and end of the string.
    const char* start = input;
    const char* end = input + size - 1;

    // Loop until the start and end pointers meet.
    while (start < end) {
        // Skip non-alphanumeric characters from the start.
        while (!isalnum(*start) && start < end) {
            start++;
        }

        // Skip non-alphanumeric characters from the end.
        while (!isalnum(*end) && start < end) {
            end--;
        }

        // Compare the characters at the start and end positions (ignoring case).
        if (tolower(*start) != tolower(*end)) {
            return false; // Not a palindrome.
        }

        // Move the pointers towards each other.
        start++;
        end--;
    }

    return true; // It's a palindrome.
}
