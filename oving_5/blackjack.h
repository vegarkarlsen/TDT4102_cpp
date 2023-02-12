
#pragma once
#include "subprojects/std_lib_facilities/std_lib_facilities.h"
#include "card.h"
#include "cardDeck.h"
#include "hand.h"


// const int outWidth = 20;


// get integer from console
int inputInt(string prompt);

// get char from console, returns char lower
char inputChar(string promt);



class Blackjack{
    private:
        CardDeck deck;
        int saldo;
        int betAmount;

        Hand dealerHand;
        Hand playerHand;

        void userBet();

        // take card from deck and put it in hand
        // alse evaluates hand
        void dealCard(Hand& hand);

        // paramter: number of cards to hide from dealer
        void printHands(int hide = 0);

        // returns true if dealer bust, else false
        bool dealerTryWin();

        // result {0: dealer won, 1: player won, 2: Draw}
        void roundResult(int result);

        // returns true if player has busted
        bool playerAction();

        // one game
        void gameLoop();

        // doublle down
        void doubleDown();
        
    public:
        // shufle deck when inizialise
        Blackjack(int startSaldo);

        // gameloop 
        void start();

};

