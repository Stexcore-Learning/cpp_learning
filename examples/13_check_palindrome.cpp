/**
 * This program tests whether a given text is a palindrome,
 * meaning it reads the same forwards and backwards.
 * It uses simple character comparison without modifying the input.
 * Returns true if the text has at least 2 characters and is symmetrical.
 * Steven Aray – July 5, 2025 – 5:53 PM
 */
#include <iostream>
#include <string.h>

// Function that checks if a string is a palindrome
bool Palidromo(const char* text);

int main(void) {
    // Sample input strings to test
    const char 
        *text1 = "otto", 
        *text2 = "anitalavalatina", 
        *text3 = "dabalearrozalazorraelabad", 
        *text4 = "Texting";

    // Test and display results
    std::cout 
        << text1 << " = " << Palidromo(text1) << std::endl
        << text2 << " = " << Palidromo(text2) << std::endl
        << text3 << " = " << Palidromo(text3) << std::endl
        << text4 << " = " << Palidromo(text4) << std::endl;
}

// Function that returns true if the given string is a palindrome
bool Palidromo(const char* text) {
    int length = strlen(text), x, y;

    // Compare characters symmetrically from both ends
    for(x = 0; x < (length / 2); x++) {
        y = length - x - 1;

        // If mismatch is found, it's not a palindrome
        if(text[x] != text[y]) {
            return false;
        }
    }

    // Return true only for valid palindromes with at least 2 characters
    return length >= 2;
}
