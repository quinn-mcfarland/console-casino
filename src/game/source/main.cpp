/* Includes */
// Standard Library Includes
#include <iostream>

// User-Defined Includes

/* Global Constants */

/* Global Variables */

/* Function Prototypes */

/* Main Function */
int main() {
    // Object Creation
    // Local Variables
    int mainMenu;

    do {
        // Main Menu Prompt
        std::cout << "1) Blackjack" << std::endl << "2) Five Card Poker" << std::endl << "3) Exit" << std::endl <<
            "Please make a selection: ";
        std::cin >> mainMenu;

        // Main Menu Switch case
        switch (mainMenu) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            default:
                std::cout << "Invalid Input. Please try again." << std::endl;
                break;
        }

    } while (mainMenu != 3);
    return 0;
}

/* Function Definitions */