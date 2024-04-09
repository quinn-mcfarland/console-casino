#include <cstdlib> // Core library. Do not remove.
#include <iostream> // For the I/O needed for all the games
#include <ctime> // For the RNG

using namespace std;
int getPlayerBet(int& playerChips);
int blackjackSoftCheck(int card, bool softCheck, int softScore);
int blackjackNewCard(int card);
int* newPokerHand(int handSize);
void outputPokerHand(int* handArray, int handSize);
void changeCardsInHand(int*& handArray);
void clearConsole();
void showChips(int playerChips);
int pokerWinCheck(int* handArray, int handSize);

int main(int argc, char** argv)
{
    string userInput; // Variable for playing again
    int menu;
    srand(time(0)); // Seeds the RNG
    int playerChips = 100;
    
    do
    {
        cout << "Current chips: $" << playerChips << endl;

        cout << "1) Blackjack" << endl;
        cout << "2) 5-Card Poker" << endl;

        cout << "Please make a selection: " << flush;
        cin >> menu;
        switch (menu)
        {
            case 1:
            {
                clearConsole();
                do
                {
                    int playerScore = 0; // Used for scoring
                    int dealerScore = 0;
                    int playerSoft = 0;
                    int dealerSoft = 0;
                    int currentCard = 0;
                    bool playerSoftDealt = false; // Will turn true when a 1 (Ace) is dealt.
                    bool dealerSoftDealt = false;
                    bool playerStand = false;
                    bool dealerStand = false;
                    bool playerGotBlackjack = false;
                    // Get initial bet
                    showChips(playerChips);
                    int playerBet = getPlayerBet(playerChips);
                    clearConsole();
                    // Do initial deal
                    for (int i = 0; i < 2; i++) // Deal player 2 cards
                    {
                        currentCard = blackjackNewCard(currentCard);
                        playerScore += currentCard;
                        playerSoft = blackjackSoftCheck(currentCard, playerSoftDealt, playerScore);
                    }
                    playerScore = 21;
                    if (playerScore == 21)
                    {
                        playerGotBlackjack = true;
                    }
                    cout << "Current Score: " << playerScore << endl;
                    dealerScore += blackjackNewCard(dealerScore);
                    dealerSoft = blackjackSoftCheck(currentCard, dealerSoftDealt, dealerScore);

                    cout << "Against Dealer's " << dealerScore << endl; // Only dealers first card is visible

                    dealerScore += blackjackNewCard(dealerScore);
                    dealerSoftDealt = blackjackSoftCheck(currentCard, dealerSoftDealt, dealerScore);

                    while (!playerStand && playerScore < 21)
                    {
                        int play;
                        cout << "1) Hit" << endl;
                        cout << "2) Stand" << endl;
                        cout << "Please make a selection: ";
                        cin >> play;
                        switch (play)
                        {
                            case 1:
                            {
                                currentCard = blackjackNewCard(currentCard);
                                playerScore += currentCard;
                                playerSoft = blackjackSoftCheck(currentCard, playerSoftDealt, playerScore);
                                break;
                            }
                            case 2:
                            {
                                playerStand = true;
                                break;
                            }
                            default:
                            {
                                cout << "Invalid input." << endl;
                            }
                        }
                        clearConsole();
                        if (playerSoft <= 21 && playerSoft > 0)// Will output user's soft score if it exists and won't result in a bust
                        {
                            cout << "Soft " << playerSoft << endl;
                        }
                        else
                        {
                            playerSoft = 0;
                        }
                        cout << "Current Score: " << playerScore << endl;
                    }
                    if (playerSoft > playerScore)
                    {
                        playerScore = playerSoft;
                    }
                    if (playerScore >= 21)
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
                        } else
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
                        if(playerGotBlackjack)
                        {
                            cout << "Blackjack!" << endl;
                            playerChips+=(playerBet * 1.5);
                        }
                        else if (playerScore > 21)
                        {
                            cout << "Player busts" << endl;
                        } 
                        else if (dealerScore > 21)
                        {
                            cout << "Dealer busts" << endl;
                            playerChips += (playerBet * 2);
                        } 
                        else if (dealerScore > playerScore)
                        {
                            cout << "Dealer wins" << endl;
                        } 
                        else if (playerScore > dealerScore)
                        {
                            cout << "Player wins" << endl;
                            playerChips += (playerBet * 2);
                        } 
                        else
                        {
                            cout << "Push. Nobody wins" << endl;
                            playerChips += playerBet;
                        }
                    }
                    cout << "Player: " << playerScore << endl
                            << "Dealer: " << dealerScore << endl;
                    showChips(playerChips);
                    
                    cout << "Would you like to play again? Y/N: ";
                    cin >> userInput;
                    clearConsole();
                } while (tolower(userInput[0]) == 'y' && playerChips > 0);
                break;
            }
            case 2:
            {
                do
                {
                    int pokerMenu;
                    int playerBet = 0;
                    const int SIZE_OF_HAND = 5;
                    int winID = 0;
                    
                    showChips(playerChips);
                    playerBet = getPlayerBet(playerChips);
                    clearConsole();
                    
                    showChips(playerChips);
                    int* playerHand;
                    playerHand = newPokerHand(SIZE_OF_HAND);
                    outputPokerHand(playerHand, SIZE_OF_HAND);
                    
                    cout << "1) Switch" << endl;
                    cout << "2) Keep" << endl;
                    
                    cout << "Please make a selection: ";
                    cin >> pokerMenu;
                    
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
                    if(winID == 5) // 4-of-a-kind
                    {
                        cout << "4 of a kind!" << endl;
                        playerChips+=playerBet * 6;
                    }
                    else if(winID == 4) // Full House
                    {
                        cout << "Full House!" << endl;
                        playerChips+=playerBet * 5;
                    }
                    else if(winID == 3) // 3 of a kind
                    {
                        cout << "3 of a kind!" << endl;
                        playerChips+=playerBet * 4;
                    }
                    else if(winID == 2)
                    {
                        cout << "Two Pair!" << endl;
                        playerChips+=playerBet * 3;
                    }
                    else if(winID == 1)
                    {
                        cout << "Pair!" << endl;
                        playerChips+=playerBet * 2;
                    }
                    else
                    {
                        cout << "You lose" << endl;
                    }
                    showChips(playerChips);
                    cout << "Would you like to play again? Y/N: ";
                    cin >> userInput;
                    clearConsole();
                }while(tolower(userInput[0]) == 'y' && playerChips > 0);
                break;
            }
        }
        if (playerChips == 0)
        {
            cout << "Game Over. You ran out of money." << endl;
            return 0;
        }
        cout << "Would you like to play another game? Y/N: ";
        cin >> userInput;
        clearConsole();
    } while (tolower(userInput[0]) == 'y');
    return 0;
}
int getPlayerBet(int& playerChips)
{
    cout << "Enter an amount to bet: ";
    int playerBet;
    cin >> playerBet;
    if(playerBet <= playerChips)
    {
        playerChips-=playerBet;
        return playerBet;
    }
    else
    {
        getPlayerBet(playerChips);
    }
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
    cout << "You have ";
    for (int i = 0; i < handSize; i++)
    {
        cout << handArray[i] << " ";
    }
    cout << endl;
}
void changeCardsInHand(int*& handArray)
{
    int cardsToChange;
    int currentCard;
    cout << "Enter amount of cards to change (1 - 3): ";
    cin >> cardsToChange;
    for (int i = 0; i < cardsToChange; i++)
    {
        cout << "Enter card in hand of card number " << i + 1 << ": ";
        cin >> currentCard;
        handArray[currentCard - 1] = rand() % 10 + 1;
    }
}
void clearConsole()
{
    for (int i = 0; i < 10; i++)
    {
        cout << "\n\n\n\n\n\n\n\n\n\n";
    }
    
}
void showChips(int playerChips)
{
    cout << "Current Chips: $" << playerChips << endl;
}
int pokerWinCheck(int* handArray, int handSize)
{
    int fullHouseCheck = 0;
    int twoPairCheck = 0;
    int winID = 0;
    
    bool check[handSize];
    for (int i = 0; i < handSize; i++)
    {
        check[i] = 0;
    }
    for (int i = 0; i < handSize; i++)
    {
        if(check[i] == 1)
        {
            continue;
        }
        int count = 1;
        for (int j = i + 1; j < handSize; j++)
        {
            if(handArray[i] == handArray[j])
            {
                check[j] = 1;
                count++;
            }
        }
        if(count == 4)
        {
            winID = 5;
        }
        else if(count == 3)
        {
            fullHouseCheck++;
            winID = 3;
        }
        else if(count == 2)
        {
            twoPairCheck++;
            fullHouseCheck++;
            winID = 1;
        }
        else
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