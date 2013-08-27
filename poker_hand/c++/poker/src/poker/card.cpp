#include <iostream>
#include "poker.h"

namespace Poker {
    Card::Card() : fc{Face::None}, st{Suit::None} { }
    Card::Card(Face f, Suit s) : fc{f}, st{s} { }
    Card::Card(const Card& card) : fc{card.face()}, st{card.suit()} { }

    Face Card::face() const { 
        if (fc == Face::None) throw std::bad_exception{};
        return fc; 
    }

    Suit Card::suit() const { 
        if (fc == Face::None) throw std::bad_exception{};
        return st; 
    }

    Card& Card::operator=(const Card& card) {
        fc = card.face();
        st = card.suit();
        return *this;
    }

    std::istream& operator>>(std::istream& in, Card &card) {
        Face face = static_cast<Face>(in.get());
        Suit suit = static_cast<Suit>(in.get());

        if (face == Face::None) throw std::exception{};
        if (suit == Suit::None) throw std::exception{};

        switch(face) {
            case Face::two:
            case Face::three:
            case Face::four:
            case Face::five:
            case Face::six:
            case Face::seven:
            case Face::eight:
            case Face::nine:
            case Face::jack:
            case Face::queen:
            case Face::king:
            case Face::ace:
                break;
            default:
                throw std::exception{};
        }

        switch(suit) {
            case Suit::clubs:
            case Suit::diamonds:
            case Suit::hearts:
            case Suit::spades:
                break;
            default:
                throw std::exception{};
        }

        card = Card { face, suit };

        return in;
    }

    std::ostream& operator<<(std::ostream& out, Card card) {
        return out << static_cast<char>(card.face()) << static_cast<char>(card.suit());
    }
}

