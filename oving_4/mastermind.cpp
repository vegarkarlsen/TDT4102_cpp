
#include "std_lib_facilities.h"
#include "mastermind.h"






int checkCharacterAndPosition(string guess, int letters){
    int nRight = 0;
    char currentToCheck;
    char checkAgainst;
    for (int i = 0; i < letters; i++) {
        currentToCheck = guess[i];
        checkAgainst = 'a' + (i - 1);

        if (currentToCheck == checkAgainst) {
            nRight++;
        }
    }
    return nRight;

}

int checkCharacter(string guess, int letters){
    
}



void playMastermind(){

    constexpr int size = 4;
    constexpr int letters = 6;

    string code;
    string guess;

    bool running = 1;
    char maxChar = 'a' + (letters - 1);

    int rightPos = 0;
    int rightCharWrongPos = 0;

    code = randomizeString(letters, 'a', maxChar);

    while (running){
        guess = readInputToString('a', maxChar, letters);

        rightPos = checkCharacterAndPosition(guess, letters);





    }


}