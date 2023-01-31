
#include "std_lib_facilities.h"
#include "mastermind.h"



int checkCharacterAndPosition(string guess, string code, int size){
    int rightPos = 0;

    for (int i = 0; i < size; i++){
        if (guess[i] == code[i]) rightPos++;
    }

    return rightPos;
}

int checkCharacter(string guess, string code, int letters){

    int currentCountCode = 0;
    int currentCountGuess = 0;
    char currentChar;
    int totalCharactersRight = 0;

    for (int i = 0; i < letters; i++){
        currentChar = 'a' + i;
        currentCountCode = countChar(code, currentChar);
        currentCountGuess = countChar(guess, currentChar);

        // guess < code => n guess is right
        if (currentCountCode >= currentCountGuess){
            totalCharactersRight += currentCountGuess;
        }
        // guess > code => n code is right
        else totalCharactersRight += currentCountCode;
    }

    return totalCharactersRight;

}




void playMastermind(int tries){

    constexpr int size = 4;
    constexpr int letters = 6;

    string code;
    string guess;

    bool running = 1;
    int iterations = 0;
    char maxChar = 'a' + (letters - 1);

    int rightPos = 0;
    int rightCharWrongPos = 0;


    code = randomizeString(size, 'a', maxChar);
    cout << code << endl;

    while (running){
        guess = readInputToString('a', maxChar, size);
        cout << endl;

        rightCharWrongPos = checkCharacter(guess, code, letters);
        cout << "Right characters: " << rightCharWrongPos << endl;

        rightPos = checkCharacterAndPosition(guess, code, size);
        cout << "Right characters on right position : "<< rightPos << endl;

        // if rightPos == size you win 
        if (rightPos == size) {
            cout << "you won!" << endl;
            running = 0; 
            break;
        }
        else if (iterations >= tries){
            cout << "times up, you lose" << endl;
            running = 0;
            break;
        }
        iterations++;
    }

}