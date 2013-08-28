#include <string>
#include <iostream>
#include <vector>

namespace Poker {
    enum class Face: char {
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

    public:
        Hand();
        Hand(std::string);
        std::string player() const;
        void set_player(std::string);
        const std::vector<Card>& cards() const;
        Card high_card() const;
        void add_card(Card);

        static bool read_hand(std::istream&, Hand&);
    };

    std::istream& operator>>(std::istream&, Hand &);
    std::ostream& operator<<(std::ostream&, Hand);

    void read_from_file(std::string file);

    namespace Rank {
        class HandRank {
        public:
            virtual const std::string name();
            virtual int value();
            virtual bool matches(const Hand&);
        };

        class StraightFlush: public HandRank {
        public:
            const std::string name();
            int value();
            bool matches(const Hand&);
        };
    }
}
