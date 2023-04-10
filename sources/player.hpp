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
        int cardsTaken_;

    public:
        Player(const string& name);
        ~Player();
        void add(Card& card);
        void addcardsTaken();
        int stacksize() const;
        int cardesTaken() const;
        string getName() const;
        void takeCard();
        Card getCard();
    };

}
#endif