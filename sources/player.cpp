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

    void Player::add(Card& card){
        myStack_.push_back(card);
        addcardsTaken(card);
    }

    int Player::stacksize() const{
        return myStack_.size();
    }

    Card Player::getCard(){
        if(myStack_.size() != 0){
            Card firstCard = myStack_.front();
            myStack_.erase(myStack_.begin());
            return firstCard;
        }else{
             throw runtime_error("The deck is empty!");
        }
    }

    void Player::addcardsTaken(Card& card){
        cardsTaken_.pop_back();
    }

    Player::~Player() {}

    
}
