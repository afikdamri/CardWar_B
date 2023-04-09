#ifndef GAME_HPP
#define GAME_HPP

#include "player.hpp"
#include<vector>

namespace ariel{
    class Game {
    private:
        Player& Player1_;
        Player& Player2_;
        vector<Card> deck_;
    public:
        Game(Player& Player1, Player& Player2) : Player1_(Player1), Player2_(Player2) {}
        ~Game(){}
        void playAll(){}
        void printWiner(){}
        void printLog(){}
        void printStats(){}
        void printLastTurn(){}
        void playTurn(){}
    };
}

#endif /* GAME_HPP */
