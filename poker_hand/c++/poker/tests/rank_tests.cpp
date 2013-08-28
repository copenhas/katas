#include "gtest/gtest.h"
#include "poker.h"

using namespace Poker;
using namespace Poker::Rank;
using namespace std;

namespace RankTests {
    TEST(StraightFlush, matches_correctly) {
        //HandRank *straightFlush = new StraightFlush();

        Hand hand { "player1" };
        hand.add_card({ Face::two, Suit::spades });
        hand.add_card({ Face::three, Suit::spades });
        hand.add_card({ Face::four, Suit::spades });
        hand.add_card({ Face::five, Suit::spades });
        hand.add_card({ Face::six, Suit::spades });

        //EXPECT_TRUE(straightFlush->matches(hand));
        EXPECT_TRUE(false) << "not implemented";
    }
}
