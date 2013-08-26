#include <iostream>
#include "poker.h"

namespace Poker {
    Card::Card(Face f, Suit s) : fc{f}, st{s} { }
    Card::Card(const Card& card) : fc{card.face()}, st{card.suit()} { }

    Face Card::face() const { return fc; }
    Suit Card::suit() const { return st; }

    Card& Card::operator=(const Card& card) {
        fc = card.face();
        st = card.suit();
        return *this;
    }

    std::ostream& operator<<(std::ostream& out, Card card) {
        return out << static_cast<char>(card.face()) << static_cast<char>(card.suit());
    }
}

