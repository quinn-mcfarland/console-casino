/* Includes */
// Library Includes
#include <iostream>
#include <array>
#include <random>

// Class Includes
#include "../Player.hpp"
#include "../include/Card.hpp"

/* Global Variables */
// Objects
Player user = Player();
Player dealer = Player();
std::array<Card, 52> cardDeck = {};

// PRNG Variables
std::random_device rd;
std::mt19937 gen(rd());

// Primitives
int cardDeckIndex = 0;

/* Function Prototypes */
// Utility Functions
inline void clearConsole() { std::cout << "\n\n\n\n\n\n\n\n\n\n";}
void createCardDeck();
void shuffleDeck();
void dealOneCard(Player &player, int currentHand);

// Blackjack Functions
void blackjackNewGame();
bool blackjackInsurance();
void blackjackPlayersTurn();
void blackjackDealersTurn();
void blackjackScoring();

// Five Card Poker Functions
void fiveCardPokerNewGame();
void fiveCardPokerExchange();
void fiveCardPokerScoring();

/* Main Function */
int main() {
    // Game initialization
    int blackjackContinue = 0;
    int mainMenu = 0;
    createCardDeck(); // Creates a new standard card deck
    shuffleDeck(); // Shuffles the new deck

    // Game Loop
    do {
        // Menu Prompt
        std::cout << "1) Blackjack" << std::endl
        << "2) Five Card Poker" << std::endl
        << "3) Exit" << std::endl
        << "Please make a selection: ";
        std::cin >> mainMenu;

        // Switch case for game menu
        switch (mainMenu) {
        case 1:
            do {
                // Start a new game of blackjack
                blackjackNewGame();

                if (user.getBetAmount() > 0) {
                    // Check for insurance
                    bool playerHasInsurance = blackjackInsurance();

                    // Resolve insurance bet
                    if (playerHasInsurance) {
                        if ((dealer.allHands[0][0].getValue() == 1 && dealer.allHands[0][1].getValue() == 10) ||
                            (dealer.allHands[0][0].getValue() == 10 && dealer.allHands[0][1].getValue() == 1)) {
                            std::cout << "Your insurance bet wins!" << std::endl;
                            blackjackScoring();
                            } else {
                                std::cout << "Your insurance bet loses." << std::endl;
                            }
                    }

                    // Resolve blackjacks
                    if (((dealer.allHands[0][0].getValue() == 1 && dealer.allHands[0][1].getValue() == 10) ||
                        (dealer.allHands[0][0].getValue() == 10 && dealer.allHands[0][1].getValue() == 1)) ||
                        ((user.allHands[0][0].getValue() == 1 && user.allHands[0][1].getValue() == 10) ||
                        (user.allHands[0][0].getValue() == 10 && user.allHands[0][1].getValue() == 1))) {
                        blackjackScoring();
                        } else {
                            // Play out game as normal
                            // First the players turn
                            blackjackPlayersTurn();

                            // Then the dealer's
                            blackjackDealersTurn();

                            // Then score the hands
                            blackjackScoring();
                        }

                    // Then prompt the player to play again
                    do {
                        std::cout << "Play again? (1 for yes, 0 for no): ";
                        std::cin >> blackjackContinue;
                        if (blackjackContinue < 0 || blackjackContinue > 1) {
                            std::cout << "Invalid input. Please try again." << std::endl;
                        }
                    } while (blackjackContinue < 0 || blackjackContinue > 1);
                }
            } while (blackjackContinue != 0);
            break;
        case 2:
            // Start a new game
            fiveCardPokerNewGame();

            // Ask player if they would like to exchange cards
            fiveCardPokerExchange();

            // Score the hand
            fiveCardPokerScoring();
        case 3:
            break;
        default:
            std::cout << "Invalid input. Please try again." << std::endl;
            break;
        }
    } while (mainMenu != 3);

    return 0;
}

/* Function Definitions */
// Utility Functions
void createCardDeck() {
    // Local Variables
    std::array<std::string, 4> suits = {"clubs", "diamonds", "hearts",
        "spades"};
    std::array<std::string, 13> ranks = { "ace", "2", "3", "4",
        "5", "6", "7", "8", "9", "10", "jack", "queen",
        "king" };
    int deckIndex = 0;

    // Create Card Deck
    for (int i = 0; i < suits.size(); i++) {
        for (int j = 0; j < ranks.size(); j++) {
            if (j >= 10) {
                cardDeck[deckIndex] = Card(suits[i], ranks[j], 10);
            } else {
                cardDeck[deckIndex] = Card(suits[i], ranks[j], j + 1);
            }
            deckIndex++;
        }
    }
}

void shuffleDeck() {
    std::shuffle(cardDeck.begin(), cardDeck.end(), gen);
    cardDeckIndex = 0;
}

void dealOneCard(Player &player, int currentHand) {
    player.allHands[currentHand].emplace_back(Card(cardDeck[cardDeckIndex].getSuit(),
    cardDeck[cardDeckIndex].getRank(), cardDeck[cardDeckIndex].getValue()));
    cardDeckIndex++;
}

// Blackjack Functions
void blackjackNewGame() {
    // Clear console and get player's bet
    clearConsole();
    user.getPlayerBet();

    if (user.getBetAmount() != 0) {
        // Create a new hand for the user and dealer
        user.allHands.emplace_back(std::vector<Card>());
        dealer.allHands.emplace_back(std::vector<Card>());

        // Deal two cards to both player and dealer
        for (int i = 0; i < 2; i++) {
            dealOneCard(user, 0);
            dealOneCard(dealer, 0);
        }

        // Display player's hand and face-up dealer card
        std::cout << "You have: " << user.allHands[0][0].getRank() << " "
        << user.allHands[0][1].getRank() << std::endl
        << "Dealer has: " << dealer.allHands[0][0].getRank() << " ?" << std::endl;
    }
}

bool blackjackInsurance() {
    int insuranceCheck;

    if (dealer.allHands[0][0].getValue() == 1  || dealer.allHands[0][0].getValue() == 10) {
        do {
            std::cout << "Insurance? (1 for yes, 0 for no): ";
            std::cin >> insuranceCheck;
            if (insuranceCheck < 0 || insuranceCheck > 1) {
                std::cout << "Invalid input. Please try again." << std::endl;
            }
        } while (insuranceCheck != 0 && insuranceCheck != 1);

        if (insuranceCheck == 1) {
            user.getInsuranceBet();
            if (user.getInsuranceBetAmount() > 0) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}

void blackjackPlayersTurn() {
    int blackjackMenu = 0;
    int currentHandScore = 0;
    int currentHandSoft = 0;

    // Play all of user's hands
    for (int i = 0; i < user.allHands.size(); i++) {
        do {
            clearConsole();

            currentHandScore = 0;
            currentHandSoft = 0;

            for (int j = 0; j < user.allHands[i].size(); j++) {
                currentHandScore += user.allHands[i][j].getValue();
                if (user.allHands[i][j].getValue() == 1 || currentHandSoft > 0) {
                    currentHandSoft = currentHandScore + 10;
                }
            }
            // Game Loop prompt
            for (int j = 0; j < user.allHands[i].size(); j++) {
                std::cout << user.allHands[i][j].getRank() << " ";
            }
            std::cout << std::endl << "Hand total: " << currentHandScore;
            if (currentHandSoft > 0 && currentHandSoft <= 21) {
                std::cout << " / Soft " << currentHandSoft;
            }
            std::cout << std::endl
                << "1) Hit" << std::endl
                << "2) Stand" << std::endl;

            // Prompt for a double down if available
            if (user.allHands[i].size() == 2) {
                std::cout << "3) Double" << std::endl;
            }

            // Prompt for split if available
            if (user.allHands[i][0].getValue() == user.allHands[i][1].getValue()) {
                std::cout << "4) Split" << std::endl;
            }

            std::cout << "Please make a selection: ";
            std::cin >> blackjackMenu;

            // Switch case for game loop
            switch (blackjackMenu) {
            case 1:
                currentHandScore += cardDeck[cardDeckIndex].getValue();
                if (cardDeck[cardDeckIndex].getValue() == 1 || currentHandSoft > 0) {
                    currentHandSoft = currentHandScore + 10;
                }
                dealOneCard(user, i);
                break;
            case 2:
                break;
            case 3:
                if (user.allHands[i].size() == 2) {
                    // Collect double down bet
                    user.setMoney(user.getMoney() - user.getBetAmount());
                    user.setBetAmount(user.getBetAmount() * 2);

                    // Deal one card
                    currentHandScore += cardDeck[cardDeckIndex].getValue();
                    if (cardDeck[cardDeckIndex].getValue() == 1 || currentHandSoft > 0) {
                        currentHandSoft = currentHandScore + 10;
                    }
                    dealOneCard(user, i);

                    // End the turn
                    blackjackMenu = 2;
                } else {
                    std::cout << "Option unavailable. How'd you even get here?" << std::endl;
                }
                break;
            case 4:
                if (user.allHands[i][0].getValue() == user.allHands[i][1].getValue()) {
                    // Collect the bet
                    user.setMoney(user.getMoney() - user.getBetAmount());

                    // Split the hand into two
                    user.allHands.emplace_back(std::vector<Card>());
                    user.allHands[i + 1].emplace_back(user.allHands[0][1]);
                    user.allHands[i].pop_back();

                    // Deal a new card to each hand
                    for (int j = 0; j < user.allHands.size(); j++) {
                        user.allHands[j].emplace_back(Card(cardDeck[cardDeckIndex].getSuit(),
                            cardDeck[cardDeckIndex].getRank(), cardDeck[cardDeckIndex].getValue()));
                        cardDeckIndex++;
                    }
                } else {
                    std::cout << "Option unavailable. How'd you even get here?" << std::endl;
                }
                break;
            default:
                std::cout << "Invalid input. Please try again." << std::endl;
                break;
            }
        } while (blackjackMenu != 2 && (currentHandScore <= 21 && currentHandSoft <= 21));
    }
}

void blackjackDealersTurn() {
    // Local Variables
    int handScore = 0;
    int handSoft = 0;

    // Calculate current scores
    for (int i = 0; i < dealer.allHands[0].size(); i++) {
        handScore += dealer.allHands[0][i].getValue();
        if (dealer.allHands[0][i].getValue() == 1) {
            handSoft = handScore + 10;
        }
    }

    while (handScore < 17 && handSoft <= 17) {
        dealOneCard(dealer, 0);

        handScore += dealer.allHands[0][dealer.allHands[0].size() - 1].getValue();
        if (dealer.allHands[0][dealer.allHands[0].size() -1].getValue() == 1) {
            handSoft = handScore + 10;
        }
    }
}

void blackjackScoring() {
    // Local Variables
    int usersCurrentHandScore = 0;
    int usersCurrentHandSoft = 0;
    int dealersHandScore = 0;
    int dealersHandSoft = 0;

    // Clear Console
    clearConsole();

    /* Calculate Score */
    // First the dealer's hand
    for (int i = 0; i < dealer.allHands[0].size(); i++) {
        dealersHandScore += dealer.allHands[0][i].getValue();
        if (dealer.allHands[0][i].getValue() == 1 || dealersHandSoft > 0) {
            dealersHandSoft = dealersHandScore + 10;
        }
    }
    if (dealersHandSoft > dealersHandScore && dealersHandSoft <= 21) {
        dealersHandScore = dealersHandSoft;
    }

    // Display dealers hand
    std::cout << "Dealer's hand: " << std::endl;
    for (int i = 0; i < dealer.allHands[0].size(); i++) {
        std::cout << dealer.allHands[0][i].getRank() << " ";
    }
    std::cout << "Total: " << dealersHandScore << std::endl;

    // Then compare it to each of the user's hands and pay out accordingly
    for (int i = 0; i < user.allHands.size(); i++) {
        usersCurrentHandScore = 0;
        for (int j = 0; j < user.allHands[i].size(); j++) {
            usersCurrentHandScore += user.allHands[i][j].getValue();
            if (user.allHands[i][j].getValue() == 1 || usersCurrentHandSoft > 0) {
                usersCurrentHandSoft = usersCurrentHandScore + 10;
            }
        }
        if (usersCurrentHandSoft > usersCurrentHandScore && usersCurrentHandSoft <= 21) {
            usersCurrentHandScore = usersCurrentHandSoft;
        }

        // Display players current hand
        std::cout << "Current hand: " << std::endl;
        for (int j = 0; j < user.allHands[i].size(); j++) {
            std::cout << user.allHands[i][j].getRank() << " ";
        }
        std::cout << "Total: " << usersCurrentHandScore << std::endl;

        // Calculate outcome
        if (user.allHands[i].size() == 2 && usersCurrentHandScore == 21) {
            std::cout << "Blackjack!" << std::endl;
            user.setMoney(user.getMoney() + (user.getBetAmount() * 2.5));
        } else if (usersCurrentHandScore > 21) {
            std::cout << "Bust! You lose." << std::endl;
        } else if (usersCurrentHandScore > dealersHandScore || dealersHandScore > 21) {
            std::cout << "You win!" << std::endl;
            user.setMoney(user.getMoney() + (user.getBetAmount() * 2));
        } else if (usersCurrentHandScore == dealersHandScore) {
            std::cout << "Push." << std::endl;
            user.setMoney(user.getMoney() + user.getBetAmount());
        }
    }

    // Shuffle the deck and clear hands
    shuffleDeck();
    user.allHands.clear();
    dealer.allHands.clear();
}
// Five Card Poker Functions
void fiveCardPokerNewGame() {
    // Local variables

    // Clear the console
    clearConsole();

    // Game Loop
    do {
        // Get Players bet
        user.getPlayerBet();
        clearConsole();
    } while (user.getBetAmount() < 0 || user.getBetAmount() > user.getMoney());

    // If bet is valid, deal 5 cards to the user and display them
    if (user.getBetAmount() > 0) {
        // Create a new hand and deal 5 cards
        user.allHands.emplace_back(std::vector<Card>());
        for (int i = 0; i < 5; i++) {
            dealOneCard(user, 0);
        }
        // Display the user's hand
        std::cout << "Your hand: " << std::endl;
        for (int i = 0; i < user.allHands[0].size(); i++) {
            std::cout << user.allHands[0][i].getRank() << " of " << user.allHands[0][i].getSuit() << std::endl;
        }
    }
}

void fiveCardPokerExchange() {
    // Local Variables
    int exchangeMenu;

    // Ask the user if they would like to exchange cards
    do {
        std::cout << "Would you like to exchange cards? (1 for yes, 0 for no): ";
        std::cin >> exchangeMenu;
        if (exchangeMenu < 0 || exchangeMenu > 1) {
            std::cout << "Invalid input. Please try again." << std::endl;
        }
    } while (exchangeMenu < 0 || exchangeMenu > 1);

    if (exchangeMenu == 1) {
        exchangeMenu = 0;
        int exchangeAmount;

        // Ask the user how many cards they would like to exchange
        do {
            std::cout << "Enter the number of cards you'd like to exchange (1-3): ";
            std::cin >> exchangeAmount;
            if (exchangeAmount < 1 || exchangeAmount > 3) {
                std::cout << "Invalid input. Please try again." << std::endl;
            }
        } while (exchangeAmount < 1 || exchangeAmount > 3);

        // Clear the console
        clearConsole();

        // Display hand with user-friendly indices
        std::cout << "Your hand: " << std::endl;
        for (int i = 0; i < user.allHands[0].size(); i++) {
            std::cout << i + 1 << ") " << user.allHands[0][i].getRank() <<
                " of " << user.allHands[0][i].getSuit() << std::endl;
        }

        // Get indices of cards to exchange
        for (int i = 0; i < exchangeAmount; i++) {
            // Individual card prompt
            do {
                std::cout << "Enter the number of the card you'd like to exchange for card " << i + 1 << ": ";
                std::cin >> exchangeMenu;
                if (exchangeMenu < 1 || exchangeMenu > 5) {
                    std::cout << "Invalid input. Please try again." << std::endl;
                }
            } while (exchangeMenu < 1 || exchangeMenu > 5);

            // Exchange the card
            user.allHands[0].at(exchangeMenu - 1) = Card(cardDeck[cardDeckIndex].getSuit(),
                cardDeck[cardDeckIndex].getRank(), cardDeck[cardDeckIndex].getValue());
            cardDeckIndex++;
        }
    }
}

void fiveCardPokerScoring() {
    // Local Variables
    bool fourOfAKind = false;
    bool threeOfAKind = false;
    int pairOne = 0;
    int pairTwo = 0;
    int count = 0;
    Card currentlyCheckedCard;

    // Iterate through the hand and check for win conditions
    for (int i = 0; i < 5; i++) {
        count = 1;
        currentlyCheckedCard = user.allHands[0][i];

        // Check if cards later in the hand match the current card
        for (int j = i; j < 5; j++) {
            if (user.allHands[0][j].getRank() == currentlyCheckedCard.getRank() && i != j) {
                count++;
            }
        }

        // Assign win conditions based on the number of matching cards
        if (count == 4) {
            fourOfAKind = true;
        } else if (count == 3) {
            threeOfAKind = true;
        } else if (count == 2) {
            if (pairOne > 0 && currentlyCheckedCard.getValue() != pairOne) {
                pairTwo = currentlyCheckedCard.getValue();
            } else {
                pairOne = currentlyCheckedCard.getValue();
            }
        }
    }

    // Assign win conditions on a hierarchy system
    if (fourOfAKind) {
        std::cout << "4 of a kind!" << std::endl;
        user.setMoney(user.getMoney() + (user.getBetAmount() * 6));
    } else if (pairOne > 0 && threeOfAKind) {
        std::cout << "Full House!" << std::endl;
        user.setMoney(user.getMoney() + (user.getBetAmount() * 5));
    } else if (threeOfAKind) {
        std::cout << "3 of a kind!" << std::endl;
        user.setMoney(user.getMoney() + (user.getBetAmount() * 4));
    } else if (pairOne > 0 && pairTwo > 0) {
        std::cout << "Two Pair!" << std::endl;
        user.setMoney(user.getMoney() + (user.getBetAmount() * 3));
    } else if (pairOne > 0) {
        std::cout << "Pair!" << std::endl;
        user.setMoney(user.getMoney() + (user.getBetAmount() * 2));
    } else {
        std::cout << "You lose." << std::endl;
    }
}