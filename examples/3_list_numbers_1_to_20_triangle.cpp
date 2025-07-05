/**
 * This program displays a list of numbers
 * in a range from 1 to 20,
 * generating a triangular pattern like:
 * 
 * 1
 * 1 2
 * 1 2 3
 * 1 2 3 4
 * ...
 * 
 * Steven Aray – Saturday, July 5, 2025 – 12:35 AM
 */
#include <iostream>

// Application entry point
int main(void) {
    // Variable declarations
    int number, subNumber;

    // Loop from 1 to 20
    for(number = 1; number <= 20; number++) {

        // Inner loop to build the triangular pattern
        for(subNumber = 1; subNumber <= number; subNumber++) {
            
            // Print each number to the console
            std::cout << " " << subNumber;
        }

        // Print a newline after each row
        std::cout << std::endl;
    }

    return 0;
}
