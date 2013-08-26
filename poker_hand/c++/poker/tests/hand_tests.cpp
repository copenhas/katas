#include <sstream>
#include "gtest/gtest.h"
#include "poker.h"

using namespace Poker;
using namespace std;

namespace HandTests {
    TEST(Hand, prints_player_and_hand) {
        basic_ostringstream<char> oss;

        Hand hand { "player1" };
        hand.add_card({ Face::king, Suit::hearts });
        hand.add_card({ Face::two, Suit::spades });

        oss << hand;

        EXPECT_EQ("player1: KH 2S", oss.str());
    }
}
