#include "Card.hpp"
#include <string>
#include <memory>

Card::Card(std::string r, std::string s, int v) {
    rank = std::make_unique<std::string>(r);
    suit = std::make_unique<std::string>(s);
    value = std::make_unique<int>(v);
}