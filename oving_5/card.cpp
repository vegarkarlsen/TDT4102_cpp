#include "card.h"

std::map<int, std::string> suitToStringMap{
        {0, "Clubs"},
        {1, "Diamonds"},
        {2, "Hearts"},
        {3, "Spades"}
    };

string suitToString(Suit suit){
    return suitToStringMap.at(static_cast<int>(suit));
}

std::map<int, std::string> rankToStringMap{
        {2, "Two"},
        {3, "Three"},
        {4, "Four"},
        {5, "Five"},
        {6, "Six"},
        {7, "Seven"},
        {8, "Eight"},
        {9, "Nine"},
        {10, "Ten"},
        {11, "Jack"},
        {12, "Queen"},
        {13, "King"},
        {14, "Ace"}
    };

string rankToString(Rank rank){
    return rankToStringMap.at(static_cast<int>(rank));
}

// Card
Card::Card(Suit suit, Rank rank): s{suit}, r{rank}
{}

string Card::getSuit(){
    return suitToString(Card::s);
}

// returns int value? should this return string??
int Card::getRank(){
    return static_cast<int>(Card::r);
}

// returns string of card eks "ten of hearts"
string Card::toString(){
    return rankToString(Card::r) + " of " +  suitToString(Card::s);
}








