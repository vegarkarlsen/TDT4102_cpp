
#include "hand.h"


// Hand::Hand(){}
/*
    [10, king] = 10, [ace] = 1 or 11 (set to 11)
*/
int Hand::getCardValue(Card card){
    // this will give cardValue = [2, 14]
    int cardRawValue = card.getRank();

    // between 10 and king
    if (cardRawValue > 10 && cardRawValue < 14){
        return 10;
    }
    // card is ace
    else if (cardRawValue == 14){
        return 11;
    }
    // card is between [2, 10]
    else {
        return cardRawValue;    
    }
}

void Hand::appendCard(Card card){
    Hand::cardsOnhand.push_back(card);
}

// loop through hand:
// sum up handSum
// check for ace and then recorrect sum if > 21
// this should set Hand::HandSum
void Hand::calculateHandSum(){
    
    int currentCardValue;
    
    // set aces to 0 before starting checking sum
    int aces = 0;
    int handSum = 0;
    
    for (auto card : Hand::cardsOnhand){
        currentCardValue = Hand::getCardValue(card);
        handSum += currentCardValue;
        // debuging
        // std::cout << "checkcing card: " << card.toString() << " = " << currentCardValue << std::endl;
        
        // checking for ace
        if (currentCardValue == 11){
            // std::cout << "found an ace" << std::endl;
            aces++;
        }
    }

    // if handSum > 21 we need to correct sum
    if (handSum > 21){
        // subtract (11 - 1) = 10 for each aces to reach handSum <= 21:
        // if aces = 0 this will hopefully just skip TODO:(need to check)
        for (int i = 0; i < aces; i++){
            handSum -= 10;
            // stop correcting if sum < 21;
            if (handSum <= 21){
                break;
            }
        }
    }

    // setting membervariable instead of returning
    Hand::handSum = handSum;
}


// check for real blackjack (only two cards and sum = 11)
// need to be done after calucating sum
// this uses values calculated from calcualteHandSum 
bool Hand::checkBlackjack(){
    int nCards = static_cast<int>(Hand::cardsOnhand.size());
    return (nCards == 2 && Hand::handSum == 21);
    
}

void Hand::evaluate(){
    Hand::calculateHandSum();
    Hand::checkBlackjack();
}


void Hand::printHand(int hide){
    // FIXME: hide can only be = 0 or 1, no supprot for hiding more cards (not necessary)
    int nCardsToShow = static_cast<int>(Hand::cardsOnhand.size()) - hide;

    // print each hand verticaly
    for (int i = 0; i < nCardsToShow; i++){
        std::cout << "[" <<  Hand::cardsOnhand.at(i).toString() << "]"  << ", " ;
    }
    std::cout << std::endl;
    
    // TODO: could print somthing could to show hidden card
    

    // print sum

    int showSum = Hand::handSum;

    // uncomment this code for supprt of hiding more than one card:
    // for (int i = static_cast<int>(Hand::cardsOnhand.size()); i > nCardsToShow; i--){
    //     showSum -= getCardValue(Hand::cardsOnhand.at(i));
    // }
    
    // hard coded hiding only last card
    if (hide > 0){
        showSum -= getCardValue(Hand::cardsOnhand.back());
    }
    
    std::cout << "sum: " << showSum << std::endl;
    
}

void Hand::clear(){
    Hand::cardsOnhand.clear();
    Hand::handSum = 0;
}

bool Hand::checkForBust(){
    return (Hand::handSum > 21);
}
