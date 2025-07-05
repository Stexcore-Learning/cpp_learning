/**
 * This program displays the alphabet
 * first in lowercase and then in uppercase.
 * Steven Aray – July 5, 2025 – 2:03 PM
 */
#include <iostream>

// Entry point of the application
int main(void) {
    // Declare variable
    char letter;

    // Display header for lowercase alphabet
    std::cout << "Lowercase alphabet:" << std::endl;
    
    // Print lowercase letters
    for(letter = 'a'; letter <= 'z'; letter++) {
        std::cout << letter;
    }

    // Display header for uppercase alphabet
    std::cout << std::endl << std::endl << "Uppercase alphabet:" << std::endl;

    // Print uppercase letters
    for(letter = 'A'; letter <= 'Z'; letter++) {
        std::cout << letter;
    }

    // Display closing message
    std::cout << std::endl << std::endl << "Exiting application...";

    return 0;
}
