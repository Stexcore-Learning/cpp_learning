/**
 * This program allows the user to enter 10 numbers,
 * then displays them, sorts them in ascending order,
 * displays them again, then sorts them in descending order
 * and displays them one last time.
 * Steven Aray – July 5, 2025 – 4:31 PM
 */
#include <iostream>

// Global array to hold 10 numbers
int arrNumbers[10];

// Enumeration for ordering modes
enum OrderType { ASC, DESC };

// Function prototypes
void printArrNumbers();
void orderArrNumbers(OrderType);

// Application entry point
int main(void) {
    int x;

    // Prompt the user to input 10 numbers
    for(x = 0; x < 10; x++) {
        std::cout << "Enter value #" << (x + 1) << ": ";
        std::cin >> arrNumbers[x];
    }

    // Show the original array
    printArrNumbers();

    // Sort in ascending order and display
    std::cout << "Sorting in ASC order" << std::endl;
    orderArrNumbers(ASC);
    printArrNumbers();

    // Sort in descending order and display
    std::cout << "Sorting in DESC order" << std::endl;
    orderArrNumbers(DESC);
    printArrNumbers();
}

// Function to sort the array using bubble sort based on the desired order
void orderArrNumbers(OrderType order) {
    int x, y, temp;
    bool shouldSwap;

    for(x = 0; x < 10; x++) {
        for(y = 0; y < (10 - x - 1); y++) {
            // Determine if a swap is needed based on order type
            shouldSwap = (
                order == DESC ?
                    (arrNumbers[y] < arrNumbers[y + 1]) :
                    (arrNumbers[y] > arrNumbers[y + 1])
            );

            // Perform swap if necessary
            if(shouldSwap) {
                temp = arrNumbers[y];
                arrNumbers[y] = arrNumbers[y + 1];
                arrNumbers[y + 1] = temp;
            }
        }
    }
}

// Function to print the contents of the array
void printArrNumbers() {
    std::cout << "[";
    for(int x = 0; x < 10; x++) {
        if(x) std::cout << ", ";
        std::cout << arrNumbers[x];
    }
    std::cout << "]" << std::endl;
}
