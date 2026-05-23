#ifndef CONSOLECASINO_CARD_H
#define CONSOLECASINO_CARD_H

#include <string>

class card {
private:
    std::string* rank;
    std::string* suit;
    int* value;
public:
    // Constructors and Destructors
    card();
    card(std::string* s = nullptr, std::string* r = nullptr, int* v = nullptr);
    ~card();
    // Operator Overloads
    // Accessors
    std::string* getRank() const { return rank; }
    std::string* getSuit() const { return suit; }
    int* getValue() const { return value; }
    // Mutators
    void setRank(std::string data) { rank = &data; }
    void setSuit(std::string data) { suit = &data; }
    void setValue(int data) { value = &data; }
    // Other Member Functions
};


#endif //CONSOLECASINO_CARD_H
