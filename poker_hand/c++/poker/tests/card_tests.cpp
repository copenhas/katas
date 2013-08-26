#include <sstream>

#include "gtest/gtest.h"
#include "poker.h"

using namespace Poker;

namespace CardTests {
    TEST(Card, prints_two_character_representation) {
        std::basic_ostringstream<char> oss;

        Card c { Face::king, Suit::hearts };
        oss << c;

        EXPECT_EQ("KH", oss.str());
    }
}
