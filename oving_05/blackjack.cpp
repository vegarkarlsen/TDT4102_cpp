#include "blackjack.h"


int inputInt(string prompt){
    
    int value;
    std::cout << prompt;
    std::cin >> value;
    return value;
}

char inputChar(string prompt){
    char value;
    std::cout << prompt;
    std::cin >> value;
    return tolower(value);
}


Blackjack::Blackjack(int startSaldo) : saldo{startSaldo}
{
    // shuffle card deck
    Blackjack::deck.shuffle();
}

// could use unsigned int beacuse we only accept positive values
void Blackjack::userBet(){
    bool betAccepted = 0;
    

    while (!betAccepted){

        Blackjack::betAmount = inputInt("Bet amount: ");

        if (Blackjack::betAmount >= 0 && Blackjack::betAmount <= Blackjack::saldo){
            betAccepted = 1;
            break;
        }
    }

    Blackjack::saldo -= Blackjack::betAmount; 
}

void Blackjack::dealCard(Hand& hand){
    hand.appendCard(Blackjack::deck.drawCard());
    hand.evaluate();
}

void Blackjack::printHands(int hide){
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "Delear cards: ";
    Blackjack::dealerHand.printHand(hide);

    std::cout << "Your cards: " ;
    Blackjack::playerHand.printHand();
    std::cout << "Your bet: " << Blackjack::betAmount << std::endl;
    std::cout << "--------------------------------------" << std::endl;
}

// returns true if dealer bust, else false
bool Blackjack::dealerTryWin(){
    // delearSum < playerSum and dealersum < 17
    while (Blackjack::dealerHand.handSum < Blackjack::playerHand.handSum && Blackjack::dealerHand.handSum < 17){
        Blackjack::dealCard(Blackjack::dealerHand);
    }
    
    if (Blackjack::dealerHand.checkForBust()){
        return 1;
        
    }
    return 0;

}


// could used enum for result here to get more readable code
// // result {0: dealer won, 1: player won, 2: Draw}
void Blackjack::roundResult(int result){
    Blackjack::printHands();

    switch (result) 
    {   
        case 0:
            std::cout << "you lost!" << std::endl;
            break;
        case 1:
            Blackjack::saldo += 2*Blackjack::betAmount;
            std::cout << "you won " << 2*Blackjack::betAmount << "! Saldo: " << Blackjack::saldo << std::endl;
            break;
        case 2:
            std::cout << "Draw!" << std::endl;
            Blackjack::saldo += Blackjack::betAmount;
            break;
        default:
            break;
    }
    std::cout << std::endl;
}

// returns true if player has busted, else false 
// TODO: add split when card is 10 and 10
bool Blackjack::playerAction(){

    while (1){

        char action = inputChar("hit (h), stand (s), doubble (d) ");

        switch (action)
        {
        case 'h':
            Blackjack::dealCard(Blackjack::playerHand);
            Blackjack::printHands(1);
            // if player busts return 1
            if (Blackjack::playerHand.checkForBust()){
                return 1;
            }
            break;
        
        case 's':
            // return 0 exit, no bust
            return 0;
            break;

        case 'd':
            // double down, draw one card and exit
            Blackjack::doubleDown();
            Blackjack::printHands(1);
            if (Blackjack::playerHand.checkForBust()){
                return 1;
            }
            else {
                return 0;
            }
            break;

        // case 'p':
        //     std::cout << "no supprot for split yet" << std::endl;

        default:
            break;
        }

    }
    return 0;
}

void Blackjack::gameLoop(){

    // inizialize game
    Blackjack::dealerHand.clear();
    Blackjack::playerHand.clear();

    // deal two cards in the beginning
    for (int i = 0; i < 2; i++){
        Blackjack::dealCard(Blackjack::playerHand);
        Blackjack::dealCard(Blackjack::dealerHand);
    }

    // bet amont
    Blackjack::userBet();
    
    // evalute for real blackjack:
    // -----------------------------
    // dealer won:
    if (Blackjack::dealerHand.checkBlackjack() && !Blackjack::playerHand.checkBlackjack()){
        // Blackjack::printHands();
        Blackjack::roundResult(0);
        return;
    }
    // player won:
    else if (Blackjack::playerHand.checkBlackjack() && !Blackjack::dealerHand.checkBlackjack()){
        // Blackjack::printHands();
        Blackjack::roundResult(1);
        return;
    }
    // draw:
    else if (Blackjack::playerHand.checkBlackjack() && !Blackjack::dealerHand.checkBlackjack()){
        // Blackjack::printHands();
        Blackjack::roundResult(2);
        return;
    }
    // ---------------------------
    
    // hide dealer 2. card on printout
    Blackjack::printHands(1);

    // player action (hit, stand, doublle)
    bool playerBust = Blackjack::playerAction();
    if (playerBust){
        Blackjack::roundResult(0);
        return;
    }
    // dealer draw cards until won or bust
    bool dealerBust = Blackjack::dealerTryWin();
    if (dealerBust){
        Blackjack::roundResult(1);
        return;
    }

    // playerSum > dealerSum ==> player won
    if (Blackjack::playerHand.handSum > Blackjack::dealerHand.handSum){
        Blackjack::roundResult(1);
    }
    // playerSum == dealerSum ==> draw
    else if (Blackjack::playerHand.handSum == Blackjack::dealerHand.handSum){
        Blackjack::roundResult(2);
    }
    // you lose
    else {
        Blackjack::roundResult(0);
    }

}

void Blackjack::start(){
    while (1){
        std::cout << "Saldo: " << Blackjack::saldo << std::endl;
        char action = inputChar("Play (p), Exit (e): ");
        // exit gameloop on e
        if (action == 'e'){
            std::cout << "goodbye!" << std::endl;
            break;
        }
        // play until exit
        Blackjack::gameLoop();
    }
}

void Blackjack::doubleDown(){
    Blackjack::betAmount *= 2;
    // std::cout << "dobble down, total bet is now: " << Blackjack::betAmount << std::endl;
    Blackjack::dealCard(Blackjack::playerHand);
}