/**
 * Validates and prints a list of hardcoded dates using compact bitfield storage.
 * Each date includes a day, month, and a year offset from 1960.
 * The program iterates through five Date entries, prints each one,
 * and determines whether it's valid based on leap year logic and calendar constraints.
 *
 * Steven Aray – July 6, 2025 – 11:36 AM
 */
#include <iostream>

// Structure representing a date using bit fields to save space
struct Date {
    unsigned short day:5;    // 5 bits for day (range: 0–31)
    unsigned short month:4;  // 4 bits for month (range: 0–15)
    unsigned short year:7;   // 7 bits for year (range: 0–127, offset applied later)
};

// Function declarations
bool isValidDate(struct Date);      // Checks if a date is valid
bool isBisiesto(int fullyear);      // Determines if a year is a leap year
void printDate(struct Date);        // Prints the date in dd/mm/yyyy format

int main(void) {
    // Array of 5 sample dates using year offset from 1960 (e.g., 63 = 2023)
    const Date dates[5] = {
        { 29, 2, 63 },  // 29/02/2023 – Not a leap year → Invalid
        { 2,  2, 45 },  // 02/02/2005 – Valid
        { 24, 8, 50 },  // 24/08/2010 – Valid
        { 29, 2, 40 },  // 29/02/2000 – Leap year → Valid
        { 17, 5,100 }   // 17/05/2060 – Valid
    };

    // Iterate through the dates, print them, and validate
    for(int x = 0; x < 5; x++) {
        printDate(dates[x]);  // Output the date
        std::cout 
            << " => " 
            << (isValidDate(dates[x]) ? "Valid Date" : "Invalid Date!") 
            << std::endl;
    }

    return 0;
}

// Function that checks if a given date is valid
bool isValidDate(struct Date date) {
    // Days in each month (non-leap year)
    const int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    // Calculate total days in the specified month,
    // adding 1 if it's February and the year is leap
    const int totalDay = days[date.month - 1] +
        (int)(date.month == 2 && isBisiesto(date.year + 1960));

    // Check basic constraints for day and month
    return (
        date.day >= 1 && date.day <= totalDay &&
        date.month >= 1 && date.month <= 12
    );
}

// Function that returns true if the provided year is a leap year
bool isBisiesto(int fullyear) {
    // Leap year rules:
    // Divisible by 4 AND not by 100, unless divisible by 400
    return (fullyear % 4 == 0 && fullyear % 100 != 0) || (fullyear % 400 == 0);
}

// Function to print a Date struct in dd/mm/yyyy format
void printDate(struct Date date) {
    // Add offset to year to get full value (based on 1960)
    std::cout << date.day << "/" << date.month << "/" << (date.year + 1960);
}
