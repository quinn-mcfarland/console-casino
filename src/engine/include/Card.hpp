#ifndef CARD_H
#define CARD_H

// Standard Library Includes
#include <memory>
#include <string>

// User-Defined Includes

class Card {
public:
    Card() = default;
    Card(std::string r = "", std::string s = "", int v = 0);
private:
    std::unique_ptr<std::string> rank;
    std::unique_ptr<std::string> suit;
    std::unique_ptr<int> value;
};

#endif