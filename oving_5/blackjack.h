
#pragma once
#include "subprojects/std_lib_facilities/std_lib_facilities.h"
#include "card.h"
#include "cardDeck.h"


class Blackjack{
    private:
        CardDeck deck;
        int getValue();
        int saldo;
        
    public:
        Blackjack(int startSaldo);

};