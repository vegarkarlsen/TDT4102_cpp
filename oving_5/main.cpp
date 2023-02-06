
#include "subprojects/std_lib_facilities/std_lib_facilities.h"
// #include "std_lib_facilities.h"
// #include <iostream>
// #include <ostream>
#include "card.h"
#include "cardDeck.h"

/*
oppgave 1 e)
Det er mer oversiktlig å bruke symboler
lettere å koble sammen kortene
*/


int main(){
    
    // Rank r = Rank::king;
    // Suit s = Suit::hearts;
    // string rank = rankToString(r);
    // string suit = suitToString(s);
    // cout << "rank: " << rank << " suit: " << suit << endl;

    // Rank r = static_cast<Rank>(11);
    // Suit s = static_cast<Suit>(3);
    // Card c{s,r};
    // cout << c.toString() << endl;

    CardDeck cardDeck{};
    cardDeck.shuffle();
    cardDeck.printDeck();
    Card card = cardDeck.drawCard();
    
    return 0;

}