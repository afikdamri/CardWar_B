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
        cout<< card.toString();
        for (const Card& card : myStack_) {
            card.toString();
        }
        cout << "--------"<<endl;
        addcardsTaken();
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

    void Player::addcardsTaken(){
        myStack_.pop_back();
    }

    int Player::cardesTaken() const {
        return cardsTaken_;
    }

    void Player::takeCard() {
        cardsTaken_++;
    }

    Player::~Player() {}

    
}
