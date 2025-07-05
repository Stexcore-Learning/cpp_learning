/**
 * This program displays a list of numbers
 * in a range from 1 to 23,
 * alternating additions and subtractions—
 * where it adds 4 and subtracts 2 on each iteration
 * until it reaches the number 23, producing a result like:
 * 
 * > 1, 5, 3, 7, 5, 9, 7, 11, 9, 13, 11, 15, 13, 17, 15, 19, 17, 21, 19, 23.
 * 
 * Steven Aray – Saturday, July 5, 2025 – 12:51 AM
 */
#include <iostream>

// Application entry point
int main(void) {
    // Declare the number to iterate with
    int number = 1;
    // Declare the type of operation (true = add 4, false = subtract 2)
    bool sumOp = true;

    // Print the first number
    std::cout << "> " << number;

    // Use a do-while loop to iterate
    // (Not sure do-while is the best fit here...
    // but hey, that was the assignment :D)
    do {
        // Apply addition or subtraction based on operation
        number += sumOp ? 4 : -2;
        // Toggle the operation for next round
        sumOp = !sumOp;

        // Print to the screen
        std::cout << ", " << number;
    } 
    while(number < 23);

    // Print a final period
    std::cout << '.';

    return 0; // Respond OK
}
