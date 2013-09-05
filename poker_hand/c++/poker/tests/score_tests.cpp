#include <sstream>
#include "gtest/gtest.h"
#include "poker.h"

using namespace Poker;
using namespace Poker::Ranking;
using namespace std;

namespace ScoreTests {
    TEST(Score, is_less_than_if_rank_is_lower) {
        Score high_card { Rank::high_card, vector<Card>() };
        Score two_pair { Rank::two_pair, vector<Card>() };

        EXPECT_TRUE(high_card < two_pair);
        EXPECT_FALSE(two_pair < high_card);
    }

    TEST(Score, same_rank_comes_down_to_the_value) {
        Score two_pair1 {
            Rank::two_pair,
            vector<Card> {
              {Face::four, Suit::clubs},
              {Face::four, Suit::clubs}
            }
        };

        Score two_pair2 {
            Rank::two_pair,
            vector<Card> {
              {Face::three, Suit::clubs},
              {Face::three, Suit::clubs}
            }
        };

        EXPECT_FALSE(two_pair1 < two_pair2);
        EXPECT_TRUE(two_pair2 < two_pair1);
    }
}
