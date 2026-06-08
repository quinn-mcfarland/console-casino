/* Includes */
// Standard Library Includes
#include <iostream> // Handles std::cout and std::cin statements
#include <memory> // Handles std::unique_ptr and member methods
#include <array> // Handles std::array and member methods

// Class Includes
#include "../../engine/include/Card.hpp" // Handles Card objects
#include "../../engine/include/Player.hpp" // Handles Player objects

// Misc. User-Defined Header Includes
#include "../../engine/include/Utilities.hpp" // Global Purpose Free Functions
#include "../../engine/include/Blackjack.hpp" // Blackjack Game Loop

/* Main Function */
int main() {
    // Objects
    std::unique_ptr<Player> player = std::make_unique<Player>(1000, 0); // Player object for the user
    std::array<std::unique_ptr<Card>, 52> cardDeck; // Card deck used inside main game loop

    // Primitives
    int mainMenu;

    // Main Game Loop
    do {
        clearConsole();

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