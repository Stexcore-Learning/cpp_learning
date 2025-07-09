/**
 * Adds two numeric strings digit by digit, storing the result in-place within the first string.
 * The operation mimics manual addition, handling overflow and digit shifts.
 * Note: The maximum length of each string is defined by STRINGMAX.
 *
 * Steven Aray – July 8, 2025 – 7:16 PM
 */
#include <iostream>
#include <stdio.h>
#include <string>

const int STRINGMAX = 5;

typedef char string[STRINGMAX];  // Defines a fixed-size string type

// Function that sums two numeric strings and stores result in `a`
bool SumString(string a, const string b);

int main(void) {
    string num1 = "999";   // First operand
    string num2 = "9999";  // Second operand

    // Display result of addition
    std::cout << num1 << " + " << num2 << " = (" << SumString(num1, num2) << ") " << num1;
}

// Performs digit-wise addition of two strings, simulating integer addition
bool SumString(string a, const string b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    char la, lb;

    int len_max, len_max_temp;
    bool overflow = false;

    // Determine max length of both strings
    len_max = len_max_temp = std::max(len_a, len_b);

    // Null-terminate at the end of the result buffer
    a[len_max] = 0;

    // Perform digit-by-digit addition from least to most significant
    while (--len_max >= 0) {
        // If out of bounds, treat missing digits as zero
        la = (--len_a >= 0) ? a[len_a] : '0';
        lb = (--len_b >= 0) ? b[len_b] : '0';

        // Sum digits and include any previous carry
        a[len_max] = la + lb - '0' + (char)overflow;

        // Detect and handle carry if sum exceeds '9'
        overflow = (a[len_max] > '9');
        if (overflow) {
            a[len_max] -= 10;  // Adjust result digit after overflow
        }
    }

    // If final carry remains, try shifting digits to insert leading '1'
    if (overflow) {
        len_max = len_max_temp + 1;
        if (len_max < STRINGMAX) {
            while (len_max > 0) {
                a[len_max] = a[len_max - 1];  // Shift digits right
                len_max--;
            }
            a[len_max] = '1';     // Insert carry digit
            overflow = false;
        }
    }

    return overflow;  // Indicates if overflow could not be handled
}