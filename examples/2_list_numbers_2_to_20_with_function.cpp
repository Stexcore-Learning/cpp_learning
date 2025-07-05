/**
 * This program displays a list of numbers
 * in the range from 1 to 20 and
 * indicates whether each number is divisible by 3.
 * This time, it uses a function and a while loop.
 * Steven Aray - Saturday, July 5, 2025 - 12:28 AM
 */
#include <iostream>

/**
 * Function prototype to check divisibility
 */
bool Divisible(int value);

// Entry point of the application
int main(void) {

    // Declare a variable for counting
    int number = 1;
    
    // Loop from 1 to 20
    while(number <= 20) {

        // Output to the console
        std::cout 
            << number
            << " " 
            << (Divisible(number) ? "Not divisible by 3" : "Divisible by 3") 
            << std::endl;

        // Increment number
        number++;
    }

    return 0;
}

// Function definition to check divisibility
bool Divisible(int value) {
    return value % 3;
}
