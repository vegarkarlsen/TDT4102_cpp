
#pragma once

// #include "std_lib_facilities.h"
// #include <string>
// #include <map>
#include "subprojects/std_lib_facilities/std_lib_facilities.h"


enum class Suit {clubs, diamonds, hearts, spades};

enum class Rank {two = 2, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace};


// map can only be defined in .h if it is const
// alternative use extern to declare and define in cpp:
string suitToString(Suit suit);

string rankToString(Rank rank);


class Card {
    private:
        Suit s;
        Rank r;
        
    public:
        Card(Suit suit, Rank rank);
        string getSuit();
        int getRank();
        string toString();
        void prettyPrint();


};


