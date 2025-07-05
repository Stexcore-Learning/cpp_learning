/**
 * This program asks the user to input 10 numbers,
 * then calculates and displays the maximum, minimum,
 * and average value from the entered data.
 * Steven Aray – July 5, 2025 – 3:53 PM
 */
#include <iostream>

int main(void) {
    // Declare an array to store 10 integer numbers
    int arrNumbers[10];

    // Initialize 'mayor' to the smallest possible signed 32-bit integer (−2^31)
    int mayor = (int)0x80000000;

    // Initialize 'menor' to the largest possible signed 32-bit integer (2^31 − 1)
    int menor = 0x7FFFFFFF;

    // Initialize the sum accumulator
    int sum = 0;

    // Loop index
    int x;

    // Input: Read 10 values from the user and store them in the array
    for(x = 0; x < 10; x++) {
        std::cout << "Enter value #" << (x + 1) << ": ";
        std::cin >> arrNumbers[x];
    }

    // Process: Determine the maximum, minimum, and total sum
    for(x = 0; x < 10; x++) {
        if(mayor < arrNumbers[x]) mayor = arrNumbers[x];  // Update max value
        if(menor > arrNumbers[x]) menor = arrNumbers[x];  // Update min value
        sum += arrNumbers[x];                             // Add to sum
    }

    // Output: Display the maximum, minimum, and average (as a float)
    std::cout
        << "Maximum: " << mayor << std::endl
        << "Minimum: " << menor << std::endl
        << "Average: " << (sum / 10.f);  // Using 10.f to ensure float division
}
