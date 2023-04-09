#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>
#include <vector>

#include "card.hpp"
using namespace std;

namespace ariel {
    class Player {
    private:
        string name_;
        vector<Card> myStack_;
        vector<Card> cardsTaken_;

    public:
        Player(const string& name);
        ~Player();
        void add(Card& card);
        void addcardsTaken(Card& card);
        int stacksize() const;
        int cardesTaken() const;
        string getName() const;
        Card getCard();
    };

}
#endif