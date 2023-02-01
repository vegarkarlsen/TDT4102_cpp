#include "masterVisual.h"
#include "std_lib_facilities.h"
#include "utilities.h"

std::map<int, Color> colorConverter{
    {1, Color::red},
    {2, Color::green},
    {3, Color::yellow},
    {4, Color::blue},
    {5, Color::blue_violet},
    {6, Color::dark_cyan}
};

void addGuess(MastermindWindow &mwin, const std::string code, const char startLetter)
{
	// definer addGuess
}

void addFeedback(MastermindWindow &mwin, const int correctPosition, const int correctCharacter)
{
	// definer addFeedback
}

void MastermindWindow::drawCodeHider()
{
	if(code_hidden) {
		draw_rectangle(Point{padX, 3 * padY}, winW - size * padX, padY, Color::black);
	}
}

MastermindWindow::MastermindWindow(int x, int y, int w, int h, int size, const std::string &title) 
: AnimationWindow(x, y, w, h, title),
guessBtn{{upperLeftCornerBtn.x, upperLeftCornerBtn.y}, btnW, btnH, "Add"},
guess{{upperLeftCornerInBox.x, upperLeftCornerInBox.y}, inBoxW, inBoxH, ""},
size(size)
{
	add(guess);
	add(guessBtn);
	guessBtn.setCallback(std::bind(&MastermindWindow::newGuess, this));
};

string MastermindWindow::wait_for_guess()
{
	while (!button_pressed && !should_close())
	{
		for(int guessIndex = 0; guessIndex < static_cast<int>(guesses.size()); guessIndex++) {
			//Implementer gjett slik at det vises fargede rektangler i grafikkvinduet
			{
                // Tegn rektangler ved bruk av draw_rectangle(). Bruk: colorConverter.at() for å få riktig farge

			}
		}

		for(int feedbackIndex = 0; feedbackIndex < static_cast<int>(feedbacks.size()); feedbackIndex++) {
			// Implementer feedback

			for (int i = 0; i < size; i++)
			{
				// Tegn sirkler ved hjelp av draw_circle
				
			}
		}

		// Burde tegnes sist siden den skal ligge på toppen
		drawCodeHider();

		next_frame();
	}
	button_pressed = false;

	string newGuess = guess.getText();
	guess.setText("");
	
	return newGuess;
}

string MastermindWindow::getInput(unsigned int n, char lower, char upper)
{
	bool validInput = false;
	string guess;
	while (!validInput && !should_close())
	{
		guess.clear();
		string input = wait_for_guess();
		if (input.size() == n)
		{
			for (unsigned int i = 0; i < n; i++)
			{
				char ch = input.at(i);
				if (isalpha(ch) && toupper(ch) <= upper && lower <= toupper(ch))
				{
					guess += toupper(ch);
				}
				else
					break;
			}
		}
		if (guess.size() == n)
		{
			validInput = true;
		}
		else
		{
			cout << "Invalid input guess again" << endl;
		}
	}
	return guess;
}

void MastermindWindow::setCodeHidden(bool hidden) {
	code_hidden = hidden;
}


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

void playMastermindVisual(int tries){


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
    cout << code << endl; // for easier debuging

    MastermindWindow mwin{800, 20, winW, winH, size, "Mastermind"};

    while (running){
        guess =  mwin.getInput(size, 'a', maxChar);
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

