/* Includes */
// Library Includes
#include <iostream>
#include <array>
#include <random>

// Class Includes
#include "Player.h"
#include "Card.h"

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
void dealOneCard(Player player);

// Blackjack Functions
void blackjackNewGame();
bool blackjackInsurance();
void blackjackPlayersTurn();
void blackjackDealersTurn();
void blackjackScoring();

// Five Card Poker Functions

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
                do {
                    std::cout << "Play again? (1 for yes, 0 for no): ";
                    std::cin >> blackjackContinue;
                    if (blackjackContinue != 0 && blackjackContinue != 1) {
                        std::cout << "Invalid input. Please try again." << std::endl;
                    }
                } while (blackjackContinue != 0 && blackjackContinue != 1);
            } while (blackjackContinue == 1);
            break;
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

void dealOneCard(Player player) {
    player.allHands[0].emplace_back(Card(cardDeck[cardDeckIndex].getSuit(),
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
            dealOneCard(user);
            dealOneCard(dealer);
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
    // Local Variables
    int blackjackMenu = 0;
    int currentHandScore;
    int currentHandSoft = 0;

    for (int i = 0; i < user.allHands.size(); i++) {
        /* Clear Console, calculate current hand score, and display everything */
        clearConsole();
        currentHandScore = 0;

        // Calculate hand score
        for (int j = 0; j < user.allHands[i].size(); j++) {
            currentHandScore += user.allHands[i][j].getValue();
            if ((user.allHands[i][j].getValue() == 1 || currentHandSoft > 0) && currentHandSoft <= 21) {
                currentHandSoft = currentHandScore + 10;
            }
        }
        do {
            // Display everything
            std::cout << "Your current hand is: " << std::endl;
            for (int j = 0; j < user.allHands[i].size(); j++) {
                std::cout << user.allHands[i][j].getRank() << " ";
            }
            std::cout << std::endl << "Total: " << currentHandScore;
            if (currentHandSoft > 0 && currentHandSoft <= 21) {
                std::cout << " / Soft " << currentHandSoft;
            }
            std::cout << std::endl;

            // If player busts, end turn immediately
            if (currentHandScore >= 21) {
                blackjackMenu = 2;
            } else {
                // Game Loop Prompt
                std::cout << "1) Hit" << std::endl
                << "2) Stand" << std::endl;
                if (user.allHands[i].size() == 2) {
                    std::cout << "3) Double" << std::endl;
                }
                if (user.allHands[0][0].getRank() == user.allHands[0][1].getRank()) {
                    std::cout << "4) Split" << std::endl;
                }
                std::cout << "Please make a selection: ";
                std::cin >> blackjackMenu;
            }

            // Game Loop Switch Case
            switch (blackjackMenu) {
            case 1:
                dealOneCard(user);
                currentHandScore += user.allHands[i][user.allHands[i].size() - 1].getValue();
                if (user.allHands[i][user.allHands[i].size() -1].getValue() == 1 || currentHandSoft > 0) {
                    currentHandSoft = currentHandScore + 10;
                }
                break;
            case 2:
                break;
            case 3:
                if (user.allHands[i].size() == 2) {
                    // Collect double down bet
                    user.setMoney(user.getMoney() - user.getBetAmount());
                    user.setBetAmount(user.getBetAmount() * 2);

                    // Deal One Card
                    dealOneCard(user);
                    currentHandScore += user.allHands[i][user.allHands[i].size() - 1].getValue();

                    // End player's turn
                    blackjackMenu = 2;
                } else {
                    std::cout << "Nice try, cheater. You know better." << std::endl;
                }
                break;
            case 4:
                // Bounds check for all those cheating freaks
                if (user.allHands[i][0].getRank() == user.allHands[i][1].getRank()) {
                    // Collect split bet
                    user.setMoney(user.getMoney() - user.getBetAmount());

                    // Create new hand and move one card to it
                    user.allHands.emplace_back(std::vector<Card>());
                    user.allHands[i + 1].emplace_back(user.allHands[i][1]);
                    user.allHands[i].pop_back();

                    for (int j = 0; j < user.allHands.size(); j++) {
                        dealOneCard(user);
                    }

                    // Recalculate current hand score for the split hand
                    currentHandScore = 0;
                    for (int j = 0; j < user.allHands[i].size(); j++) {
                        currentHandScore += user.allHands[i][j].getValue();
                        if ((user.allHands[i][j].getValue() == 1 || currentHandSoft > 0) && currentHandSoft <= 21) {
                            currentHandSoft = currentHandScore + 10;
                        }
                    }
                } else {
                    std::cout << "You know damn well you shouldn't have accessed that. Nice try, cheater." << std::endl;
                }
                break;
            default:
                std::cout << "Invalid input, please try again." << std::endl;
                break;
            }
        } while (blackjackMenu != 2);
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

    while (handScore < 18 && handSoft <= 17) {
        std::cout << "Dealer's score: " << handScore << std::endl;
        dealOneCard(dealer);

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

    /* Calculate Score */
    // First the dealer's hand
    for (int i = 0; i < dealer.allHands[0].size(); i++) {
        dealersHandScore += dealer.allHands[0][i].getValue();
        if (dealer.allHands[0][i].getValue() == 1) {
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
        for (int j = 0; j < user.allHands[i].size(); j++) {
            usersCurrentHandScore += user.allHands[i][j].getValue();
            if (user.allHands[i][j].getValue() == 1) {
                usersCurrentHandSoft = usersCurrentHandScore + 10;
            }
        }
        if (usersCurrentHandSoft > usersCurrentHandScore && usersCurrentHandSoft <= 21) {
            usersCurrentHandScore = usersCurrentHandSoft;
        }

        // Calculate outcome
        if (usersCurrentHandScore > 21) {
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