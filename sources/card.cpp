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

    string Card::printSuit() const{
        string suit = "";
        if(suit_ == Suit::CLUBS){
            suit = "Clubs";
        }
        else if(suit_ == Suit::DIAMONDS){
            suit = "Diamonds";
        }   
        else if(suit_ == Suit::HEARTS){
            suit = "Hearts";
        }
        else if(suit_ == Suit::SPADES){
            suit = "Spades";
        }
        return suit;
    }

    string Card::printRank() const{
        string rank = "";
        if(rank_ == Rank::ACE){
            rank = "1";
        }
        else if(rank_ == Rank::TWO){
            rank = "2";
        }   
        else if(rank_ == Rank::THREE){
            rank = "3";
        }
        else if(rank_ == Rank::FOUR){
            rank = "4";
        }
        else if(rank_ == Rank::FIVE){
            rank = "5";
        }   
        else if(rank_ == Rank::SIX){
            rank = "6";
        }
        else if(rank_ == Rank::SEVEN){
            rank = "7";
        }
        else if(rank_ == Rank::EIGHT){
            rank = "8";
        }   
        else if(rank_ == Rank::NINE){
            rank = "9";
        }
        else if(rank_ == Rank::TEN){
            rank = "10";
        }
        else if(rank_ == Rank::JACK){
            rank = "Jack";
        }
        else if(rank_ == Rank::QUEEN){
            rank = "Queen";
        }
        else if(rank_ == Rank::KING){
            rank = "King";
        }
        return rank;
    }
    string Card::toString() const{
        return printRank() + " of " + printSuit();
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