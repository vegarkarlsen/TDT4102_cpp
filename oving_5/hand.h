
#pragma once
#include "subprojects/std_lib_facilities/std_lib_facilities.h"
#include "card.h"
#include "cardDeck.h"



class Hand{
    private:
        // get value of induvidual card, (use in calculateHandSum())
        int getCardValue(Card card);
        // calculate handsum (need to know if you have aces)
        void calculateHandSum();

        // check for real blackjack (only two cards and sum = 11)
        // need to be done after calucating sum
        



    public:
        // cards on hand
        vector<Card> cardsOnhand;
        // value of hand
        int handSum = 0;

        // start by dealing cards
        // Hand();
        // append card to hand
        void appendCard(Card card);
        // this does all hand calcualtions
        void evaluate();

        // prints hand, has to hide second card if dealer:
        void printHand(int hide = 0); // comment: only define defalue pramter i .h file

        // check for real blackjack
        bool checkBlackjack();

        // returns true if player is bust
        bool checkForBust();

        // clear hand
        void clear();
        

};