#include<iostream>
#include "card.hpp"

namespace ariel {
    Card::Card(Suit suit, Rank rank) : suit_(suit), rank_(rank){}

    Suit Card::getSuit() const{
        return this->suit_;
    }

    Rank Card::getRank() const{
        return this->rank_;
    }

    void Card::printSuit() const{
        if(suit_ == Suit::CLUBS){
            std::cout << "Clubs";
        }
        else if(suit_ == Suit::DIAMONDS){
            std::cout << "Diamonds";
        }   
        else if(suit_ == Suit::HEARTS){
            std::cout << "Hearts";
        }
        else if(suit_ == Suit::SPADES){
            std::cout << "Spades";
        }
    }

    void Card::printRank() const{
        if(rank_ == Rank::ACE){
            std::cout << "1";
        }
        else if(rank_ == Rank::TWO){
            std::cout << "2";
        }   
        else if(rank_ == Rank::THREE){
            std::cout << "3";
        }
        else if(rank_ == Rank::FOUR){
            std::cout << "4";
        }
        else if(rank_ == Rank::FIVE){
            std::cout << "5";
        }   
        else if(rank_ == Rank::SIX){
            std::cout << "6";
        }
        else if(rank_ == Rank::SEVEN){
            std::cout << "7";
        }
        else if(rank_ == Rank::EIGHT){
            std::cout << "8";
        }   
        else if(rank_ == Rank::NINE){
            std::cout << "9";
        }
        else if(rank_ == Rank::TEN){
            std::cout << "10";
        }
        else if(rank_ == Rank::JACK){
            std::cout << "Jack";
        }
        else if(rank_ == Rank::QUEEN){
            std::cout << "Queen";
        }
        else if(rank_ == Rank::KING){
            std::cout << "King";
        }
    }
    void Card::toString() const{
        printRank();
        std::cout << "of";
        printSuit();
        std::cout << endl;
    }

    bool Card::operator==(const Card& card) const {
        if(this->rank_ == card.rank_)
            return true;
        else
            return false;
    }

    bool Card::operator<(const Card& card) const {
        if(this->rank_ == Rank::ACE && card.rank_ == Rank::TWO) {
            return true;
        }
        else if(this->rank_ == Rank::TWO && card.rank_ == Rank::ACE) {
            return false;
        }
        else if(this->rank_ < card.rank_){
            return true;
        }else{
            return false;
        }
    }

    bool Card::operator>(const Card& card) const {
        if(this->rank_ == Rank::ACE && card.rank_ == Rank::TWO) {
            return false;
        }
        else if(this->rank_ == Rank::TWO && card.rank_ == Rank::ACE) {
            return true;
        }
        else if(this->rank_ > card.rank_){
            return true;
        }else{
            return false;
        }
    }
}