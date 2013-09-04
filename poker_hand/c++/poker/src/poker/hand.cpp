#include <algorithm>
#include "poker.h"

namespace Poker {
    Hand::Hand() {
        _rank = Rank::no_rank;
    }

    Hand::Hand(std::string player) : Hand() {
        _player = player;
    }

    std::string Hand::player() const { return _player; }
    void Hand::set_player(std::string name) { _player = name; }
    const std::vector<Card>& Hand::cards() const { return _cards; }
    Rank Hand::rank() const { return _rank; }

    void Hand::add_card(Card c) {
        _cards.push_back(c);
    }

    bool Hand::read_hand(std::istream& in, Hand& h) {
        if (in.eof()) return false;

        in >> h;
        if (h.player().length() > 0) return true;

        return false;
    }

    std::istream& operator>>(std::istream& in, Hand &h) {
        std::string name;
        Hand hand;

        for(char c = in.get(); !in.eof(); c = in.get()) {
            if (c == ':') break;
            name += c;
        }

        hand.set_player(name);

        Card card;
        while(Card::read_card(in, card)) {
            hand.add_card(card);
        }

        h = hand;
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
