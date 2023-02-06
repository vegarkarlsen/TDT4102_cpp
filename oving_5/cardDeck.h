#pragma once

#include "subprojects/std_lib_facilities/std_lib_facilities.h"
#include "card.h"


class CardDeck{
    private:
        vector<Card> cards;
        // this is private because we dont want to swap on accsident
        void swap(int card1, int card2);
        
    
    public:
        CardDeck();
        void printDeck();
        void shuffle();
        // draws a card and remove it from the deck
        Card drawCard();
};
