/**
 * This program allows the user to input a number
 * and decompose it into its prime factors,
 * perform the necessary calculations, and repeat
 * until the user no longer wants to continue.
 * Steven Aray – Sat, July 5 – 1:40 AM
 */
#include <iostream>

// Application entry point
int main(void) {
    // Declare variable to store the user input
    int value;
    char input[12];

    do {
        // Prompt the user to enter a value
        std::cout << "Enter a number to decompose: "; 
        std::cin >> value;

        // Display the result header
        std::cout << "Result: " << std::endl << std::endl;

        // Perform the prime factorization and print
        int factor = 2;
        while(value >= (factor * factor)) {

            // Check if divisible by current factor
            if(!(value % factor)) {
                // Print the factor and divide the value
                std::cout << factor << " * ";
                value /= factor;
            }
            // Increment factor (skip even numbers after 2)
            factor += factor == 2 ? 1 : 2;
        }
        // Print the remaining prime and line break
        std::cout << value << std::endl << std::endl;

        // Ask if user wants to decompose another number
        std::cout << "Type 'y' to decompose another number: ";
        std::cin >> input;
    }
    while(input[0] == 'y' || input[0] == 'Y');

    // Display application exit message
    std::cout << "Closing application..."; 

    return 0;
}
