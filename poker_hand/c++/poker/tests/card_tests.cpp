#include <sstream>

#include "gtest/gtest.h"
#include "poker.h"

using namespace Poker;

namespace CardTests {
    TEST(Card, cards_can_not_be_used_without_a_face) {
        Card c;
        try {
            c.face();
        }
        catch(...) {
            EXPECT_TRUE(true);
            return;
        }

        EXPECT_FALSE(true) << "Using an uninitialied card should fail";
    }

    TEST(Card, cards_can_not_be_used_without_a_suit) {
        Card c;
        try {
            c.suit();
        }
        catch(...) {
            EXPECT_TRUE(true);
            return;
        }

        EXPECT_FALSE(true) << "Using an uninitialied card should fail";
    }

    TEST(Card, prints_two_character_representation) {
        std::basic_ostringstream<char> oss;

        Card c { Face::king, Suit::hearts };
        oss << c;

        EXPECT_EQ("KH", oss.str());
    }

    TEST(Card, invalid_first_character_errors) {
        std::basic_istringstream<char> iss { "kM" };

        try {
            Card c;
            iss >> c;
        }
        catch(...) {
            EXPECT_TRUE(true);
            return;
        }

        EXPECT_FALSE(true) << "Invalid character should fail";
    }

    TEST(Card, invalid_second_character_errors) {
        std::basic_istringstream<char> iss { "2M" };

        try {
            Card c;
            iss >> c;
        }
        catch(...) {
            EXPECT_TRUE(true);
            return;
        }

        EXPECT_FALSE(true) << "Invalid character should fail";
    }

    TEST(Card, not_enough_in_stream_errors) {
        std::basic_istringstream<char> iss { "2" };

        try {
            Card c;
            iss >> c;
        }
        catch(...) {
            EXPECT_TRUE(true);
            return;
        }

        EXPECT_FALSE(true) << "Invalid character should fail";
    }

    TEST(Card, parses_two_characters_as_card) {
        std::basic_istringstream<char> iss { "2S" };

        Card c;
        iss >> c;

        EXPECT_EQ(Face::two, c.face());
        EXPECT_EQ(Suit::spades, c.suit());
    }

}
