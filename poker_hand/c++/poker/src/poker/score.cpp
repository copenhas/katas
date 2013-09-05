#include "poker.h"

using namespace std;

namespace Poker {
    Score::Score() : _rank{Rank::no_rank} {}
    Score::Score(Rank r, vector<Card> o) : _rank{r}, _value{o} { }

    Rank Score::rank() const { return _rank; }
    vector<Card> Score::value() const { return _value; }

    bool operator<(Score& s1, Score& s2) {
        if (s1.rank() < s2.rank()) return true;
        if (s2.rank() < s1.rank()) return false;

        auto s1_value = s1.value();
        auto s1_size = s1.value().size();

        auto s2_value = s2.value();
        auto s2_size = s2.value().size();

        for (unsigned long i = 0; i < s1_size && i < s2_size; i++) {
            if (s1_value[i] < s2_value[i]) {
                return true;
            }

            if (s2_value[i] < s1_value[i]) {
                return false;
            }
        }

        return s1_size < s2_size;
    }
}
