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

    TEST(Hand, parses_up_to_a_colon_as_player_name) {
        std::basic_istringstream<char> iss { "copenhaver: " };

        Hand h;
        iss >> h;

        EXPECT_EQ("copenhaver", h.player());
    }

    TEST(Hand, parses_after_colon_as_cards) {
        std::basic_istringstream<char> iss { "copenhaver: 2H 4D KS " };

        Hand h;
        iss >> h;

        EXPECT_EQ("copenhaver", h.player());
        ASSERT_EQ(3, h.cards().size());

        EXPECT_EQ(Face::two, h.cards()[0].face());
        EXPECT_EQ(Suit::hearts, h.cards()[0].suit());

        EXPECT_EQ(Face::four, h.cards()[1].face());
        EXPECT_EQ(Suit::diamonds, h.cards()[1].suit());

        EXPECT_EQ(Face::king, h.cards()[2].face());
        EXPECT_EQ(Suit::spades, h.cards()[2].suit());
    }

    TEST(Hand, can_parse_multiple_lines_of_hands) {
        std::basic_istringstream<char> iss { "copenhaver: 2H 3S 4D 5C 6H\n"
                                             "rhoten: 7H 8S 9D JC QH\n" };

        std::vector<Hand> hands{ 5 };

        while(!iss.eof()) {
            Hand h;
            iss >> h;
            hands.push_back(h);
        }

        ASSERT_EQ(2, hands.size());
    }

}
