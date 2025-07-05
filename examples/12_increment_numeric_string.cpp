/**
 * This program demonstrates how to increment a numeric string
 * stored in a fixed-size char array (max 9 digits + null terminator).
 * It handles overflow manually, similar to a string-based counter.
 * Steven Aray – July 5, 2025 – 5:42 PM
 */

#include <iostream>
#include <cctype>
#include <string>

// Function to increment a numeric string in-place
bool Increment(char number[10]);

int main(void) {
    // Define sample numeric strings (up to 9 digits)
    char number1[10] = "999999999";   // Will overflow to "000000000"
    char number2[10] = "3423";        // Will become "3424"
    char number3[10] = "00002323";    // Will become "00002324"

    // Display and increment number1
    std::cout << number1 << " => ";
    Increment(number1);
    std::cout << number1 << std::endl;

    // Display and increment number2
    std::cout << number2 << " => ";
    Increment(number2);
    std::cout << number2 << std::endl;

    // Display and increment number3
    std::cout << number3 << " => ";
    Increment(number3);
    std::cout << number3 << std::endl;

    return 0;
}

// Function that increments a char array representing a decimal number
bool Increment(char number[10]) {
    bool isDigit = false;
    int length = 0;

    // Validate that all characters are digits
    while(number[length]) {
        isDigit = isdigit(number[length++]);
        if(!isDigit) break;
    }

    if(isDigit) {
        bool overflow = false;

        // Start incrementing from the rightmost digit
        for(int x = length - 1; x >= 0; x--) {
            if(++number[x] > '9') {
                number[x] = '0';     // Carry the overflow
                overflow = true;
            }
            else {
                overflow = false;    // No carry needed; done
                break;
            }
        }

        // If full overflow occurred and we have room, shift digits to make space for '1'
        if(overflow && length < 9) {
            char temp = number[0], temp2;
            number[0] = '1';

            for(int x = 0; x < 9; x++) {
                temp2 = number[x + 1];
                number[x + 1] = temp;
                temp = temp2;
            }
        }
    }

    return isDigit;  // Return whether the input was valid digits
}
