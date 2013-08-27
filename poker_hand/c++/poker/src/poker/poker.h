#include <string>
#include <iostream>
#include <vector>

namespace Poker {
    enum class Face: char {
        None = ' ',
        two = '2',
        three = '3',
        four = '4',
        five = '5',
        six = '6',
        seven = '7',
        eight = '8',
        nine = '9',
        ten = '0',
        jack = 'J',
        queen = 'Q',
        king = 'K',
        ace = 'A'
    };

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
            void add_card(Card);

            static bool read_hand(std::istream&, Hand&);
    };

    std::istream& operator>>(std::istream&, Hand &);
    std::ostream& operator<<(std::ostream&, Hand);

    void read_from_file(std::string file);
}
