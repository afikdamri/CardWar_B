#include <iostream>
#include "player.hpp"
#include <vector>
using namespace std;


namespace ariel
{
    Player::Player(const string& name) : name_(name) {}

    string Player::getName() const{
        return name_;
    }

    void Player::add(const Card& card){
        myStack_.push_back(card);
    }

    int Player::stacksize() const{
        return myStack_.size();
    }

    Card Player::getCard() {
        if (myStack_.empty()) {
            throw runtime_error("The deck is empty!");
        }
        Card firstCard = myStack_.front();
        myStack_.erase(myStack_.begin());
        return firstCard;
    }

    int Player::cardesTaken() const {
        return cardsTaken_.size();
    }

    void Player::takeCard(const vector<Card>& card) {
        for(const Card& c: card){
            cardsTaken_.push_back(c);
        }
    }
  
}
