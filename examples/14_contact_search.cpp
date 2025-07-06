/**
 * Simple contact search program that allows the user to:
 * 1. Search for a person by name.
 * 2. Search for a person by phone number.
 * If a match is found, the person's contact information is displayed.
 * The search uses substring matching within a static list of 10 contacts.
 * The user can repeat searches until they choose to exit (option 0).
 *
 * Steven Aray – July 6, 2025 – 10:58 AM
 */
#include <iostream>
#include <string.h>

// Define a structure to store basic contact information
struct Person {
    char name[12];
    char phone[15];
};

// Forward declaration of the function that displays a person's info
void showPerson(Person person);

int main(void) {
    // List of 10 people with their names and phone numbers
    struct Person people[10] = {
        { "Steven", "+584123013160" },
        { "Ana",    "+584126789012" },
        { "Luis",   "+584123456789" },
        { "Maria",  "+584124567890" },
        { "Carlos", "+584127654321" },
        { "Elena",  "+584128765432" },
        { "Pedro",  "+584129876543" },
        { "Lucia",  "+584121234567" },
        { "Andres", "+584122345678" },
        { "Valeria","+584123098765" }
    };

    char input[15];  // Input buffer for search query
    int option;      // User menu selection

    do {
        // Display menu options
        std::cout
            << "1) Search by name" << std::endl
            << "2) Search by number" << std::endl
            << "0) Exit" << std::endl << std::endl
            << "> ";

        std::cin >> option;

        // Skip loop if the user chose to exit
        if(option == 0) continue;

        int x;
        bool found = false;  // Flag to indicate if a match was found

        switch(option) {
            case 1:
                std::cout << "Enter name to search: ";
                std::cin >> input;

                for(x = 0; x < 10; x++) {
                    // Check if input is part of the name
                    if(strstr(people[x].name, input)) {
                        showPerson(people[x]);
                        found = true;
                        break;
                    }
                }
                break;

            case 2:
                std::cout << "Enter phone number to search: ";
                std::cin >> input;

                for(x = 0; x < 10; x++) {
                    // Check if input is part of the phone number
                    if(strstr(people[x].phone, input)) {
                        showPerson(people[x]);
                        found = true;
                        break;
                    }
                }
                break;
        }

        // If no match was found
        if(!found) {
            std::cout << "Person not found..." << std::endl;
        }
    }
    while(option); // Repeat until user selects 0

    return 0;
}

// Displays the information of a person
void showPerson(Person person) {
    std::cout 
        << "Person:" << std::endl
        << "  Name: " << person.name << std::endl
        << "  Phone: " << person.phone << std::endl;
}