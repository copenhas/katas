#include "poker.h"

namespace Poker {
    Hand::Hand(std::string player) :
        _player{player}
    {}

    std::string Hand::player() const { return _player; }
    std::vector<Card> Hand::cards() const { return _cards; }

    void Hand::add_card(Card c) {
        _cards.push_back(c);
    }

    std::ostream& operator<<(std::ostream& out, Hand hand) {
        out << hand.player() << ":";
        for(auto c : hand.cards()) {
            out << " " << c;
        }
        return out;
    }
}
