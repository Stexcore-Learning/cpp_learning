/**
 * Performs byte-wise addition of two fixed-size numeric arrays simulating multi-byte integers.
 * The sum is stored in-place in a third array, and overflow is detected if the result exceeds byte capacity.
 * The result is printed in hexadecimal format for inspection.
 *
 * Steven Aray – July 8, 2025 – 8:57 PM
 */
#include <iostream>
#include <math.h>

const int NUMBERMAX = 2;
typedef unsigned char number[NUMBERMAX];

bool SumNumber(const number, const number, number);
void PrintNumber(const number);

int main(void) {
    number num = {0xff, 0x0f};
    number num2 = {0xff, 0x0f};

    std::cout << "(" << SumNumber(num, num2, num) << ") ";
    PrintNumber(num);
}

// Function to print each byte as hex, from most to least significant
void PrintNumber(const number value) {
    std::cout << "0x";
    // Iterate in reverse to show high byte first
    for (int i = NUMBERMAX - 1; i >= 0; i--) {
        printf("%02X", value[i]);  // Print as two-digit hexadecimal
    }
    std::cout << std::endl;
}

bool SumNumber(const number a, const number b, number result) {
    int x, sum;
    bool overflow;

    for(x = 0; x < NUMBERMAX; x++) {
        sum = a[x] + b[x] + (int)overflow;
        overflow = sum > 0xff;
        if(overflow) sum -= 256; 
        result[x] = (unsigned char)sum;
    }

    return overflow;
}