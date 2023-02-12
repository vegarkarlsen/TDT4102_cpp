
#include "subprojects/std_lib_facilities/std_lib_facilities.h"
// #include "std_lib_facilities.h"
// #include <iostream>
// #include <ostream>
#include "card.h"
#include "cardDeck.h"
#include "blackjack.h"

// #include "windows.h"

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

    // cout << c.toString() << endl;
    // CardDeck cardDeck{};
    // cardDeck.shuffle();
    // cardDeck.printDeck();

    // make a startHand 
    // vector<Card> startHand{{cardDeck.drawCard(), cardDeck.drawCard()}};
    // Hand testHand{startHand};
    // testHand.evaluate();
    // std::cout << "handsum: " << testHand.handSum << std::endl;

    // Hand hand{};

    // hand.appendCard(cardDeck.drawCard());
    // hand.appendCard(cardDeck.drawCard());
    // cout << "cards in deck: " <<  cardDeck.countCards() << endl;
    // hand.evaluate();
    // hand.printHand();
    // hand.printHand(1);

    Blackjack b{5000};
    b.start();

    return 0;
}