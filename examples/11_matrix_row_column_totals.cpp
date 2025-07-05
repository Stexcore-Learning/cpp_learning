/**
 * This program allows the user to fill a 5x5 matrix with numbers,
 * then displays the matrix in column-major order while showing
 * the sum of each column next to it.
 * After that, it prints the total of each row aligned underneath.
 * The grid uses fixed-width cell formatting.
 * Steven Aray – July 5, 2025 – 5:35 PM
 */

#include <iostream>
#include <stdio.h>

// Function to print a number with fixed-width cell spacing
void printCell(int value);

int main(void) {
    int arrNumbers[5][5];  // 5x5 array to store numbers
    int x, y, sum;

    // Prompt the user to fill the matrix with values
    for(x = 0; x < 5; x++) {
        for(y = 0; y < 5; y++) {
            std::cout << "Enter number[" << x << "][" << y << "]: ";
            std::cin >> arrNumbers[x][y];
        }
    }

    // Print header for results table
    std::cout 
        << "========================================" << std::endl
        << " Result" << std::endl
        << "========================================" << std::endl;

    // Print each column and its total (column-wise view)
    for(y = 0; y < 5; y++) {
        sum = 0;
        for(x = 0; x < 5; x++) {
            sum += arrNumbers[x][y];      // Add current value to column sum
            printCell(arrNumbers[x][y]);  // Print the current cell
        }
        std::cout << " = ";  // Indicate the total
        printCell(sum);      // Print column total
        std::cout << std::endl;
    }

    // Print horizontal line to separate section
    std::cout << "========================================" << std::endl;

    // Print the sum of each row aligned beneath the grid
    for(x = 0; x < 5; x++) {
        sum = 0;
        for(y = 0; y < 5; y++) {
            sum += arrNumbers[x][y];  // Sum values in the current row
        }
        printCell(sum);  // Print the row total
    }

    return 0;
}

// Function that formats a number into a fixed-width 8-character cell
void printCell(int value) {
    static char texto[8];  // Buffer to hold the string representation

    sprintf(texto, "%i", value);  // Convert the number to string
    int length = strlen(texto);   // Get the string length

    // Print each character followed by padding spaces to ensure 8-char width
    for(int x = 0; x < 8; x++) {
        if(x < length) std::cout << texto[x];
        else std::cout << " ";
    }
}
