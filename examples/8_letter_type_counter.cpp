/**
 * Allows the user to type anything until they enter '&'
 * and counts the total number of Consonants, Vowels, Digits,
 * Punctuation Marks, Uppercase letters, Lowercase letters,
 * Spaces, and any other characters.
 * Steven Aray – July 5, 2025 – 2:53 PM
 */
#include <stdio.h>
#include <cctype> 

int main(void) {
    char letter;

    // Counters for each type of character
    int nDigits = 0;
    int nPunctuation = 0;
    int nUppercase = 0;
    int nLowercase = 0;
    int nSpaces = 0;
    int nVowels = 0;
    int nConsonants = 0;
    int nOther = 0;

    // Prompt the user for input
    printf("Type whatever you like. To stop, type '&':\n");

    // Read characters one by one until '&' is entered
    while((letter = getchar()) != '&') {
        if(isalpha(letter)) {  // If it's an alphabetic letter
            if(isupper(letter)) {
                nUppercase++;  // Count uppercase letters
            }
            else if(islower(letter)) {
                nLowercase++;  // Count lowercase letters
            }

            // Check if it's a vowel or consonant
            switch (tolower(letter)) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    nVowels++;
                    break;
                default:
                    nConsonants++;
                    break;
            }
        }
        else if(isdigit(letter)) {
            nDigits++;  // Count numeric digits
        }
        else if(ispunct(letter)) {
            nPunctuation++;  // Count punctuation marks like . , ! etc.
        }
        else if(isspace(letter)) {
            nSpaces++;  // Count spaces, tabs, newlines
        }
        else {
            nOther++;  // Any other unidentified character
        }
    }
    
    // Display final counts
    printf("Summary =============\n");
    printf("Consonants: %i\n", nConsonants);
    printf("Vowels: %i\n", nVowels);
    printf("Digits: %i\n", nDigits);
    printf("Punctuation: %i\n", nPunctuation);
    printf("Uppercase: %i\n", nUppercase);
    printf("Lowercase: %i\n", nLowercase);
    printf("Spaces: %i\n", nSpaces);
    printf("Other: %i\n", nOther);
    
    return 0;
}