#include <iostream>
#include "poker.h"

namespace Poker {
    Card::Card() : fc{Face::None}, st{Suit::None} { }
    Card::Card(Face f, Suit s) : fc{f}, st{s} { }

    Face Card::face() const { 
        if (fc == Face::None) throw std::bad_exception{};
        return fc; 
    }

    Suit Card::suit() const { 
        if (fc == Face::None) throw std::bad_exception{};
        return st; 
    }

    bool Card::read_card(std::istream& in, Card &card) {
        if (in.eof()) return false;

        //ignore leading whitespace
        char c = in.get();
        while(c == ' ') c = in.get();
        if (in.eof()) return false;
        if (c == '\n') return false;

        Face face = static_cast<Face>(c);

        c = in.get();

        if (c == '\n') return false;
        if (in.eof()) return false;

        Suit suit = static_cast<Suit>(c);

        if (face == Face::None) return false;
        if (suit == Suit::None) return false;

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
                return false;
        }

        switch(suit) {
            case Suit::clubs:
            case Suit::diamonds:
            case Suit::hearts:
            case Suit::spades:
                break;
            default:
                return false;
        }

        card = Card { face, suit };
        return true;
    }

    std::ostream& operator<<(std::ostream& out, Card card) {
        return out << static_cast<char>(card.face()) << static_cast<char>(card.suit());
    }
}

