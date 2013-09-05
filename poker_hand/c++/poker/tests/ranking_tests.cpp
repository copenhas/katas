#include "gtest/gtest.h"
#include "poker.h"

using namespace Poker;
using namespace Poker::Ranking;
using namespace std;

namespace RankingTests {
    TEST(StraightFlush, matches_correctly) {
        Hand hand { "player1" };
        hand.add_card({ Face::two, Suit::spades });
        hand.add_card({ Face::three, Suit::spades });
        hand.add_card({ Face::four, Suit::spades });
        hand.add_card({ Face::five, Suit::spades });
        hand.add_card({ Face::six, Suit::spades });

        EXPECT_EQ(Rank::straight_flush, hand.rank());
    }
}
