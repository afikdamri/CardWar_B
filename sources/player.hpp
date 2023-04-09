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
        string name;
        vector<Card> myStack;

    public:
        Player(const std::string name);
        ~Player();
        void add(Card& card){myStack.push_back(card);}
        static int stacksize();
        static int cardesTaken();
    };

    Player::Player(const std::string name){
       this->name = name;
    }

    Player::~Player(){}
}
#endif