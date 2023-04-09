#include <iostream>
#include "game.hpp"
#include <algorithm>
#include <random>

using namespace std;

namespace ariel {
    Game::Game(Player& player1, Player& player2) : player1_(player1), player2_(player2) {
        vector<Card> cards;
        for (int row = (int)Rank::TWO; row <= (int)Rank::ACE; row++) {
            for (int col = (int)Suit::CLUBS; col <= (int)Suit::SPADES; col++) {
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
        v1.insert(v1.begin(), deck_.begin(), deck_.begin() + static_cast<long>(mid));
        v2.insert(v2.begin(), deck_.begin() + static_cast<long>(mid), deck_.end());

        for (int i = 0; i < static_cast<int>(v1.size()); i++) {
            player1_.add(v1[static_cast<size_t>(i)]);
            player2_.add(v2[static_cast<size_t>(i)]);
        }

        v1.clear();
        v2.clear();
    }

    void Game::printWiner() {
        if (player1_.stacksize() == 0 || player2_.stacksize() == 0) {
            string name = "";
            if (player1_.stacksize() > player2_.stacksize()) {
                name = player1_.getName();
            } else {
                name = player2_.getName();
            }
            cout << name << " is the winner !!" << endl;
        } else {
            cout << "There is no winner yet." << endl;
        }
    }

    void Game::playTurn(){
    if(player1_.stacksize() != 0 && player2_.stacksize() != 0){
        Card cardPlayer1 = player1_.getCard();
        Card cardPlayer2 = player2_.getCard();
        cardGame_.push_back(cardPlayer1);
        cardGame_.push_back(cardPlayer2);
        if(cardGame_.back() > cardGame_[cardGame_.size()-2]){
          for (size_t i = 0; i < cardGame_.size(); i++) {
                player2_.add(cardGame_[i]);
            }
            cardGame_.clear();
        }else if(cardGame_.back() < cardGame_[cardGame_.size()-2]){
            for (size_t i = 0; i < cardGame_.size(); i++) {
                player1_.add(cardGame_[i]);
            }
            cardGame_.clear();
            }
            else{
                Card cardPlayer1 = player1_.getCard();
                Card cardPlayer2 = player2_.getCard();
                cardGame_.push_back(cardPlayer1);
                cardGame_.push_back(cardPlayer2);

            }
        }
    }
}
