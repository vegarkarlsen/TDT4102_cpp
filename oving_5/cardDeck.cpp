
#include "cardDeck.h"
#include "random.h"

CardDeck::CardDeck(){
    for (int s = 0; s < 4 ; s++){
        // trough suit
        for (int r = 2; r < 15; r++){
            // trough rank
            Suit suit = static_cast<Suit>(s);
            Rank rank = static_cast<Rank>(r);
            Card card{suit,rank};
            CardDeck::cards.push_back(card);

            // debug:
            // std::cout << "appended:  " << card.toString() << std::endl;

        }
    }
}


void CardDeck::swap(int card1, int card2){
    // store one card
    Card backupCard1 = CardDeck::cards.at(card1);
    
    CardDeck::cards.at(card1) = CardDeck::cards.at(card2);

    CardDeck::cards.at(card2) = backupCard1;
}



void CardDeck::printDeck(){
    for (auto& card : CardDeck::cards){
        std::cout << card.toString() << std::endl;
    }
}


void CardDeck::shuffle(){
    // random shuftle number
    // swap random two random cards

    int shufleRounds = randomWithLimits(100, 1000);
    int cardIndex1;
    int cardIndex2;

    for (int i = 0; i < shufleRounds; i++){
        cardIndex1 = randomWithLimits(0,51);
        cardIndex2 = randomWithLimits(0,51);
        // std::cout << "changig card: " << cardIndex1 << " with " << cardIndex2 << std::endl;
        CardDeck::swap(cardIndex1, cardIndex2);
    }
}

Card CardDeck::drawCard(){
    if (!CardDeck::cards.empty()){
        Card card = CardDeck::cards.back();
        CardDeck::cards.pop_back();
        return card;
    }

    // if deck empty return random card
    Card card{Suit::clubs, Rank::ace};
    std::cout << "deck is empty, returning ace of spades" << std::endl;
    return card;
}