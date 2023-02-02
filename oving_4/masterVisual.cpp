#include "masterVisual.h"
#include "std_lib_facilities.h"
#include "mastermind.h"

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
    Guess g{code, startLetter};
	mwin.guesses.push_back(g);
}

void addFeedback(MastermindWindow &mwin, const int correctPosition, const int correctCharacter)
{
	// definer addFeedback
    Feedback f{correctPosition, correctCharacter};
    mwin.feedbacks.push_back(f);
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

    int roundNr = static_cast<int>(guesses.size());
    // int roundNr = 1;

    // pos y is based on round nr (the size of guesses gives roundnr)
    // int yPos = padY + (padY * roundNr);
    // startvariables:
    int yPos = 4 * padY; 
    int xPos = padX;
    
    string currentGuess;
    int colorIndex;

	while (!button_pressed && !should_close())
	{
		for(int guessIndex = 0; guessIndex < roundNr; guessIndex++) {
			//Implementer gjett slik at det vises fargede rektangler i grafikkvinduet
			{
                // Tegn rektangler ved bruk av draw_rectangle(). Bruk: colorConverter.at() for å få riktig farge

                currentGuess = guesses.at(guessIndex).code;
                // cout << "guess from drawing nr " << guessIndex << " " << currentGuess << endl;
                
                // position y TODO: change size between rows
                yPos = padY*2 + (padY * guessIndex  * 2);

                // draw trough x-direction for each guessIndex
                int xRectNr = static_cast<int>(currentGuess.length());
                for (int i = 0; i < xRectNr; i++){
                    
                    // (startChar + 1) - currentChar 
                    colorIndex = static_cast<int>(currentGuess.at(i) - 'a' + 1);

                    // position x TODO: change size between columns
                    xPos = (padX * i * 2) + 10;

                    // cout << "drawing " 
                    //     << "(x,y): " << xPos << ", " << yPos 
                    //     << " colorIndex: " << colorIndex << endl;

                    draw_rectangle(Point{xPos, yPos}, padX, padY, colorConverter.at(colorIndex));

                }
				
			}
		}
        int circleX = (padX * 4 * 2) + 10;
        int circleY = padY*2;
		for(int feedbackIndex = 0; feedbackIndex < static_cast<int>(feedbacks.size()); feedbackIndex++) {
			// Implementer feedback
            // svart: korrekt bosktav med korrekt posisjon
            // hvit: korrekt bokstav uavhengig av pos

            int rightPos = feedbacks.at(feedbackIndex).correctPosition;

            // - rightPos because this has higher priority
            int rightCharacter = feedbacks.at(feedbackIndex).correctCharacter - rightPos;

            //increment ypos
            circleY = padY*2 + padY/2 + (padY * feedbackIndex  * 2);
            int startCircleX = ((padX * 4 * 2 - padX/2));

            // black
			for (int i = 0; i < rightPos; i++)
			{
				// Tegn sirkler ved hjelp av draw_circle
                // draw_circle(Point{circleX, circleY}, radius, color, colorBorder);
                circleX = startCircleX + i*(radCircle+10);

                draw_circle(Point{circleX, circleY}, radCircle, Color::black, Color::black);

			}
            // white
            for (int i = 0; i < rightCharacter; i++){

                circleX = startCircleX + (i + rightPos)*(radCircle+10);
                
                draw_circle(Point{circleX, circleY}, radCircle, Color::white, Color::black);
            }

		}

		// Burde tegnes sist siden den skal ligge på toppen
		// drawCodeHider();

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
        // cout << "input to check: " << input << endl;
		if (input.size() == n)
		{
			for (unsigned int i = 0; i < n; i++)
			{
				char ch = input.at(i);
                // debug
                // cout << "checing char: " << ch << endl;
                // cout << "isalpha: " << isalpha(ch) << endl;
                // cout << "<= upper: " << (toupper(ch) <= toupper(upper)) << endl;
                // cout << ">= lower: " << (toupper(lower) <= toupper(ch)) << endl;

				if (isalpha(ch) && toupper(ch) <= toupper(upper) && toupper(lower) <= toupper(ch))
				{
					guess += tolower(ch);
                    // cout << "is good" << endl;
                    continue;
				}
				else{
                    // cout << "failed!" << endl;
					break;
                }
                    
			}
		}
		if (guess.size() == n)
		{
			validInput = true;
            // cout << "input got through test, and is valid" << endl;
		}
		else
		{
            // cout << "guess.size(): " << guess.size() << endl;
			cout << "Invalid input guess again" << endl;
		}
	}
	return guess;
}

void MastermindWindow::setCodeHidden(bool hidden) {
	code_hidden = hidden;
}


// Oppgave 5
//----------------------------------------------------------------


void playMastermindViusal(const int rounds){


    constexpr int size = 4;
    constexpr int letters = 6;

    string code;
    string guess;

    bool victory = 0;
    char startChar = 'a';
    char maxChar = startChar + (letters - 1);

    int rightPos = 0;
    int rightCharWrongPos = 0;

    code = randomizeString(size, startChar, maxChar);
    cout << "The code is: "<< code << endl;

	MastermindWindow mwin{800, 40, winW, winH, size, "Mastermind"};

    for (int i = 0; i < rounds + 1; i++){
        
        guess = mwin.getInput(size, startChar, maxChar);
        // cout << "guess from main: " << guess << endl;
        addGuess(mwin, guess, startChar);

        rightCharWrongPos = checkCharacter(guess, code, letters);
        rightPos = checkCharacterAndPosition(guess, code, size);

        // cout << "Right characters: " << rightCharWrongPos << endl;
        // cout << "Right characters on right position : "<< rightPos << endl;

        addFeedback(mwin, rightPos, rightCharWrongPos);

        // if rightPos == size you win 
        if (rightPos == size) {
            cout << "you won!" << endl;
            victory = 1; 
            break;
        }

        // // debug, printing guesses vector.
        // cout << "stored guesses: " << endl;
        // for (int i = 0; i < static_cast<int>(mwin.guesses.size()); i++){
        //     cout << mwin.guesses.at(i).code << endl;
        // }



    }
    if (!victory) cout << "you lose!" << endl;

}



