#include <memory>
#include "poker.h"

using namespace std;

namespace Poker {
    namespace Ranking {
        HandRank CreateRank(Hand &h) {
            if (StraightFlush::matches(h)) return StraightFlush{h};
            return NoRank();
        }

        const std::string NoRank::name() const { return "illegal hand"; }
        Rank NoRank::value() const { return Rank::no_rank; }

        StraightFlush::StraightFlush(const Hand &h) {}

        const std::string StraightFlush::name() const { return "Straight Flush"; }
        Rank StraightFlush::value() const { return Rank::straight_flush; }

        bool StraightFlush::matches(Hand &h) {
            return false;
        }
    }
}
