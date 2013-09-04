#include <string>
#include <iostream>
#include <vector>

namespace Poker {
    enum class Rank : int {
        no_rank = 0,
        high_card = 1,
        pair = 2,
        two_pair = 3,
        three_of_a_kind = 4,
        straight = 5,
        flush = 6,
        full_house = 7,
        four_of_a_kind = 8,
        straight_flush = 9
    };

    enum class Face: int {
        None = 0,
        two = 2,
        three = 3,
        four = 4,
        five = 5,
        six = 6,
        seven = 7,
        eight = 8,
        nine = 9,
        ten = 10,
        jack = 11,
        queen = 12,
        king = 13,
        ace = 14
    };

    Face char_to_face(char);
    char face_to_char(Face);

    enum class Suit: char {
        None = ' ',
        clubs = 'C',
        diamonds = 'D',
        hearts = 'H',
        spades = 'S'
    };

    class Card {
    private:
        Face fc;
        Suit st;

    public:
        Card();
        Card(Face,Suit);
        Face face() const;
        Suit suit() const;

        static bool read_card(std::istream&, Card&);
    };

    bool operator<(const Card&, const Card&);
    std::ostream& operator<<(std::ostream&, Card);

    class Hand {
    private:
        std::string _player;
        std::vector<Card> _cards;
        Rank _rank;

    public:
        Hand();
        Hand(std::string);
        std::string player() const;
        void set_player(std::string);
        const std::vector<Card>& cards() const;
        void add_card(Card);
        Rank rank() const;

        static bool read_hand(std::istream&, Hand&);
    };

    std::istream& operator>>(std::istream&, Hand &);
    std::ostream& operator<<(std::ostream&, Hand);

    void read_from_file(std::string file);

    namespace Ranking {
        class HandRank {
        public:
            virtual ~HandRank();
            virtual const std::string name() const;
            virtual Rank value() const;
        };

        HandRank CreateRank(const Hand &);

        class NoRank: public HandRank {
        public:
            const std::string name() const;
            Rank value() const;
        };

        class StraightFlush: public HandRank {
        public:
            StraightFlush(const Hand &);
            const std::string name() const;
            Rank value() const;

            static bool matches(Hand &);
        };
    }
}
