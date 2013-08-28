#include <memory>
#include "poker.h"

using namespace std;

namespace Poker {
    namespace Rank {
        const std::string StraightFlush::name() { return "Straight Flush"; }
        int StraightFlush::value() { return 9; }
        bool StraightFlush::matches(const Hand &h) {
            return false;
        }
    }
}
