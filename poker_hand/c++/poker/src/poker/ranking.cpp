#include "poker.h"

using namespace std;

namespace Poker {
    namespace Ranking {
        vector<Card> sort_high_first(vector<Card> cards) {
            sort(cards.begin(), cards.end());
            return cards;
        }

        static bool is_straight_flush(vector<Card> cards, Score &score) {
            Suit suit = cards[0].suit();
            for(auto &c : cards) {
                if (c.suit() != suit) return false;
            }

            int prev_face = static_cast<int>(cards[0].face());
            for(unsigned long i = 1; i < cards.size(); i++) {
                int current_face = static_cast<int>(cards[i].face());
                if (prev_face - current_face != -1) return false;
                prev_face = current_face;
            }

            score = Score{Rank::straight_flush, cards};
            return true;
        }

        Score score(const Hand &h) {
            vector<Card> sorted  = sort_high_first(h.cards());

            if (h.cards().size() < 5) {
                return Score{Rank::no_rank, sorted};
            }

            Score score;
            if (is_straight_flush(sorted, score)) return score;

            return Score{Rank::high_card, sorted};
        }
    }
}
