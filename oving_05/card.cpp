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


// ♠
std::map<int, std::string> suitToStringMapPretty{
        {0, "C"},
        {1, "D"},
        {2, "H"},
        {3, "S"}
    };



std::map<int, std::string> rankToStringMapPretty{
    {2, "2"},
    {3, "3"},
    {4, "4"},
    {5, "5"},
    {6, "6"},
    {7, "7"},
    {8, "8"},
    {9, "9"},
    {10, "10"},
    {11, "J"},
    {12, "Q"},
    {13, "K"},
    {14, "A"}
};

void Card::prettyPrint(){
    int cardWidth = 9;
    
    string rank = rankToStringMapPretty.at(static_cast<int>(Card::r));
    string suit = suitToStringMapPretty.at(static_cast<int>(Card::s));

    cout << " --------" << endl;
    cout << "|" << rank << setw(cardWidth-1) << "|"<<endl;
    cout << "|" << suit << setw(cardWidth-1)<<"|"<<endl;
    cout << "|" << setw(cardWidth) << "|" << endl;
    cout << "|" << setw(cardWidth)<< "|"<< endl;
    cout << "|" << setw(cardWidth-1) << suit <<"|"<<endl;
    cout << "|" << setw(cardWidth-1) << rank << "|" <<endl;
    cout << " --------" << endl; 
}














