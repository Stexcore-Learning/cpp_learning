/**
 * Validates and prints a list of hardcoded dates using compact bitfield storage.
 * Each date includes a day, month, and a year offset from 1960.
 * The program iterates through five Date entries, prints each one,
 * and determines whether it's valid based on leap year logic and calendar constraints.
 *
 * Steven Aray – July 6, 2025 – 11:36 AM
 */
#include <iostream>

// Days in each month (non-leap year)
const int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};

// Structure representing a date using bit fields to save space
struct Date {
    unsigned short day:5;    // 5 bits for day (range: 1–31)
    unsigned short month:4;  // 4 bits for month (range: 1–12)
    unsigned short year:7;   // 7 bits for year (offset from 1960)
};

// Function declarations
bool isValidDate(struct Date);         // Checks if a date is valid
bool isLeapYear(int fullYear);         // Determines if a year is a leap year
void printDate(struct Date);           // Prints the date in dd/mm/yyyy format
int compareDate(struct Date, struct Date);  // Compares two dates chronologically
int diffDate(struct Date, struct Date);     // Returns absolute day difference

int main(void) {
    // Sample dates encoded using year offset from 1960
    const Date dates[5] = {
        { 29, 2, 63 },  // 29/02/2023 – Not a leap year → Invalid
        { 2,  2, 45 },  // 02/02/2005 – Valid
        { 24, 8, 50 },  // 24/08/2010 – Valid
        { 29, 2, 40 },  // 29/02/2000 – Leap year → Valid
        { 17, 5,100 }   // 17/05/2060 – Valid
    };

    // Iterate through dates: print and validate each
    for (int x = 0; x < 5; x++) {
        printDate(dates[x]);
        std::cout 
            << " => " 
            << (isValidDate(dates[x]) ? "Valid Date" : "Invalid Date!") 
            << std::endl;
    }

    // Compare and compute difference between two example dates
    Date date_a = { 1, 3, 45 };  // March 1, 2005
    Date date_b = { 1, 2, 45 };  // February 1, 2005

    printDate(date_a);
    std::cout << " < " << compareDate(date_a, date_b) << " > ";
    printDate(date_b);
    std::cout << std::endl;

    std::cout << "Diff: ";
    printDate(date_a);
    std::cout << " diff ";
    printDate(date_b);
    std::cout << " = " << diffDate(date_a, date_b);

    return 0;
}

// Validates a given date based on month/day constraints and leap year logic
bool isValidDate(struct Date date) {
    const int fullYear = date.year + 1960;
    const int totalDay = days[date.month - 1] +
        (int)(date.month == 2 && isLeapYear(fullYear)); // Feb + 1 day if leap year

    return (
        date.day >= 1 && date.day <= totalDay &&
        date.month >= 1 && date.month <= 12
    );
}

// Determines if a year is a leap year (Gregorian calendar rules)
bool isLeapYear(int fullYear) {
    return (fullYear % 4 == 0 && fullYear % 100 != 0) || (fullYear % 400 == 0);
}

// Outputs date in dd/mm/yyyy format
void printDate(struct Date date) {
    std::cout << date.day << "/" << date.month << "/" << (date.year + 1960);
}

// Returns comparison result: 1 if a > b, -1 if a < b, 0 if equal
int compareDate(Date date_a, Date date_b) {
    if (date_a.year > date_b.year ||
        (date_a.year == date_b.year && date_a.month > date_b.month) ||
        (date_a.year == date_b.year && date_a.month == date_b.month && date_a.day > date_b.day)) {
        return 1;
    }
    if (date_a.year < date_b.year ||
        (date_a.year == date_b.year && date_a.month < date_b.month) ||
        (date_a.year == date_b.year && date_a.month == date_b.month && date_a.day < date_b.day)) {
        return -1;
    }
    return 0;
}

// Returns total number of days elapsed since Jan 1, 1960
int getDaysSince1960(Date date) {
    int totalDays = 0;
    int fullYear = date.year + 1960;

    for (int y = 1960; y < fullYear; y++) {
        totalDays += 365 + isLeapYear(y);  // Add 366 if leap year
    }

    for (int m = 1; m < date.month; m++) {
        totalDays += days[m - 1] + (m == 2 && isLeapYear(fullYear));
    }

    totalDays += date.day - 1;
    return totalDays;
}

// Returns absolute difference in days between two dates
int diffDate(Date date_a, Date date_b) {
    return std::abs(getDaysSince1960(date_a) - getDaysSince1960(date_b));
}
