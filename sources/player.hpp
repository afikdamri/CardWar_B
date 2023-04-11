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
        void add(const Card& card);
        int stacksize() const;
        int cardesTaken() const;
        string getName() const;
        void takeCard(const vector<Card>& card);
        Card getCard();
    };

}
#endif