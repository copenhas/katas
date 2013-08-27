#include "poker.h"

namespace Poker {
    Hand::Hand() : _cards{ 5 } { }
    Hand::Hand(std::string player) :
        _player{player}
    {}

    std::string Hand::player() const { return _player; }
    void Hand::set_player(std::string name) { _player = name; }
    std::vector<Card> Hand::cards() const { return _cards; }

    void Hand::add_card(Card c) {
        _cards.push_back(c);
    }

    std::istream& operator>>(std::istream& in, Hand &hand) {
        std::string name;

        for(char c = in.get(); !in.eof(); c = in.get()) {
            if (c == ':') break;
            name += c;
        }

        hand.set_player(name);

        for(char c = in.peek(); !in.eof();) {
            if (c == ' ') {
                //if it's a space skip it
                in.get();
                continue;
            }
            if (c == '\n') break;

            Card card;
            in >> card;
            hand.add_card(card);
        }

        return in;
    }

    std::ostream& operator<<(std::ostream& out, Hand hand) {
        out << hand.player() << ":";
        for(auto c : hand.cards()) {
            out << " " << c;
        }
        return out;
    }
}
