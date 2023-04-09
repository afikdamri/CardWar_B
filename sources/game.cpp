#include<iostream>
#include "game.hpp"
#include <algorithm>
#include <random>
using namespace std;

namespace ariel {
    Game::Game(Player& p1ayer1, Player& player2) : player1_(p1ayer1), player2_(player2) {
        vector<Card> cards;
        for(int row = (int)Rank::TWO; row  <= (int)Rank::ACE; row++){
            for (int col = (int)Suit::CLUBS; col <= (int)Suit::SPADES; col++)
            {
                Card c((Suit)col, (Rank)row);
                cards.push_back(c);
            }
        }
        random_device rd;
        default_random_engine rng(rd());
        shuffle(cards.begin(), cards.end(), rng);
        deck_ = cards;

        vector<Card> v1;
        vector<Card> v2;
        size_t mid = deck_.size() / 2;
        v1.insert(v1.begin(), deck_.begin(), deck_.begin() + mid);
        v2.insert(v2.begin(), deck_.begin() + mid, deck_.end());

        for(int i = 0; i < v1.size(); i++){
            player1_.add(v1[i]);
            player2_.add(v2[i]);
        }
        v1.clear();
        v2.clear();
    }

}