#include <string>

#include "card.h"

card::card() {
    rank = new std::string("");
    suit = new std::string("");
    value = new int(0);
}

card::card(std::string* s, std::string* r, int* v) {
    suit = s;
    rank = r;
    value = v;
}

card::~card() {
    delete rank;
    delete suit;
    delete value;
    rank = nullptr;
    suit = nullptr;
    value = nullptr;
}