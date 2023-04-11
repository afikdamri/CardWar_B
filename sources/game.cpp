#include <iostream>
#include "game.hpp"
#include <algorithm>
#include <random>

using namespace std;

namespace ariel {
    Game::Game(Player& player1, Player& player2) : player1_(player1), player2_(player2) {
        draw_=0;
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
        string name = "";
        if (player1_.cardesTaken() > player2_.cardesTaken()) {
            name = player1_.getName();
            cout << name << " is the winner !!" << endl;
        }else if(player1_.cardesTaken() < player2_.cardesTaken()){
            name = player2_.getName();
            cout << name << "is the winner !!" << endl;
        }else if(player1_.cardesTaken() == player2_.cardesTaken()){
            cout <<" its a tie !!" << endl;
        }
    }

    void Game::playTurn(){
        if (&player1_ == &player2_) {
            throw invalid_argument("Player cannot play against himself.");
        }
        if(player1_.stacksize() != 0 && player2_.stacksize() != 0){
            Card cardPlayer1 = player1_.getCard();
            Card cardPlayer2 = player2_.getCard();
            cardGame_.push_back(cardPlayer1);
            cardGame_.push_back(cardPlayer2);
            log_.push_back(make_pair(cardPlayer1, cardPlayer2));
            if (cardPlayer1 > cardPlayer2){
               player1_.takeCard({cardPlayer1, cardPlayer2});
               cardGame_.clear();
            }
            else if (cardPlayer1 < cardPlayer2) {
                player2_.takeCard({cardPlayer1, cardPlayer2});
                cardGame_.clear();
            } 
            else {
                while (cardPlayer1 == cardPlayer2 && player1_.stacksize() > 0 && player2_.stacksize() > 0)
                {
                    draw_++;
                    cardGame_.push_back(player1_.getCard());
                    cardGame_.push_back(player2_.getCard());
                    cardPlayer1 = player1_.getCard();
                    cardPlayer2 = player2_.getCard();
                    cardGame_.push_back(cardPlayer1);
                    cardGame_.push_back(cardPlayer2);

                }
                if(cardPlayer1 > cardPlayer2){
                    player1_.takeCard(cardGame_);
                }else if(cardPlayer1 < cardPlayer2){
                    player2_.takeCard(cardGame_);
                }else{
                    for (size_t i = 0; i < cardGame_.size(); i++) {
                        if(i%2 == 1){
                            player1_.add(cardGame_[i]);
                        }else{
                            player2_.add(cardGame_[i]);
                        }
                    }
                }
                
            }
        }else{
            throw ::invalid_argument("Player has no card.");
        }
}


    void Game::playAll() {
    while (player1_.stacksize() > 0 && player2_.stacksize() > 0) {
        try {
            playTurn();
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
            break;
        }
    }
}

        void Game::printLastTurn() {
            if (log_.empty()) {
                cout << "No turns have been played yet." << endl;
                return;
            }
            pair<Card, Card>& lastPair = log_.back();
            Card firstCard = lastPair.first;
            Card secondCard = lastPair.second;
            cout << player1_.getName() << " played " << firstCard.toString();
            cout << ", " << player2_.getName() << " played " << secondCard.toString();
            if (firstCard < secondCard) {
                cout << ", " << player2_.getName() << " wins!" << endl;
            } else if (firstCard > secondCard) {
                cout << ", " << player1_.getName() << " wins!" << endl;
            } else {
                cout << ", it's a draw!" << endl;
            }
        }

    void Game::printLog(){
        for (const auto& pair : log_) {
            cout << player1_.getName() << " played " << pair.first.toString();
            cout <<", "<< player2_.getName() << " played " << pair.second.toString() << endl;
        }
    }

    void Game::printStats() {
        int totalGames = player1_.cardesTaken() + player2_.cardesTaken() + draw_;
        double p1WinRate = ((double) player1_.cardesTaken() / totalGames)*100;
        double p2WinRate = ((double) player2_.cardesTaken() / totalGames)*100;
        double drawRate = ((double) draw_ / totalGames)*100;

        cout << "Player " << player1_.getName() << ":" << endl;
        cout << "Win rate: " << p1WinRate <<"%"<<endl;
        cout << "Cards won: " << player1_.cardesTaken() << endl;
        cout << "Draw rate: " << drawRate <<"%"<<endl;
        cout << "Draws: " << draw_ << endl << endl;

        cout << "Player " << player2_.getName() << ":" << endl;
        cout << "Win rate: " << p2WinRate << "%"<<endl;
        cout << "Cards won: " << player2_.cardesTaken() << endl;
        cout << "Draw rate: " << drawRate <<"%"<< endl;
        cout << "Draws: " << draw_ << endl << endl;
    }

}
