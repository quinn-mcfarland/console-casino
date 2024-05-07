#include <cstdlib> // Core library. Do not remove.
#include <iostream> // For the I/O needed for all the games
#include <ctime> // For the RNG

int getPlayerBet(int playerChips); // Gets bet for all games
int blackjackSoftCheck(int card, bool softCheck, int softScore); // Delete
int blackjackNewCard(int card); // Deals new card to active player.
int* newPokerHand(int handSize);
void outputPokerHand(int* handArray, int handSize);
void changeCardsInHand(int*& handArray);
void clearConsole();
void showChips(int playerChips);
int pokerWinCheck(int* handArray, int handSize);

int main(int argc, char** argv)
{
    std::string userInput; // Variable for playing again
    int menu;
    
    srand(time(0)); // Seeds the RNG
    
    int playerChips = 100; // Player's money
    int playerBet = 0;
    
    do
    {
        showChips(playerChips);

        std::cout << "1) Blackjack" << std::endl;
        std::cout << "2) 5-Card Poker" << std::endl;

        std::cout << "Please make a selection: ";
        std::cin >> menu;
        switch (menu)
        {
            case 1:

                clearConsole();
                do
                {
                    int playerScore = 0; // Used for scoring
                    int dealerScore = 0;
                    int playerSoft = 0; // Alternate scores when ace is dealt.
                    int dealerSoft = 0;
                    int currentCard = 0; // Newest card in play. Used for soft scoring
                    // All following booleans can/should be removed 
                    bool playerSoftDealt = false; // Will turn true when a 1 (Ace) is dealt.
                    bool dealerSoftDealt = false;
                    bool playerStand = false;
                    bool dealerStand = false;
                    // Get initial bet
                    showChips(playerChips);
                    do
                    {
                        playerBet = getPlayerBet(playerChips);
                    } while (playerBet <= 0 || playerBet > playerChips);
                    playerChips -= playerBet;
                    clearConsole();
                    // Do initial deal
                    for (int i = 0; i < 2; i++) // Deal player 2 cards
                    {
                        currentCard = blackjackNewCard(currentCard);
                        playerScore += currentCard;
                        playerSoft = blackjackSoftCheck(currentCard, playerSoftDealt, playerScore);
                    }
                    if (playerScore == 21)
                    {
                        std::cout << "Blackjack! " << std::endl;
                        playerChips += (playerBet * 3.5);
                        playerStand = true;
                        dealerStand = true;
                    }
                    std::cout << "Current Score: " << playerScore << std::endl;
                    dealerScore += blackjackNewCard(dealerScore);
                    dealerSoft = blackjackSoftCheck(currentCard, dealerSoftDealt, dealerScore);
                    std::cout << "Against Dealer's " << dealerScore << std::endl; // Only dealers first card is visible
                    dealerScore += blackjackNewCard(dealerScore);
                    dealerSoftDealt = blackjackSoftCheck(currentCard, dealerSoftDealt, dealerScore);
                    while (!playerStand && playerScore < 21)
                    {
                        int play;
                        std::cout << "1) Hit" << std::endl;
                        std::cout << "2) Stand" << std::endl;
                        std::cout << "Please make a selection: ";
                        std::cin >> play;
                        switch (play)
                        {
                            case 1:
                                currentCard = blackjackNewCard(currentCard);
                                playerScore += currentCard;
                                playerSoft = blackjackSoftCheck(currentCard, playerSoftDealt, playerScore);
                                break;
                            case 2:
                                playerStand = true;
                                break;
                            default:
                                std::cout << "Invalid input." << std::endl;
                        }
                        clearConsole();
                        if (playerSoft <= 21 && playerSoft > 0)// Will output user's soft score if it exists and won't result in a bust
                        {
                            std::cout << "Soft " << playerSoft << std::endl;
                        }
                        std::cout << "Current Score: " << playerScore << std::endl;
                    }
                    if (playerSoft > playerScore)
                    {
                        playerScore = playerSoft;
                    }
                    if (playerScore >= 21) // Remove. This isn't how blackjack is played.
                    {
                        dealerStand = true;
                    }
                    while (playerStand && !dealerStand)
                    {
                        if (dealerScore < 18 && dealerSoft < 18)
                        {
                            currentCard = blackjackNewCard(currentCard);
                            dealerScore += currentCard;
                            dealerSoft = blackjackSoftCheck(currentCard, dealerSoftDealt, dealerScore);
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
                    if (dealerStand)
                    {
                        if (playerScore > 21)
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
                    }
                    std::cout << "Player: " << playerScore << std::endl
                            << "Dealer: " << dealerScore << std::endl;
                    showChips(playerChips);

                    std::cout << "Would you like to play again? Y/N: ";
                    std::cin >> userInput;
                    clearConsole();
                } while (tolower(userInput[0]) == 'y' && playerChips > 0);
                break;
            case 2:
                clearConsole();
                do
                {
                    int pokerMenu;
                    int playerBet = 0;
                    const int SIZE_OF_HAND = 5; // Hand size will never change in 5-card poker
                    int winID = 0; // Used to check if player won and how much.
                    do
                    {
                        playerBet = getPlayerBet(playerChips);
                    } while (playerBet <= 0 || playerBet > playerChips);
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
                    std::cout << "Would you like to play again? Y/N: ";
                    std::cin >> userInput;
                    clearConsole();
                } while (tolower(userInput[0]) == 'y');
                break;
            default:
                std::cout << "Input not valid. Please try again." << std::endl;
        }
        if (playerChips == 0)
        {
            std::cout << "Game Over. You ran out of money." << std::endl;
            return 0;
        }
        std::cout << "Would you like to play another game? Y/N: ";
        std::cin >> userInput;
        clearConsole();
    } while (tolower(userInput[0]) == 'y');
    return 0;
}
int getPlayerBet(int playerChips)
{
    std::cout << "Enter an amount to bet: ";
    int playerBet;
    std::cin >> playerBet;
    return playerBet;
}
int blackjackSoftCheck(int card, bool softCheck, int softScore)
{
    if (card == 1)
    {
        softCheck = true;
        return softScore + 10; // Calculation required for soft scoring
    }
    return softScore * 0;
}
int blackjackNewCard(int card)
{
    card = rand() % 10 + 1; // Should only generate numbers between 1 and 10.
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
void outputPokerHand(int* handArray, int handSize)
{
    std::cout << "You have ";
    for (int i = 0; i < handSize; i++)
    {
        std::cout << handArray[i] << " ";
    }
    std::cout << std::endl;
}
void changeCardsInHand(int*& handArray) // Fix this (Issue #13)
{
    int cardsToChange;
    int currentCard;
    std::cout << "Enter amount of cards to change (1 - 3): "; // Prompt better. Out of bounds possibility
    std::cin >> cardsToChange;
    for (int i = 0; i < cardsToChange; i++)
    {
        std::cout << "Enter card in hand of card number " << i + 1 << ": ";
        std::cin >> currentCard;
        handArray[currentCard - 1] = rand() % 10 + 1;
    }
}
void clearConsole()
{
    for (int i = 0; i < 10; i++)
    {
        std::cout << "\n\n\n\n\n\n\n\n\n\n";
    }

}
void showChips(int playerChips)
{
    std::cout << "You have $" << playerChips << std::endl;
}
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