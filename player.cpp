#include <iostream>

#include "player.h"

player::player() {
    *money = 1000;
    betAmount = nullptr;
    hand = new std::vector<card*>();
}

player::~player() {
    delete money;
    delete betAmount;
    for (int i = 0; i < hand->size(); i++) {
        delete hand->at(i);
        hand->at(i) = nullptr;
    }
    delete hand;
    money = nullptr;
    betAmount = nullptr;
    hand = nullptr;
}

std::ostream& operator<<(std::ostream& os, const player& p) {
    os << "(" << p.money << ", " << p.betAmount << ", " << p.hand << ")";
    return os;
}

std::istream& operator>>(std::istream& is, player& p) {
    is >> p.money >> p.betAmount >> p.hand;
    return is;
}