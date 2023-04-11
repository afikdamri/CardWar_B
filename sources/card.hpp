#ifndef CARD_HPP
#define CARD_HPP

#include <string>
using namespace std;

namespace ariel{
    enum Rank{
        TWO = 2,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        JACK,
        QUEEN,
        KING,
        ACE,
    };

    enum Suit{
        CLUBS, DIAMONDS, HEARTS, SPADES,
    };

    class Card {
    private:
        Suit suit_;
        Rank rank_;
    public:
        Card(Suit suit, Rank rank);
        Suit getSuit() const;
        Rank getRank() const;
        string printSuit() const;
        string printRank() const;
        string toString() const;
        bool operator>(const Card& card) const;
        bool operator<(const Card& card) const;
        bool operator==(const Card& card) const;

    };

}

#endif // CARD_HPP
