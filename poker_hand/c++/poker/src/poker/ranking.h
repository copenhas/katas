namespace Ranking {
    class Score {
    private:
        Rank _rank;
        std::vector<Card> _value;

    public:
        Score(Rank, std::vector<Card>);
        Rank rank() const;
        std::vector<Card> value() const;
    };

    bool operator<(Score&, Score&);

    Score score(const std::vector<Card> &);
}
