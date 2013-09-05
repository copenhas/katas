#include <algorithm>
#include "poker.h"

namespace Poker {
    Hand::Hand() {
        _score = Score{Rank::no_rank, std::vector<Card>()};
    }

    Hand::Hand(std::string player) : Hand() {
        _player = player;
    }

    std::string Hand::player() const { return _player; }
    void Hand::set_player(std::string name) { _player = name; }
    const std::vector<Card>& Hand::cards() const { return _cards; }
    Rank Hand::rank() const { return _score.rank(); }

    void Hand::add_card(Card c) {
        if (_cards.size() == 5) throw std::bad_exception();

        _cards.push_back(c);

        if (_cards.size() == 5) {
            _score = Ranking::score(*this);
        }
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
