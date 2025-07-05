/**
 * Displays the alphabet in uppercase and lowercase variations:
 * AbCdEfGhIjKlMnOpQrStUvWxYz
 * aBcDeFgHiJkLmNoPqRsTuVwXyZ
 * abCDefGHijKLmnOPqrSTuvWXyz
 * ABcdEFghIJklMNopQRstUVwxYZ
 * Steven Aray – Saturday, July 5, 2025 – 2:21 PM
 */
#include <iostream>
#include <cctype>

// Entry point of the application
int main(void) {
    // Declare alphabet character array
    char alphabet[27];
    const char baseChar = 'a';
    int x;

    // Fill array with alternating-case alphabet starting from 'A'
    for(x = 0; x < 26; x++) {
        alphabet[x] = (x % 2) ? (baseChar + x) : toupper(baseChar + x);
    }

    // Append null terminator to treat as a C-style string
    alphabet[x] = '\x00';

    // Print original pattern: AbCdEf...
    std::cout << alphabet << std::endl;

    // Invert each letter’s case (uppercase ↔ lowercase)
    x = 0;
    while(alphabet[x]) {
        alphabet[x] = isupper(alphabet[x]) 
            ? tolower(alphabet[x]) 
            : toupper(alphabet[x]);
        x++;
    }
    // Print inverted: aBcDeF...
    std::cout << alphabet << std::endl;

    // Apply alternating casing in blocks of two characters
    x = 0;
    while(alphabet[x]) {
        // Group into pairs: uppercase for groups 0, 2, 4... lowercase for 1, 3, 5...
        if((x / 2) % 2) {
            alphabet[x] = tolower(alphabet[x]);
        } else {
            alphabet[x] = toupper(alphabet[x]);
        }
        x++;
    }
    // Print block-patterned case: abCDef...
    std::cout << alphabet << std::endl;

    // Flip all letters again
    x = 0;
    while(alphabet[x]) {
        alphabet[x] = isupper(alphabet[x]) 
            ? tolower(alphabet[x]) 
            : toupper(alphabet[x]);
        x++;
    }
    // Final variation: ABcdEF...
    std::cout << alphabet << std::endl;

    return 0;
}
