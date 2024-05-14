#include <cstdlib> // Core library. Do not remove.
#include <iostream> // For the I/O needed for all the games
#include <ctime> // For the RNG
// Function Prototypes
int getPlayerBet(int playerChips);
void clearConsole();
void showChips(int playerChips);
int generateNewCard();
int* newPokerHand(int handSize);
void outputPokerHand(int* handArray, int handSize);
void changeCardsInHand(int*& handArray);
int pokerWinCheck(int* handArray, int handSize);
int main(int argc, char** argv)
{
    std::string userInput;
    int menu; // Main menu variable
    srand(time(0)); // Seeds the RNG
    int playerChips = 100; // Player's money
    int playerBet = 0; // Global variable for player bet
    showChips(playerChips);
    std::cout << "1) Blackjack" << std::endl;
    std::cout << "2) 5-Card Poker" << std::endl;
    std::cout << "3) Exit" << std::endl;
    std::cout << "Please make a selection: ";
    std::cin >> menu;
    switch (menu)
    {
        case 1:
        {
            clearConsole();
            do
            {
                int playerScore = 0; // Used for scoring
                int dealerScore = 0;
                int playerSoft = 0; // Alternate scores when ace is dealt.
                int dealerSoft = 0;
                int currentCard = 0;
                bool playerStand = false;
                bool dealerStand = false;
                bool playerHasBlackjack = false;
                // Get bets
                showChips(playerChips);
                do
                {
                    playerBet = getPlayerBet(playerChips);
                } while (playerBet < 0 || playerBet > playerChips);
                if (playerBet != 0)
                {
                    playerChips -= playerBet;
                    clearConsole();
                    // Do initial deal
                    showChips(playerChips);
                    for (int i = 0; i < 2; i++) // Deal player 2 cards
                    {
                        currentCard = generateNewCard();
                        playerScore += currentCard;
                        if((currentCard == 1 && !playerStand) || (playerSoft > 0 && playerSoft < 21))
                        {
                            playerSoft = playerScore + 10;
                        }
                    }
                    if (playerScore == 21) // Improperly Scores (Issue #16)
                    {
                        playerStand = true;
                        playerHasBlackjack = true;
                    }
                    dealerScore += generateNewCard();
                    if(dealerScore == 1)
                    {
                        dealerSoft = dealerScore + 10;
                    }
                    while (!playerStand && playerScore < 21)
                    {

                        if (playerSoft <= 21 && playerSoft > 0)// Will output user's soft score if it exists and won't result in a bust
                        {
                            std::cout << "You have " << playerScore << "/" << playerSoft << std::endl;
                        }
                        else
                        {
                            std::cout << "You have " << playerScore << std::endl;
                        }
                        if (dealerScore == 1 || dealerSoft > 0)
                        {
                            std::cout << "Dealer has" << dealerScore << "/" << dealerSoft << std::endl;
                        }
                        else
                        {
                            std::cout << "Dealer has " << dealerScore << std::endl;
                        }
                        int blackjackMenu;
                        std::cout << "1) Hit" << std::endl;
                        std::cout << "2) Stand" << std::endl;
                        std::cout << "Whats your play?: ";
                        std::cin >> blackjackMenu;
                        switch (blackjackMenu)
                        {
                            case 1:
                                currentCard = generateNewCard();
                                playerScore += currentCard;
                                break;
                            case 2:
                                playerStand = true;
                                break;
                            default:
                                std::cout << "Invalid input." << std::endl;
                                break;
                        }
                        if((currentCard == 1 && !playerStand) || (playerSoft > 0 && playerSoft < 21))
                        {
                            playerSoft = playerScore + 10;
                        }
                        clearConsole();
                    }
                    if (playerSoft > playerScore)
                    {
                        playerScore = playerSoft;
                    }
                    if (playerScore > 21)
                    {
                        dealerStand = true;
                    }
                    while (playerStand && !dealerStand)
                    {
                        if (dealerScore < 18 && dealerSoft <= 17)
                        {
                            currentCard = generateNewCard();
                            dealerScore += currentCard;
                            if((currentCard == 1 && !dealerStand) || (dealerSoft > 0 && dealerSoft < 21))
                            {
                                dealerSoft = dealerScore + 10;
                            }
                        }
                        else
                        {
                            dealerStand = true;
                        }
                    }
                    clearConsole();
                    if (dealerSoft > dealerScore)
                    {
                        dealerScore = dealerSoft;
                    }
                    if (playerHasBlackjack && playerScore > dealerScore)
                    {
                        std::cout << "Blackjack!" << std::endl;
                        playerChips += (playerBet * 3.5);
                    }
                    else if (playerScore > 21)
                    {
                        std::cout << "Player busts" << std::endl;
                    }
                    else if (dealerScore > 21)
                    {
                        std::cout << "Dealer busts" << std::endl;
                        playerChips += (playerBet * 2);
                    }
                    else if (dealerScore > playerScore)
                    {
                        std::cout << "Dealer wins" << std::endl;
                    }
                    else if (playerScore > dealerScore)
                    {
                        std::cout << "Player wins" << std::endl;
                        playerChips += (playerBet * 2);
                    }
                    else
                    {
                        std::cout << "Push. Nobody wins" << std::endl;
                        playerChips += playerBet;
                    }
                    std::cout << "Player: " << playerScore << std::endl
                            << "Dealer: " << dealerScore << std::endl;
                    showChips(playerChips);
                }
            } while (playerBet > 0 && playerChips > 0);
            break;
        }
        case 2:
        {
            do
            {
                int pokerMenu;
                int playerBet = 0;
                const int SIZE_OF_HAND = 5; // Hand size will never change in 5-card poker
                int winID = 0; // Used to check if player won and how much.
                
                do
                {
                    playerBet = getPlayerBet(playerChips);
                } while (playerBet < 0 || playerBet > playerChips);
                while(playerBet != 0)
                {
                    clearConsole();
                    showChips(playerChips);

                    int* playerHand;
                    playerHand = newPokerHand(SIZE_OF_HAND);
                    outputPokerHand(playerHand, SIZE_OF_HAND);

                    std::cout << "1) Switch" << std::endl;
                    std::cout << "2) Keep" << std::endl;
                    std::cout << "Please make a selection: ";
                    std::cin >> pokerMenu;

                    switch (pokerMenu)
                    {
                        case 1:
                            changeCardsInHand(playerHand);
                            outputPokerHand(playerHand, SIZE_OF_HAND);
                            break;
                        case 2:
                            outputPokerHand(playerHand, SIZE_OF_HAND);
                            break;
                    }
                    clearConsole();

                    winID = pokerWinCheck(playerHand, SIZE_OF_HAND);
                    outputPokerHand(playerHand, SIZE_OF_HAND);
                    if (winID == 5) // 4-of-a-kind
                    {
                        std::cout << "4 of a kind!" << std::endl;
                        playerChips += playerBet * 6;
                    }
                    else if (winID == 4) // Full House
                    {
                        std::cout << "Full House!" << std::endl;
                        playerChips += playerBet * 5;
                    }
                    else if (winID == 3) // 3 of a kind
                    {
                        std::cout << "3 of a kind!" << std::endl;
                        playerChips += playerBet * 4;
                    }
                    else if (winID == 2)
                    {
                        std::cout << "Two Pair!" << std::endl;
                        playerChips += playerBet * 3;
                    }
                    else if (winID == 1)
                    {
                        std::cout << "Pair!" << std::endl;
                        playerChips += playerBet * 2;
                    }
                    else
                    {
                        std::cout << "You lose" << std::endl;
                    }
                    showChips(playerChips);
                }
            } while (playerBet > 0 && playerChips > 0);
            break;
        }
        case 3:
        {
            break;
        }
        default:
            std::cout << "Input not valid. Please try again." << std::endl;
    }
    return 0;
}
    /**
     * Gets players bet when invoked.
     * @param playerChips - The current amount of money the player has.
     * @return - The player's bet. Used for payouts later.
     */
    int getPlayerBet(int playerChips)
    {
        int playerBet;
        std::cout << "Place your bet: ";
        std::cin >> playerBet;
        return playerBet;
    }
    /**
     * Clears the console
     */
    void clearConsole()
    {
        for (int i = 0; i < 10; i++)
        {
            std::cout << "\n\n\n\n\n\n\n\n\n\n";
        }

    }
    /**
     * Outputs amount of money player has.
     * @param playerChips - The current amount of money the player has.
     */
    void showChips(int playerChips)
    {
        std::cout << "You have $" << playerChips << std::endl;
    }
    /**
     * Generates a new hand for active players during 5 card poker.
     * @param handSize - size of the hand. Should be a constant.
     * @return - The entire hand array after generation.
     */
    int generateNewCard()
    {
        int card = rand() % 10 + 1;
        return card;
    }
    int* newPokerHand(int handSize)
    {
        static int handArray[5];
        for (int i = 0; i < handSize; i++)
        {
            handArray[i] = rand() % 10 + 1;
        }
        return handArray;
    }
    /**
     * Outputs hand during 5-card poker.
     * @param handArray - The hand array
     * @param handSize - The size of the hand array
     */
    void outputPokerHand(int* handArray, int handSize)
    {
        std::cout << "You have ";
        for (int i = 0; i < handSize; i++)
        {
            std::cout << handArray[i] << " ";
        }
        std::cout << std::endl;
    }
    /**
     * The exchange system for 5 card Poker
     * @param handArray - The hand array
     */
    void changeCardsInHand(int*& handArray) // Readability as a whole (Issue #14)
    {
        int cardsToChange;
        int currentCard;
        std::cout << "Enter amount of cards to change (1 - 3): "; // Out of bounds possible (Issue #13)
        std::cin >> cardsToChange;
        for (int i = 0; i < cardsToChange; i++)
        {
            std::cout << "Enter card in hand of card number " << i + 1 << ": ";
            std::cin >> currentCard;
            handArray[currentCard - 1] = rand() % 10 + 1;
        }
    }
    /**
     * Win check system for 5 card poker.
     * @param handArray - The hand array
     * @param handSize - The size of the hand
     * @return - The ID number of a winning hand.
     */
    int pokerWinCheck(int* handArray, int handSize) // Rework this (Issue #22)
    {
        int fullHouseCheck = 0;
        int twoPairCheck = 0;
        int winID = 0;
        // Change this whole function to work better
        bool check[handSize];
        for (int i = 0; i < handSize; i++)
        {
            check[i] = 0;
        }
        for (int i = 0; i < handSize; i++)
        {
            if (check[i] == 1)
            {
                continue;
            }
            int count = 1;
            for (int j = i + 1; j < handSize; j++)
            {
                if (handArray[i] == handArray[j])
                {
                    check[j] = 1;
                    count++;
                }
            }
            if (count == 4)
            {
                winID = 5;
            }
            else if (count == 3)
            {
                fullHouseCheck++;
                winID = 3;
            }
            else if (count == 2)
            {
                twoPairCheck++;
                fullHouseCheck++;
                winID = 1;
            }
            else // delete
            {
            }
        }
        if (fullHouseCheck == 2)
        {
            winID = 4;
        }
        if (twoPairCheck == 2)
        {
            winID = 2;
        }
        return winID;
    }