#include "poker.h"

using namespace std;

namespace Poker {
    namespace Ranking {
        vector<Card> sort_high_first(vector<Card> cards) {
            sort(cards.begin(), cards.end());
            vector<Card> high_first {cards.size()};
            copy(cards.rbegin(), cards.rend(), high_first.begin());
            return high_first;
        }

        Score score(const Hand &h) {
            vector<Card> sorted  = sort_high_first(h.cards());

            if (h.cards().size() < 5) {
                return Score{Rank::no_rank, sorted};
            }

            return Score{Rank::high_card, sorted};
        }
    }
}
