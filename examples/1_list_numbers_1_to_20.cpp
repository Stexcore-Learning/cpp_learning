/**
 * This program displays a list of numbers
 * in the range from 1 to 20 and
 * indicates whether each number is divisible by 3.
 * Steven Aray - Saturday, July 5, 2025 - 12:24 AM
 */
#include <iostream>

// Entry point of the application
int main(void) {

    // Loop from 1 to 20
    for(int number = 1; number <= 20; number++) {
        // Print to the console
        std::cout 
            << number
            << " " 
            << (number % 3 ? "Not divisible by 3" : "Divisible by 3") 
            << std::endl;
    }

    return 0;
}
