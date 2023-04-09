#ifndef GAME_HPP
#define GAME_HPP

#include "player.hpp"
#include<vector>

namespace ariel{
    class Game {
    private:
        Player& player1_;
        Player& player2_;
        vector<Card> deck_;
        vector<Card> cardGame_;
        vector<pair <Card, Card>> log_;
    public:
        Game(Player& Player1, Player& Player2);
        ~Game(){}
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
        void printLastTurn();
        void playTurn();
    };
}

#endif /* GAME_HPP */
